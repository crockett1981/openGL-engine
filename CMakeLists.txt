cmake_minimum_required(VERSION 3.17)
project(Engine C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIB REQUIRED sdl2 glew libpng16)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra")

add_executable(Engine src/main.c
        src/engine/core/engine_init.c
        src/engine/core/engine_init.h
        src/engine/engine_common.h
        src/engine/core/engine_close.c
        src/engine/core/engine_close.h
        src/engine/render/shader.c
        src/engine/render/shader.h
        src/engine/engine.h
        src/engine/render/texture.c
        src/engine/render/texture.h src/engine/events/close_window.c src/engine/events/close_window.h src/engine/input/keyboard.c src/engine/input/keyboard.h src/engine/render/update.c src/engine/render/update.h)

target_link_libraries(Engine ${LIB_LIBRARIES})
target_include_directories(Engine PUBLIC ${LIB_INCLUDE_DIRS})
target_compile_options(Engine PUBLIC ${LIB_CFLAGS_OTHER})