# ============================================================================
# / <summary>
# / CMakeLists.txt
# / ModernCplusPlus
# / created by Mehrdad Soleimanimajd on 27.11.2019
# / </summary>
# / <created>ʆϒʅ, 27.11.2019</created>
# / <changed>ʆϒʅ, 03.07.2023</changed>
# ============================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME ModernCplusPlus)

set(PROJECT_NAME ${TARGET_NAME})

set(CMAKE_CXX_COMPILER Clang++)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME}
  VERSION 1.0.1.0
  DESCRIPTION "A brief introduction to modern C++"
  HOMEPAGE_URL "https://github.com/s-mehrdad/ModernCplusPlus"
  LANGUAGES CXX
)

set(VerCompanyName "BirdSofts")
set(VerFileDescription "A brief introduction to modern C++")
set(VerFileVersion "1,0,1,0")
set(VerInternalName ${TARGET_NAME})
set(VerLegalCopyright "Copyright (C) 2019-2023")
set(VerLegalTrademarks1 "BS")
set(VerLegalTrademarks2 "BSs")
set(VerOriginalFilename ${TARGET_NAME})
set(VerProductName ${TARGET_NAME})
set(VerProductName ${TARGET_NAME})
set(VerProductVersion ${CMAKE_PROJECT_VERSION})

set(VerProjectType "VFT_APP")

configure_file(
  ModernCplusPlus.rc.in
  ModernCplusPlus.rc
  @ONLY
  NEWLINE_STYLE LF
)

list(APPEND RESOURCES
  ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.rc
  resource.h
)

list(APPEND HEADER_FILES
  pch.h
  _1_Introduction.h
  _2_UsabilityEnhancements.h
  _3_RuntimeEnhancements.h
  Console.h
  Terminal.h
)

list(APPEND SOURCE_FILES
  pch.cpp
  ModernCplusPlus.cpp
  _1_Introduction.cpp
  _2_UsabilityEnhancements.cpp
  _3_RuntimeEnhancements.cpp
  Console.cpp
  Terminal.cpp
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
