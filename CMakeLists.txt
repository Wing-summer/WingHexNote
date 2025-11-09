cmake_minimum_required(VERSION 3.16)

project(WingHexNote)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

option(WINGHEX_TEST_MODE TRUE)

find_package(
    Qt6
    COMPONENTS Widgets Core LinguistTools
    REQUIRED)

add_subdirectory(WingPlugin)

set(TS_FILES WingHexNote_zh_CN.ts WingHexNote_zh_TW.ts WingHexNote_en_US.ts)

set(TRANSLATION_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

qt6_create_translation(QM_FILES ${TRANSLATION_PATH} ${TS_FILES} OPTIONS
                       -no-obsolete)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/TranslationUtils.cmake)
add_plugin_translations_resource(QM_RES WingHexNote ${QM_FILES})

add_library(
    WingHexNote SHARED
    ${QM_FILES}
    ${QM_RES}
    WingHexNote.json
    src/winghexnote.h
    src/winghexnote.cpp
    src/noteeditorwidget.h
    src/noteeditorwidget.cpp
    src/wingnotecreator.h
    src/wingnotecreator.cpp
    resources.qrc)

set_target_properties(WingHexNote PROPERTIES SUFFIX ".wingplg")

if(WINGHEX_TEST_MODE)
    set(WINGHEX_PATH "${CMAKE_BINARY_DIR}")

    set(WINGHEX_PLUGIN_PATH "${WINGHEX_PATH}/plugin")
    add_custom_command(
        TARGET WingHexNote
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${WINGHEX_PLUGIN_PATH}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:WingHexNote> ${WINGHEX_PLUGIN_PATH})
endif()

target_link_libraries(WingHexNote PRIVATE Qt6::Widgets Qt6::Core WingPlugin)
