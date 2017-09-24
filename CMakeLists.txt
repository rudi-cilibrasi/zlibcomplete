cmake_minimum_required(VERSION 3.0)

# Better behavior of VS generator.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

# Allow to specify VERSION in project()
cmake_policy(SET CMP0048 NEW)

set(ZLIBCOMPLETE_VERSION 1.0.5)

project(zlibcomplete VERSION ${ZLIBCOMPLETE_VERSION})

add_definitions(-DZLIBCOMPLETE_VERSION="${ZLIBCOMPLETE_VERSION}"
                -DZLIBCOMPLETE_GITHUB="https://github.com/HexwellC/zlibcomplete")

# Generate compilation database for YouCompleteMe and stuff like clang-tidy.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Allow some tweaks in build process without changing CMakeLists.
option(ZLIBCOMPLETE_WERROR  "Build with -Werror flag."                 OFF)
option(ZLIBCOMPLETE_WSTRICT "Build with really strict warning flags."  OFF)
option(ZLIBCOMPLETE_RELEASE "Build with optimizations"                 ON)

# Check if used compiler supports warning flags we use.
if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR
   ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR
   ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang"))
    if (ZLIBCOMPLETE_WSTRICT)
        set(WARNING_FLAGS ${WARNING_FLAGS} -Wall -Wextra -pedantic -Weffc++
                -Wcast-align -Wcast-qual -Wno-ctor-dtor-privacy
                -Wdisabled-optimization -Wformat=2 -Winit-self
                -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast
                -Woverloaded-virtual -Wredundant-decls -Wshadow
                -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch
                -Wundef -Wno-unused -Wnon-virtual-dtor -Wreorder -Wdeprecated
                -Wno-float-equal
                )
    endif()
    if(ZLIBCOMPLETE_WERROR)
        set(WARNING_FLAGS ${WARNING_FLAGS} -Werror)
    endif()
else()
    message(WARNING "Using WERROR/WSTRICT with non-GCC like compiler is not supported. Ignoring.")
endif()

# Documentation (Doxygen)

find_package(Doxygen)
option(ZLIBCOMPLETE_DOCS    "Generate HTML documentation (Doxygen)"    ${DOXYGEN_FOUND})
if(ZLIBCOMPLETE_DOCS)
    if (NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is required to build documentation.")
        # Don't have to put everything else in else branch because FATAL_ERROR aborts configuration.
    endif()

    configure_file(${CMAKE_SOURCE_DIR}/Doxyfile ${CMAKE_BINARY_DIR}/Doxyfile @ONLY)

    add_custom_target(doc ALL
                      COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
                      WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                      COMMENT "Generating HTML API documentation using Doxygen"
                      SOURCES ${PROJECT_SOURCE_DIR}/Doxyfile
                      BYPRODUCTS ${PROJECT_BINARY_DIR}/docs
                      VERBATIM
                      )

    install(DIRECTORY ${PROJECT_BINARY_DIR}/docs/ DESTINATION share/doc/zlibcomplete)
endif()

# Library itself

option(ZLIBCOMPLETE_STATIC "Build static library." ON )
option(ZLIBCOMPLETE_SHARED "Build shared library." OFF)

file(GLOB_RECURSE ZLIBCOMPLETE_HEADERS ${PROJECT_SOURCE_DIR}/lib/*.h)
file(GLOB_RECURSE ZLIBCOMPLETE_SOURCES ${PROJECT_SOURCE_DIR}/lib/*.cpp)

if(ZLIBCOMPLETE_STATIC)
    add_library(zlibcomplete STATIC ${ZLIBCOMPLETE_HEADERS} ${ZLIBCOMPLETE_SOURCES})
endif()

if(ZLIBCOMPLETE_SHARED)
    add_library(zlibcomplete SHARED ${ZLIBCOMPLETE_HEADERS} ${ZLIBCOMPLETE_SOURCES})
endif()

target_link_libraries(zlibcomplete PUBLIC ${ZLIBCOMPLETE_DEPENDENCIES})
target_include_directories(zlibcomplete PUBLIC ${PROJECT_SOURCE_DIR}/lib)
target_compile_options(zlibcomplete PRIVATE ${WARNING_FLAGS})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/zlibcomplete
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")
install(TARGETS zlibcomplete
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

option(ZLIBCOMPLETE_EXAMPLES "Build examples." OFF)

if(ZLIBCOMPLETE_EXAMPLES)
    add_subdirectory(${PROJECT_SOURCE_DIR}/examples)
endif()
