
#list(REMOVE_ITEM CMAKE_CXX_FLAGS "-fno-exceptions")
#set(CMAKE_CXX_FLAGS "-fexceptions ${CMAKE_CXX_FLAGS}")

set(LLVM_LINK_COMPONENTS support)
set(LLVM_USED_LIBS clangTooling clangBasic clangAST)

add_clang_executable(binder
  main.cpp

  binder.hpp
  binder.cpp

  context.hpp
  context.cpp

  class.hpp
  class.cpp

  config.hpp
  config.cpp

  enum.hpp
  enum.cpp

  function.hpp
  function.cpp

  options.hpp
  options.cpp

  type.hpp
  type.cpp

  util.hpp
  util.cpp

  fmt/format.cc
  fmt/format.h
  fmt/os.cc
  fmt/os.h
  )
if (NOT VERSION)
  set(VERSION 1.4.1)
endif()  
target_compile_definitions(binder PUBLIC BINDER_VERSION_STRING=\"${VERSION}\")
if(USE_EXTERNAL_LLVM)
  if(STATIC)
    find_library(lib_llvm_path NAMES libclang_static_bundled.a
                               PATHS ${LLVM_LIBRARY_DIR}
                               REQUIRED
                               )
  else()
    if(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
      set(lib_llvm_path )
    else()
      find_library(lib_llvm_path NAMES LLVM
                               LLVM-${LLVM_VERSION_MAJOR}
                               LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}
                               LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}
                               PATHS  ${LLVM_LIBRARY_DIR}  ${LLVMLIBDIR}
                               REQUIRED
                               )
     endif()
  endif()
  add_definitions(${LLVM_DEFINITIONS})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_COMPILE_FLAGS}")
  list(REMOVE_ITEM CMAKE_CXX_FLAGS "-fno-exceptions")
  string (REPLACE "-fno-exceptions" ""     CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
  message(STATUS "binder: lib_llvm_path=${lib_llvm_path}")
  message(STATUS "binder: CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
  if ( (LLVM_VERSION_MAJOR GREATER 3)  AND (LLVM_VERSION_MAJOR LESS 8) )
    target_link_libraries(binder
      PRIVATE
      ${lib_llvm_path}
      clangAST
      clangBasic
      clangFrontend
      clangTooling
      )
  endif()
  if ( (LLVM_VERSION_MAJOR EQUAL 8) OR (LLVM_VERSION_MAJOR EQUAL 9) )
    target_link_libraries(binder
      PRIVATE
      ${lib_llvm_path}
      clangTooling
      clangBasic
      clangAST
      clangFrontend
      clangSerialization
      )
  endif()
  if ( (LLVM_VERSION_MAJOR EQUAL 10) OR (LLVM_VERSION_MAJOR GREATER 10) )
    if(STATIC)
      # As of 11-08-2020, libclang-static-build [1] only supports LLVM version 10.
      #
      # [1]: https://github.com/deech/libclang-static-build
      target_link_libraries(binder
        PRIVATE
        ${lib_llvm_path}
        "-static"
        # This causes the strong "__pthread_*" symbols from libpthread to be
        # used instead of the *weak* "__pthread_*" symbols defined in libc.
        # https://stackoverflow.com/a/45271521
        "-Wl,--whole-archive -lpthread -Wl,--no-whole-archive"
        )
    else()
      target_link_libraries(binder
        PRIVATE
        ${lib_llvm_path}
        clang
        clang-cpp
        )
    endif()
  endif()
else()
  target_link_libraries(binder
    PRIVATE
    clangTooling
    clangBasic
    clangASTMatchers
    clangAST
    clangFrontend
    )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_COMPILE_FLAGS}")
  list(REMOVE_ITEM CMAKE_CXX_FLAGS "-fno-exceptions")
  string (REPLACE "-fno-exceptions" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
  message(STATUS "binder: CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
endif()
install(TARGETS binder
PERMISSIONS WORLD_EXECUTE WORLD_READ OWNER_WRITE OWNER_READ OWNER_EXECUTE
DESTINATION binder/bin COMPONENT binder)
