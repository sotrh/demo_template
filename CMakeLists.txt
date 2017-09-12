cmake_minimum_required(VERSION 3.8)
project(demo_template)

set(CMAKE_CXX_STANDARD 11)

# --- glfw ---
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)

# --- glad ---
aux_source_directory(${PROJECT_SOURCE_DIR}/lib/glad/src GLAD_SOURCES)

# --- glm ---
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glm)

# --- openGL ---
find_package(OpenGL REQUIRED)

# --- main build commands ---
include_directories(
        ${PROJECT_SOURCE_DIR}/src/headers
        ${PROJECT_SOURCE_DIR}/lib/header-libs
        ${PROJECT_SOURCE_DIR}/lib/glfw/include
        ${PROJECT_SOURCE_DIR}/lib/glad/include
        ${PROJECT_SOURCE_DIR}/lib/glm
)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/sources/*.cpp)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/src/headers/*.hpp)
file(GLOB_RECURSE ASSETS ${PROJECT_SOURCE_DIR}/src/assets/*)
file(COPY ${PROJECT_SOURCE_DIR}/src/assets/
        DESTINATION ${PROJECT_BINARY_DIR}/assets/)

add_executable(demo_template
        ${SOURCES}
        ${HEADERS}
        ${ASSETS}
        ${GLAD_SOURCES})

target_link_libraries(demo_template glfw ${GLFW_LIBRARIES})

