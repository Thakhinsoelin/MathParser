cmake_minimum_required(VERSION 3.10)

project(MathParser LANGUAGES C)
set(CMAKE_C_STANDARD 11)

# Collect source files
file(GLOB SRC_FILES "src/*.c")

# Create the Library Target
add_library(MathParser ${SRC_FILES})
add_library(MathParser::MathParser ALIAS MathParser)

# Set Include Directories
target_include_directories(MathParser PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:include>
)

# --- INSTALLATION LOGIC ---
# We wrap this in a check so it only runs for YOU (the developer)
# and NOT for people using FetchContent to include your code.
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)

    # 1. Install the Library Binaries
    install(TARGETS MathParser
        EXPORT MathParserTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    # 2. Install the Header files (Corrected Destination)
    install(FILES 
        includes/vec.h 
        includes/Scanner.h 
        includes/Parser.h 
        includes/Ast.h
        includes/Mparser.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # 3. Generate the Export File
    install(EXPORT MathParserTargets
        FILE MathParserTargets.cmake
        NAMESPACE MathParser::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathParser
    )

    # 4. Generate the Package Config
    # NOTE: Ensure you create Config.cmake.in in your root folder!
    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/MathParserConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathParser
    )

    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/MathParserConfig.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathParser
    )
endif()