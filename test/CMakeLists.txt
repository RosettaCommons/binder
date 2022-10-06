if("0" STREQUAL ${BINDER_TEST_PYTHON_VERSIONS})
  message(STATUS "binder: Only comparisons of produced outputs to the reference outputs will be performed.")
else()
  find_package(pybind11 CONFIG REQUIRED)
  message(STATUS "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIRS}   and ${pybind11_INCLUDE_DIR}")
endif()

macro( binder_src stestname)
string(REPLACE "." "_" stestnamenodot ${stestname})
message( STATUS "binder test: building ${stestnamenodot}.cpp for ${stestname}" )
if (BINDER_MOCK_TEST)
  file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${stestnamenodot}.cpp INPUT ${CMAKE_CURRENT_SOURCE_DIR}/${stestname}.ref )
else()
  make_directory(${CMAKE_CURRENT_BINARY_DIR}/test)
  SET(${stestname}_config_flag "")
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${stestname}.config")
    SET(${stestname}_config_flag --config ${stestname}.config )
  endif()
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${stestname}.cli")
    FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${stestname}.cli" ${stestname}_cli_flags)
  endif()
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${stestname}.hpp.include "#include <${stestname}.hpp>" )
  if(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    ADD_CUSTOM_TARGET(target${stestnamenodot}cpp
    #The first two expressions below are for older clang
    COMMAND C_INCLUDE_PATH=${LibClang_INCLUDE_DIR}:/Library/Developer/CommandLineTools/usr/include/c++/v1/  CPLUS_INCLUDE_PATH=${LibClang_INCLUDE_DIR}:/Library/Developer/CommandLineTools/usr/include/c++/v1/
      ${CMAKE_BINARY_DIR}/source/binder --bind ""  -max-file-size=100000
      --root-module ${stestnamenodot} --prefix ${CMAKE_CURRENT_BINARY_DIR}/ ${${stestname}_config_flag} --single-file  --annotate-includes  ${CMAKE_CURRENT_BINARY_DIR}/${stestname}.hpp.include ${${stestname}_cli_flags}
      -- -x c++ -std=c++11   -I . -I ${CMAKE_CURRENT_SOURCE_DIR}  -isystem /  -I ${CLANG_INCLUDE_DIRS}   -iwithsysroot${LibClang_INCLUDE_DIR}
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" VERBATIM)
  else()
    ADD_CUSTOM_TARGET(target${stestnamenodot}cpp
    #The first two expressions below are for older clang
    COMMAND C_INCLUDE_PATH=${LibClang_INCLUDE_DIR}   CPLUS_INCLUDE_PATH=${LibClang_INCLUDE_DIR}  ${CMAKE_BINARY_DIR}/source/binder --bind ""  -max-file-size=100000
      --root-module ${stestnamenodot} --prefix ${CMAKE_CURRENT_BINARY_DIR}/ ${${stestname}_config_flag} --single-file  --annotate-includes  ${CMAKE_CURRENT_BINARY_DIR}/${stestname}.hpp.include ${${stestname}_cli_flags}
      -- -x c++ -std=c++11   -I . -I ${CMAKE_CURRENT_SOURCE_DIR}  -isystem /  -I ${CLANG_INCLUDE_DIRS}   -iwithsysroot${LibClang_INCLUDE_DIR}
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" VERBATIM)
  endif()
endif()
endmacro( binder_src  stestname)

macro( binder_test testname vers)
  string(REPLACE "." "_" testnamenodot ${testname})
  string(REPLACE "." ";" MAJMIN "${vers}.X.Y")
  list(GET MAJMIN 0 MAJ)
  list(GET MAJMIN 1 MIN)
  if (${MAJ} STREQUAL 0 )
    if (NOT TARGET diffbinder)
      add_executable( diffbinder diffbinder.cpp)
    endif()
    add_test( NAME ${testname}_diff
#--always-success option forces the diffbinder to return success regardles of the results of comparison.
      COMMAND diffbinder  ${CMAKE_CURRENT_BINARY_DIR}/${testnamenodot}.cpp ${CMAKE_CURRENT_SOURCE_DIR}/${testname}.ref --always-success
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
    set_source_files_properties( ${CMAKE_CURRENT_BINARY_DIR}/${testnamenodot}.cpp PROPERTIES GENERATED TRUE)
    add_dependencies( diffbinder target${testnamenodot}cpp)
  else()
    if (${MAJ} STREQUAL 2)
      Python_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${CMAKE_CURRENT_BINARY_DIR}/${testnamenodot}.cpp)
    endif()
    if (${MAJ} STREQUAL 3)
      Python3_add_library(${testnamenodot}${vers} MODULE  ${testname}.hpp  ${CMAKE_CURRENT_BINARY_DIR}/${testnamenodot}.cpp)
    endif()
    set_source_files_properties( ${CMAKE_CURRENT_BINARY_DIR}/${testnamenodot}.cpp PROPERTIES GENERATED TRUE)
    add_dependencies(${testnamenodot}${vers}  target${testnamenodot}cpp)
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
         T15.inner_class.fwd
         T17.anonymous
         T20.template
         T30.include
         T31.include_for_class
         T32.call_guard
         T33.buffer_protocol
         T40.stl
         T42.stl.names
         T42.stl.names.map
         T42.stl.names.set
         T42.stl.names.multimap
         T42.stl.names.multiset
         T43.stl.pybind11_include_stl
         T50.namespace_binder
         )
if (pybind11_VERSION VERSION_LESS 2.5.99)
 message(STATUS "pybind11 version ${pybind11_VERSION} is less than 2.5.99. Some tests will be disabled." )
 list(REMOVE_ITEM binder_tests T09.overload)
 list(REMOVE_ITEM binder_tests T10.inheritance)
 list(REMOVE_ITEM binder_tests T11.override)
 list(REMOVE_ITEM binder_tests T15.inner_class)
endif()
if( CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin" )
 list(REMOVE_ITEM binder_tests T42.stl.names.multimap)
 list(REMOVE_ITEM binder_tests T42.stl.names.multiset)
 list(REMOVE_ITEM binder_tests T42.stl.names.set)
 list(REMOVE_ITEM binder_tests T42.stl.names.map)
 list(REMOVE_ITEM binder_tests T42.stl.names)
 list(REMOVE_ITEM binder_tests T40.stl)
 list(REMOVE_ITEM binder_tests T11.override)
 list(REMOVE_ITEM binder_tests T10.inheritance)
 list(REMOVE_ITEM binder_tests T02.function)
endif()
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
