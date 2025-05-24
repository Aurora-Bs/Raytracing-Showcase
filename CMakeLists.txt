cmake_minimum_required(VERSION 3.10.0)
project(raytracing VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
include(cmake/CPM.cmake)
CPMAddPackage("gh:libsdl-org/SDL#release-3.2.14")
CPMAddPackage("gh:ocornut/imgui#v1.91.9b")
CPMAddPackage("gh:gabime/spdlog#v1.15.3")
file(GLOB IMGUI_SOURCES "${imgui_SOURCE}/*.cpp")
file(GLOB SRC_FILES "*.cpp")
add_library(imgui STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.cpp
)
target_include_directories(imgui PRIVATE 
    ${imgui_SOURCE_DIR}
)
set(BUILD_TESTS false)
set(BUILD_MAIN true)
if(BUILD_MAIN) 

add_executable(raytracing ${SRC_FILES})
target_include_directories(raytracing PRIVATE 
    ${SDL_SOURCE_DIR}/include
    ${imgui_SOURCE_DIR}/backends
    ${imgui_SOURCE_DIR}
    include/
)
target_link_libraries(raytracing PRIVATE
    SDL3::SDL3
    imgui
    spdlog::spdlog
)
endif()




if(BUILD_TESTS)
add_executable(vectorLibTest vectorMath.cpp vectorLibTest.cpp)
target_include_directories(vectorLibTest PRIVATE include/)
endif()
include(CTest)
enable_testing()

