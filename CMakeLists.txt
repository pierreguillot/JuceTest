cmake_minimum_required(VERSION 3.12)

set(CMAKE_XCODE_GENERATE_SCHEME true)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version")
set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD)" CACHE STRING "" FORCE)
set(JUCE_ENABLE_MODULE_SOURCE_GROUPS ON CACHE BOOL "" FORCE)
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

project(JuceTest VERSION 0.0.1 LANGUAGES C CXX)

add_subdirectory(JUCE)

juce_add_gui_app(JuceTest
    PRODUCT_NAME                        "JuceTest"
    VERSION                             ${CMAKE_PROJECT_VERSION}
    BUNDLE_ID                           fr.pierre.guillot.juce.test
    COMPANY_COPYRIGHT                   "Nobody"
    COMPANY_NAME                        "Nobody"
    NEEDS_CURL                          FALSE
    NEEDS_WEB_BROWSER                   FALSE
    NEEDS_STORE_KIT                     FALSE
    PLIST_TO_MERGE                      "<plist><dict><key>LSApplicationCategoryType</key><string>public.app-category.music</string></dict></plist>"
    )

juce_generate_juce_header(JuceTest)
set_target_properties(JuceTest PROPERTIES CXX_STANDARD 20)

set(SOURCES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Source)

file(GLOB JuceTestSources
    ${SOURCES_DIRECTORY}/*.cpp
    ${SOURCES_DIRECTORY}/*.h
    ${CMAKE_CACHEFILE_DIR}/Result_artefacts/JuceLibraryCode/JuceHeader.h
)
source_group("Source" FILES ${JuceTestSources})
target_sources(JuceTest PRIVATE ${JuceTestSources})

target_compile_definitions(JuceTest PRIVATE
    DONT_SET_USING_JUCE_NAMESPACE=1
    JUCE_MODAL_LOOPS_PERMITTED=0
    JUCE_ALLOW_STATIC_NULL_VARIABLES=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_LOG_ASSERTIONS=0
    JUCE_STRICT_REFCOUNTEDPOINTER=1
    JUCE_USE_CURL=0
    JUCE_WEB_BROWSER=0
    JUCE_ENABLE_REPAINT_DEBUGGING=0
)

target_link_libraries(JuceTest PRIVATE
    juce::juce_gui_extra
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)

