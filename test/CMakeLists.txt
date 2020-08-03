find_package(pybind11 CONFIG REQUIRED)
message(STATUS "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIRS}   and ${pybind11_INCLUDE_DIR}")

macro( binder_src stestname)
message( STATUS "binder test: building ${stestname} for ${stestname}" )
string(REPLACE "." "_" stestnamenodot ${stestname})
if (BINDER_MOCK_TEST)
ADD_CUSTOM_TARGET(${stestnamenodot}.cpp
COMMAND  cp  ${stestname}.ref ${stestnamenodot}.cpp
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
VERBATIM)
else()
ADD_CUSTOM_TARGET(${stestnamenodot}.cpp
COMMAND touch ${stestname}.config
COMMAND echo "#include <${stestname}.hpp>" > ${stestname}.hpp.include
COMMAND ${CMAKE_BINARY_DIR}/source/binder --bind ""  --root-module ${stestnamenodot} --prefix ${CMAKE_CURRENT_SOURCE_DIR}/ --config ${stestname}.config --single-file  --annotate-includes  ${stestname}.hpp.include  
-- -x c++ -std=c++11   -I . -I ${CMAKE_CURRENT_SOURCE_DIR}  -isystem /  -I ${CLANG_INCLUDE_DIRS}   -iwithsysroot${LibClang_INCLUDE_DIR}
#The last one is for the crazy old clang
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
VERBATIM)
endif()
endmacro( binder_src  stestname)

macro( binder_test testname vers)
string(REPLACE "." "_" testnamenodot ${testname})
string(REPLACE "." ";" MAJMIN "${vers}.X.Y")
list(GET MAJMIN 0 MAJ)
list(GET MAJMIN 1 MIN)
if (${MAJ} STREQUAL 0 )
add_executable( ${testname}_diffbinder diffbinder.cpp) 
add_dependencies( ${testname}_diffbinder ${testnamenodot}.cpp)
add_test( NAME ${testname}_diff
COMMAND ${testname}_diffbinder ${testnamenodot}.cpp ${testname}.ref
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
SET_TESTS_PROPERTIES(${testname}_diff PROPERTIES DEPENDS  binder)
SET_TESTS_PROPERTIES(${testname}_diff PROPERTIES DEPENDS  ${testname}_foo )
else()
if (${MAJ} STREQUAL 2)
Python_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${testnamenodot}.cpp)
endif()
if (${MAJ} STREQUAL 3)
Python3_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${testnamenodot}.cpp)
endif()
set_source_files_properties( ${testnamenodot}.cpp PROPERTIES GENERATED TRUE)
add_dependencies(${testnamenodot}${vers}  ${testnamenodot}.cpp)
#target_link_libraries(${testnamenodot}${vers} PRIVATE pybind11::module)
set_target_properties(${testnamenodot}${vers} PROPERTIES OUTPUT_NAME  ${testnamenodot}
                                               NO_SYSTEM_FROM_IMPORTED ON
                                               ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:> 
                                               LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>
                                               RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
target_compile_definitions(${testnamenodot}${vers} PRIVATE ${testnamenodot}_EXPORTS )
target_include_directories( ${testnamenodot}${vers} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}  ${pybind11_INCLUDE_DIR})

if(BINDER_USE_PYTHON_IN_TEST)
add_test( NAME ${testname}_python${vers} 
COMMAND ${Python_EXECUTABLE} -c "import ${testnamenodot}"
WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
else()
add_test( NAME ${testname}_python${vers} 
COMMAND echo "Import for ${testnamenodot} is disabled"
WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/py${vers}/${CMAKE_INSTALL_LIBDIR}/$<0:>)
endif()

SET_TESTS_PROPERTIES(${testname}_python${vers} PROPERTIES DEPENDS ${testnamenodot}${vers})
endif()

endmacro( binder_test testname vers)
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
         #fail T17.anonymous
         #T20.template
         #T30.include
         #T31.include_for_class
         T32.call_guard
         #T40.stl
         #fails T42.stl.names
         #T50.namespace_binder
         )

string(REPLACE "," ";" TESTVERSIONS ${BINDER_TEST_PYTHON_VERSIONS})
foreach ( tests ${binder_tests} )
  binder_src( ${tests})
endforeach ( tests ${binder_tests} )

foreach( pver ${TESTVERSIONS} )         

string(REPLACE "." ";" MAJMIN "${pver}.X.Y")
list(GET MAJMIN 0 MAJ)
list(GET MAJMIN 1 MIN)
set(PYFOUND FALSE)
if (${MAJ} STREQUAL 0)
set(PYFOUND TRUE)
SET( Python_VERSION "0")
endif()
if (${MAJ} STREQUAL 2)
find_package (Python ${pver} COMPONENTS  Development Interpreter)
if (Python_FOUND AND (pybind11_VERSION_MAJOR GREATER_EQUAL 2) AND (pybind11_VERSION_MINOR GREATER_EQUAL 2) )
set(PYFOUND TRUE)
endif()
endif()

if (${MAJ} STREQUAL 3)
find_package (Python3 ${pver} COMPONENTS  Development Interpreter)
if (Python3_FOUND AND (pybind11_VERSION_MAJOR GREATER_EQUAL 2) AND (pybind11_VERSION_MINOR GREATER_EQUAL 2) )
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

if (PYFOUND )             
foreach ( xtest ${binder_tests} )
  binder_test( ${xtest} ${Python_VERSION})
endforeach ( xtest ${binder_tests} )
endif()
endforeach( pver ${TEMPVERSIONS} )
