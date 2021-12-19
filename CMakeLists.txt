
# *******************************************************************************************
#/ <summary>
#/
#/ </summary>
#/ <created>ʆϒʅ,27.11.2019</created>
#/ <changed>ʆϒʅ,19.12.2021</changed>
# *******************************************************************************************

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME ModernCplusPlus)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
  VERSION 1.0.0.1
  DESCRIPTION "A brief introduction to modern C++"
  HOMEPAGE_URL "https://github.com/BirdSofts/ModernCplusPlus"
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 20)

if(MSVC)
  list(APPEND RESOURCES
    ${TARGET_NAME}.rc
    resource.h
    )
endif(MSVC)

list(APPEND HEADER_FILES
  pch.h
  _1_Introduction.h
  _2_UsabilityEnhancements.h
  _3_RuntimeEnhancements.h
  Console.h
  )

list(APPEND SOURCE_FILES
  pch.cpp
  ModernCplusPlus.cpp
  _1_Introduction.cpp
  _2_UsabilityEnhancements.cpp
  _3_RuntimeEnhancements.cpp
  Console.cpp
  )

if(WIN32)
  list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})

if(MINGW)
  add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
    COMMAND cmake -E copy_if_different
    ${CMAKE_PREFIX_PATH}/bin/libgcc_s_seh-1.dll
    ${CMAKE_PREFIX_PATH}/bin/libstdc++-6.dll
    ${CMAKE_PREFIX_PATH}/bin/libwinpthread-1.dll
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endif(MINGW)
