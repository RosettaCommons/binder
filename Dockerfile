FROM ubuntu:20.04 as base

# Build Args
ARG CLANG_VERSION=14

# Dependencies
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
 && apt-get install -yq wget gnupg \
 && rm -rf /var/lib/apt/lists/*

# Get LLVM install script
ENV CLANG_VERSION="${CLANG_VERSION}"
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN echo "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-${CLANG_VERSION} main" >> /etc/apt/sources.list

# Clang
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
 && apt-get install -yq "clang-${CLANG_VERSION}" \
 && rm -rf /var/lib/apt/lists/*


# Build binder
FROM base as build

# Build deps
RUN apt-get update
RUN apt-get install -yq \
	"libclang-${CLANG_VERSION}-dev" \
	cmake \
	git

# Grab binder source
RUN git clone "https://github.com/RosettaCommons/binder.git" /binder

# Build
WORKDIR "/build"
RUN cmake \
	-DCMAKE_CXX_COMPILER="$(which clang++-"${CLANG_VERSION}")" \
	-DBINDER_ENABLE_TEST=OFF \
	/binder
RUN make "-j$(nproc)"
RUN make install


# Install image
FROM base as install
COPY --from=build /usr/local/bin/binder /usr/local/bin/binder
