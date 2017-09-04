cmake_minimum_required(VERSION 3.8)
project(src)

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

find_package(OpenGL REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/src/headers
        ${PROJECT_SOURCE_DIR}/lib/glfw/include
        ${PROJECT_SOURCE_DIR}/lib/glad/include
        ${PROJECT_SOURCE_DIR}/lib/glm
)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/sources/*.cpp)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/src/headers/*.hpp)
file(GLOB_RECURSE SHADERS
        ${PROJECT_SOURCE_DIR}/src/shaders/*.comp
        ${PROJECT_SOURCE_DIR}/src/shaders/*.vert
        ${PROJECT_SOURCE_DIR}/src/shaders/*.geom
        ${PROJECT_SOURCE_DIR}/src/shaders/*.frag)

add_executable(src
        ${SOURCES}
        ${HEADERS}
        ${GLAD_SOURCES})

target_link_libraries(src glfw ${GLFW_LIBRARIES})

