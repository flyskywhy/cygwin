MESSAGE(STATUS "Loaded CMakeASM${ASM_DIALECT}Information - ASM${ASM_DIALECT} support is still experimental, please report issues")

IF(UNIX)
  SET(CMAKE_ASM${ASM_DIALECT}_OUTPUT_EXTENSION .o)
ELSE(UNIX)
  SET(CMAKE_ASM${ASM_DIALECT}_OUTPUT_EXTENSION .obj)
ENDIF(UNIX)

SET(CMAKE_INCLUDE_FLAG_ASM${ASM_DIALECT} "-I")       # -I

GET_FILENAME_COMPONENT(CMAKE_BASE_NAME "${CMAKE_ASM${ASM_DIALECT}_COMPILER}" NAME_WE)

IF("${CMAKE_BASE_NAME}" STREQUAL "as")
  SET(CMAKE_BASE_NAME gas)
ENDIF("${CMAKE_BASE_NAME}" STREQUAL "as")

INCLUDE(Platform/${CMAKE_BASE_NAME} OPTIONAL)

IF(CMAKE_SYSTEM_PROCESSOR)
  INCLUDE(Platform/${CMAKE_SYSTEM_NAME}-${CMAKE_BASE_NAME}-${CMAKE_SYSTEM_PROCESSOR} OPTIONAL RESULT_VARIABLE _INCLUDED_FILE)
ENDIF(CMAKE_SYSTEM_PROCESSOR)
IF(NOT _INCLUDED_FILE)
  INCLUDE(Platform/${CMAKE_SYSTEM_NAME}-${CMAKE_C_COMPILER_ID}-ASM-${CMAKE_SYSTEM_PROCESSOR} OPTIONAL)
ENDIF(NOT _INCLUDED_FILE)

INCLUDE(Platform/${CMAKE_SYSTEM_NAME}-${CMAKE_BASE_NAME} OPTIONAL RESULT_VARIABLE _INCLUDED_FILE)
IF(NOT _INCLUDED_FILE)
  INCLUDE(Platform/${CMAKE_SYSTEM_NAME}-${CMAKE_C_COMPILER_ID}-ASM OPTIONAL)
ENDIF(NOT _INCLUDED_FILE)

IF(NOT CMAKE_ASM@ASM_DIALECT@_SOURCE_FILE_EXTENSIONS)
  SET(CMAKE_ASM@ASM_DIALECT@_SOURCE_FILE_EXTENSIONS s;S;asm)
ENDIF(NOT CMAKE_ASM@ASM_DIALECT@_SOURCE_FILE_EXTENSIONS)

IF(NOT CMAKE_ASM${ASM_DIALECT}_COMPILE_OBJECT)
  SET(CMAKE_ASM${ASM_DIALECT}_COMPILE_OBJECT "<CMAKE_ASM${ASM_DIALECT}_COMPILER> <FLAGS> -o <OBJECT> <SOURCE>")
ENDIF(NOT CMAKE_ASM${ASM_DIALECT}_COMPILE_OBJECT)

IF(NOT CMAKE_ASM${ASM_DIALECT}_CREATE_STATIC_LIBRARY)
  SET(CMAKE_ASM${ASM_DIALECT}_CREATE_STATIC_LIBRARY
      "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS> "
      "<CMAKE_RANLIB> <TARGET> ")
ENDIF(NOT CMAKE_ASM${ASM_DIALECT}_CREATE_STATIC_LIBRARY)

IF(NOT CMAKE_ASM${ASM_DIALECT}_LINK_EXECUTABLE)
  SET(CMAKE_ASM${ASM_DIALECT}_LINK_EXECUTABLE
    "<CMAKE_LINKER> <FLAGS> <CMAKE_ASM${ASM_DIALECT}_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> <LINK_LIBRARIES>")
ENDIF(NOT CMAKE_ASM${ASM_DIALECT}_LINK_EXECUTABLE)

# to be done
IF(NOT CMAKE_ASM${ASM_DIALECT}_CREATE_SHARED_LIBRARY)
  SET(CMAKE_ASM${ASM_DIALECT}_CREATE_SHARED_LIBRARY)
ENDIF(NOT CMAKE_ASM${ASM_DIALECT}_CREATE_SHARED_LIBRARY)

IF(NOT CMAKE_ASM${ASM_DIALECT}_CREATE_SHARED_MODULE)
  SET(CMAKE_ASM${ASM_DIALECT}_CREATE_SHARED_MODULE)
ENDIF(NOT CMAKE_ASM${ASM_DIALECT}_CREATE_SHARED_MODULE)


SET(CMAKE_ASM${ASM_DIALECT}_INFOMATION_LOADED 1)

