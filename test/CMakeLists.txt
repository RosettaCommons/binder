macro( binder_test testname vers)
message( STATUS "binder test: building ${testname} for ${testname}" )
string(REPLACE "." "_" testnamenodot ${testname})
ADD_CUSTOM_command(    
#COMMAND binder --bind ""  --root-module ${testnamenodot} --prefix ${CMAKE_CURRENT_SOURCE_DIR}  --single-file ${testname}.hpp  -- -std=c++11 -I${CMAKE_CURRENT_SOURCE_DIR} -isystem /usr/include/c++/4.8.2/x86_64-redhat-linux  -I/usr/lib/clang/3.4.2/include
COMMAND  cp  ${testname}.ref ${testname}.cpp
OUTPUT ${testname}.cpp
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
VERBATIM)
if (${vers} STREQUAL 2)
Python_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${testname}.cpp)
endif()
if (${vers} STREQUAL 3)
Python3_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${testname}.cpp )
endif()
set_target_properties(${testnamenodot}${vers} PROPERTIES OUTPUT_NAME  ${testnamenodot}
                                               ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:> 
                                               LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>
                                               RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
target_include_directories( ${testnamenodot}${vers} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_test( NAME ${testname}_python${vers} 
COMMAND ${Python_EXECUTABLE} -c "import ${testnamenodot}"
WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
SET_TESTS_PROPERTIES(${testname}_python${vers} PROPERTIES DEPENDS ${testnamenodot}${vers})
endmacro( binder_test  vers)
set( CMAKE_INCLUDE_DIRECTORIES_BEFORE ON )
set( binder_tests
        T00.basic
        T01.enum
        T02.function
        T05.default
         )
set (TEMPVERSIONS 2 3 )
foreach( pver ${TEMPVERSIONS} )
         
if (${pver} STREQUAL 2)
find_package (Python ${pver} COMPONENTS  Development Interpreter REQUIRED)
endif()
if (${pver} STREQUAL 3)
find_package (Python3 ${pver} COMPONENTS  Development Interpreter  REQUIRED)
if (Python3_VERSION AND Python3_LIBRARIES AND Python3_INCLUDE_DIRS AND Python3_EXECUTABLE  ) #something is set
SET( Python_VERSION ${Python3_VERSION})
SET( Python_VERSION_MAJOR ${Python3_VERSION_MAJOR})
SET( Python_VERSION_MINOR ${Python3_VERSION_MINOR})
SET( Python_LIBRARIES ${Python3_LIBRARIES})
SET( Python_SITEARCH ${Python3_SITEARCH})
SET( Python_EXECUTABLE ${Python3_EXECUTABLE})
SET( Python_INCLUDE_DIRS ${Python3_INCLUDE_DIRS})
endif()
endif()             
foreach ( test ${binder_tests} )
  binder_test( ${test} ${pver})
endforeach ( test ${binder_tests} )
endforeach( pver ${TEMPVERSIONS} )