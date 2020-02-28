macro( binder_test testname vers)


message( STATUS "binder test: building ${testname} for ${testname}" )
string(REPLACE "." "_" testnamenodot ${testname})
if (BINDER_MOCK_TEST)
ADD_CUSTOM_command(    
#COMMAND binder --bind ""  --root-module ${testnamenodot} --prefix ${CMAKE_CURRENT_SOURCE_DIR}  --single-file ${testname}.hpp  -- -std=c++11 -I${CMAKE_CURRENT_SOURCE_DIR} -isystem /usr/include/c++/4.8.2/x86_64-redhat-linux  -I/usr/lib/clang/3.4.2/include
COMMAND  cp  ${testname}.ref ${testnamenodot}.cpp
OUTPUT ${testnamenodot}.cpp
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
VERBATIM)
else()
ADD_CUSTOM_command(    
COMMAND echo "#include <${testname}.hpp>" > ${testname}.hpp.include
COMMAND binder --bind ""  --root-module ${testnamenodot} --prefix ${CMAKE_CURRENT_SOURCE_DIR}/  --single-file  --annotate-includes  ${testname}.hpp.include  -- -x c++ -std=c++11   -I . -I ${CMAKE_CURRENT_SOURCE_DIR}
 -isystem /usr/include/c++/10/x86_64-redhat-linux 
  -I/usr/lib/clang/3.4.2/include
-I/usr/lib64/clang/10.0.0/include
#COMMAND  cp  ${testname}.ref ${testname}.cpp
OUTPUT ${testnamenodot}.cpp
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
VERBATIM)
endif()

if (${vers} STREQUAL 0 )
add_test( NAME ${testname}_diff
COMMAND diff ${testnamenodot}.cpp ${testname}.ref
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
else()
if (${vers} STREQUAL 2)
Python_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${testnamenodot}.cpp)
endif()
if (${vers} STREQUAL 3)
Python3_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${testnamenodot}.cpp )
endif()
set_target_properties(${testnamenodot}${vers} PROPERTIES OUTPUT_NAME  ${testnamenodot}
                                               ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:> 
                                               LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>
                                               RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
#-DT15_inner_class3_EXPORTS
#-DT15_inner_class3_EXPORTS
target_compile_definitions(${testnamenodot}${vers} PRIVATE ${testnamenodot}_EXPORTS )
target_include_directories( ${testnamenodot}${vers} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_test( NAME ${testname}_python${vers} 
COMMAND ${Python_EXECUTABLE} -c "import ${testnamenodot}"
WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
SET_TESTS_PROPERTIES(${testname}_python${vers} PROPERTIES DEPENDS ${testnamenodot}${vers})
endif()
endmacro( binder_test  vers)
set( CMAKE_INCLUDE_DIRECTORIES_BEFORE ON )
set( binder_tests
        T00.basic
        T01.enum
        T02.function
        T05.default
        T07.class
         T08.constructor
         T09.overload
         T10.inheritance
         T11.override
         T12.operator
         T15.copy
         T15.inner_class
         )
#0 means only diff         
set (TEMPVERSIONS  2 3 )
foreach( pver ${TEMPVERSIONS} )         
set(PYFOUND FALSE)
if (${pver} STREQUAL 0)
set(PYFOUND TRUE)
endif()
if (${pver} STREQUAL 2)
find_package (Python ${pver} COMPONENTS  Development Interpreter)
if (Python_FOUND)
set(PYFOUND TRUE)
endif()


endif()
if (${pver} STREQUAL 3)
find_package (Python3 ${pver} COMPONENTS  Development Interpreter)
if (Python3_FOUND)
set(PYFOUND TRUE)
endif()
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
if (PYFOUND)             
foreach ( test ${binder_tests} )
  binder_test( ${test} ${pver})
endforeach ( test ${binder_tests} )
endif()
endforeach( pver ${TEMPVERSIONS} )