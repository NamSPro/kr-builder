add_library(lib texture_wrapper.cpp)

target_link_libraries(lib PUBLIC SDL2::Main SDL2::Image SDL2::TTF)