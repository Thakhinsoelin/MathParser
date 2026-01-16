cmake_minimum_required(VERSION 3.10)

project(MathParser LANGUAGES C)
# set(PROJECT_NAME math)
set(CMAKE_C_STANDARD 11)

file(GLOB SRC_FILES
    src/*.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_library(${PROJECT_NAME} ${SRC_FILES})
add_library(MathParser::MathParser ALIAS MathParser)
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:includes>
)

install(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 4. Install the Header files
install(FILES 
    includes/vec.h 
    includes/Scanner.h 
    includes/Parser.h 
    includes/Ast.h
    includes/Mparser.h

    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# 5. Generate the Config files so find_package() works
install(EXPORT MathParserTargets
    FILE MathParserTargets.cmake
    NAMESPACE MathParser::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathParser
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/MathParserConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathParser
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/MathParserConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathParser
)