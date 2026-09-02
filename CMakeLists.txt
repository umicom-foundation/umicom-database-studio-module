#-----------------------------------------------------------------------------
# Umicom Database Studio Module
# File: CMakeLists.txt
#
# PURPOSE:
#   Build a thin C23 product composition over Framework-owned application
#   experience, runtime and workbench contracts.
#
# AUTHOR AND ORGANISATION:
#   Sammy Hegab
#   Umicom Foundation
#
# LICENCE:
#   MIT
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.24)

project(
    DatabaseStudioModule
    VERSION 0.1.0
    DESCRIPTION "Thin Umicom Database Studio composition over Umicom Framework"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(UMICOM_DATABASE_STUDIO_BUILD_CONSOLE
       "Build the native Umicom Database Studio verification console"
       ON)

include(CTest)
include(GNUInstallDirs)

# Load the dependency only when the parent build has not already provided its target.
if(NOT TARGET Umicom::Framework)
    find_package(UmicomFramework CONFIG REQUIRED)
endif()

# Load the dependency only when the parent build has not already provided its target.
if(NOT TARGET Umicom::application)
    message(FATAL_ERROR
        "Umicom Database Studio requires Framework target Umicom::application")
endif()

# Define the local fallback only when the parent build did not provide the shared helper.
if(NOT COMMAND umicom_apply_warnings)
    # Define the apply warnings build helper so parent and application projects apply one
    # consistent rule.
    function(umicom_apply_warnings target)
        # Select the warning options understood by the active compiler.
        if(MSVC)
            target_compile_options(${target} PRIVATE /W4)
        # Use this fallback path when the earlier condition does not apply.
        else()
            target_compile_options(${target} PRIVATE
                -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
        endif()
    endfunction()
endif()

# Define the local fallback only when the parent build did not provide the shared helper.
if(NOT COMMAND umicom_apply_sanitizers)
    # Define the apply sanitizers build helper so parent and application projects apply one
    # consistent rule.
    function(umicom_apply_sanitizers target)
    endfunction()
endif()

add_library(umicom_database_studio_module STATIC
    src/application.c
    src/workspace.c
)
add_library(Umicom::database_studio_module ALIAS umicom_database_studio_module)

target_include_directories(umicom_database_studio_module PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(umicom_database_studio_module PUBLIC
    Umicom::Framework
    Umicom::application
)
umicom_apply_warnings(umicom_database_studio_module)
umicom_apply_sanitizers(umicom_database_studio_module)

include(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../framework/cmake/UmicomThinApplicationRuntime.cmake")
umicom_extend_thin_application_runtime(
    NAME "database-studio"
    TARGET "umicom_database_studio_module")

# Create this optional product surface only when its build option is enabled.
if(UMICOM_DATABASE_STUDIO_BUILD_CONSOLE)
    add_executable(umicom-database-studio-console
        src/console/main.c)
    target_link_libraries(umicom-database-studio-console PRIVATE Umicom::database_studio_module)
    umicom_apply_warnings(umicom-database-studio-console)
    umicom_apply_sanitizers(umicom-database-studio-console)
endif()

# Register verification targets only when the developer has enabled testing.
if(BUILD_TESTING)
    add_executable(database_studio-application-test
        tests/test_application.c)
    target_link_libraries(database_studio-application-test PRIVATE Umicom::database_studio_module)
    umicom_apply_warnings(database_studio-application-test)
    umicom_apply_sanitizers(database_studio-application-test)
    add_test(NAME database-studio.module.application
             COMMAND database_studio-application-test)

    add_executable(database_studio-workspace-test
        tests/test_workspace.c)
    target_link_libraries(database_studio-workspace-test PRIVATE Umicom::database_studio_module)
    umicom_apply_warnings(database_studio-workspace-test)
    umicom_apply_sanitizers(database_studio-workspace-test)
    add_test(NAME database-studio.module.workspace
             COMMAND database_studio-workspace-test)
endif()

install(TARGETS umicom_database_studio_module
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
# Configure the optional target only when its feature has created it.
if(TARGET umicom-database-studio-console)
    install(TARGETS umicom-database-studio-console
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES application.umicom.yaml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/umicom/applications/database-studio)
# Use the optional file only when it is present in this checkout.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    install(FILES LICENSE
        DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/database-studio)
endif()

message(STATUS "Umicom Database Studio Module version: ${PROJECT_VERSION}")
message(STATUS "Umicom Database Studio uses Framework-owned application experience")

include(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../framework/cmake/UmicomApplicationProductisationContribution.cmake")
umicom_add_application_productisation_contribution(
    NAME "database-studio"
    TARGET umicom_database_studio_productisation
    SOURCE "src/productisation_contribution.c"
    TEST_SOURCE "tests/test_productisation_contribution.c")
