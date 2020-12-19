cmake_minimum_required(VERSION 3.17)
project(Engine C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIB REQUIRED sdl2 glew libpng16)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -lm")

add_executable(Engine src/main.c
		src/shader.c
		src/shader.h
		src/engine.h
		src/texture.c
		src/texture.h
		src/event.c
		src/event.h
		src/keyboard.c
		src/keyboard.h
		src/window.c
		src/window.h
		src/camera.c
		src/camera.h
		src/mouse.c
		src/mouse.h
		src/model/obj.c
		src/model/model.h
		src/game.c
		src/game.h
		src/draw_model.c
		src/draw_model.h)

target_link_libraries(Engine ${LIB_LIBRARIES})
target_include_directories(Engine PUBLIC ${LIB_INCLUDE_DIRS})
target_compile_options(Engine PUBLIC ${LIB_CFLAGS_OTHER})