find_package(pybind11 CONFIG REQUIRED)
message(STATUS "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIRS}   and ${pybind11_INCLUDE_DIR}")
macro( binder_test testname vers)
message( STATUS "binder test: building ${testname} for ${testname}" )
string(REPLACE "." "_" testnamenodot ${testname})
if (BINDER_MOCK_TEST)
ADD_CUSTOM_command(    
COMMAND  cp  ${testname}.ref ${testnamenodot}.cpp
OUTPUT ${testnamenodot}.cpp
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
VERBATIM)
else()
ADD_CUSTOM_command(    
COMMAND echo "#include <${testname}.hpp>" > ${testname}.hpp.include
COMMAND binder --bind ""  --root-module ${testnamenodot} --prefix ${CMAKE_CURRENT_SOURCE_DIR}/  --single-file  --annotate-includes  ${testname}.hpp.include  
-- -x c++ -std=c++11   -I . -I ${CMAKE_CURRENT_SOURCE_DIR}
-isystem /
-I ${LibClang_INCLUDE_DIRS}
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
target_link_libraries(${testnamenodot}${vers} PRIVATE pybind11::module)

set_target_properties(${testnamenodot}${vers} PROPERTIES OUTPUT_NAME  ${testnamenodot}
                                               NO_SYSTEM_FROM_IMPORTED ON
                                               ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:> 
                                               LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>
                                               RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
target_compile_definitions(${testnamenodot}${vers} PRIVATE ${testnamenodot}_EXPORTS )
target_include_directories( ${testnamenodot}${vers} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}  ${pybind11_INCLUDE_DIR})
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