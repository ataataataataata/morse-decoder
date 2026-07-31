cmake_minimum_required(VERSION 3.16)

project(MorseDecoder)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(MorseDecoder
    src/main.cpp
    src/Window.cpp
    src/Renderer.cpp
    src/MorseTranslator.cpp
    src/MorseInput.cpp
    src/Application.cpp
)

target_include_directories(MorseDecoder PRIVATE include)

target_link_libraries(MorseDecoder PRIVATE 
    SDL2::SDL2 
    SDL2_ttf::SDL2_ttf
)


file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
