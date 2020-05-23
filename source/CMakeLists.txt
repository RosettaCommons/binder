
#list(REMOVE_ITEM CMAKE_CXX_FLAGS "-fno-exceptions")
#set(CMAKE_CXX_FLAGS "-fexceptions ${CMAKE_CXX_FLAGS}")

set(LLVM_LINK_COMPONENTS support)
set(LLVM_USED_LIBS clangTooling clangBasic clangAST)

add_clang_executable(binder
  binder.cpp
  binder.hpp

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

  type.hpp
  type.cpp

  util.hpp
  util.cpp

  fmt/format.cc
  fmt/posix.cc
  )
if(USE_EXTERNAL_LLVM)
find_library(LLVMSO  NAMES LLVM 
                           LLVM-${LLVM_VERSION_MAJOR} 
                           LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR} 
                           LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}
                           PATHS  ${LLVM_LIBRARY_DIR}  ${LLVMLIBDIR}
                           )
add_definitions(${LLVM_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_COMPILE_FLAGS}")
list(REMOVE_ITEM CMAKE_CXX_FLAGS "-fno-exceptions")
string (REPLACE "-fno-exceptions" ""     CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
message(STATUS "binder: LLVMSO=${LLVMSO}")
message(STATUS "binder: CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
if (LLVM_VERSION_MAJOR LESS 7  )
target_link_libraries(binder PRIVATE
-Wl,--start-group
${LLVMSO}
clang
clangAnalysis 
clangARCMigrate
clangAST
clangASTMatchers
clangBasic 
clangCodeGen
clangDriver
clangDynamicASTMatchers
clangEdit 
clangFormat 
clangFrontend
clangFrontendTool
clangLex 
clangParse
clangRewriteFrontend
clangSema
clangSerialization
clangTooling
-Wl,--end-group
)
endif()
if (LLVM_VERSION_MAJOR EQUAL 7)
target_link_libraries(binder
  PRIVATE
  ${LLVMSO}
  clangTooling
  clangBasic
  clangASTMatchers
  clangAST
  clangFrontend  
  )
endif()
if (LLVM_VERSION_MAJOR EQUAL 8 OR LLVM_VERSION_MAJOR EQUAL 9 )
target_link_libraries(binder
  PRIVATE
  ${LLVMSO}
  clangTooling
  clangBasic
  clangASTMatchers
  clangAST
  clangFrontend
  clangSerialization
  )
endif()

if (LLVM_VERSION_MAJOR EQUAL 10 OR LLVM_VERSION_MAJOR GREATER 10 )
target_link_libraries(binder
  PRIVATE
  ${LLVMSO}
  clang
  clang-cpp
  )
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
endif()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/binder 
PERMISSIONS WORLD_EXECUTE WORLD_READ OWNER_WRITE OWNER_READ OWNER_EXECUTE 
DESTINATION ${CMAKE_INSTALL_BINDIR})
