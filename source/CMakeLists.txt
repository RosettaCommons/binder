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

if (LLVM_VERSION_MAJOR GREATER_EQUAL 4 AND LLVM_VERSION_MAJOR LESS 8 )
target_link_libraries(binder
  PRIVATE
  LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}
  clangTooling
  clangBasic
  clangASTMatchers
  clangAST
  clangFrontend  
  )
endif()
if (LLVM_VERSION_MAJOR GREATER_EQUAL 8 AND LLVM_VERSION_MAJOR LESS 10 )
target_link_libraries(binder
  PRIVATE
  LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}
  clangTooling
  clangBasic
  clangASTMatchers
  clangAST
  clangFrontend
  clangSerialization
  )
endif()

if (LLVM_VERSION_MAJOR GREATER_EQUAL 10 )
target_link_libraries(binder
  PRIVATE
  LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}
  clang
  clang-cpp
  )
endif()

if (LLVM_VERSION_MAJOR LESS 4  )
target_link_libraries(binder PRIVATE
-Wl,--start-group  
clang 
LLVM-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}    
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
-Wl,--end-group  )
endif()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/binder 
PERMISSIONS WORLD_EXECUTE WORLD_READ OWNER_WRITE OWNER_READ OWNER_EXECUTE 
DESTINATION ${CMAKE_INSTALL_BINDIR})
