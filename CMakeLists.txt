cmake_minimum_required(VERSION 3.17)
project(Engine C)

if(UNIX)
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(LIB REQUIRED sdl2 glew)
endif(UNIX)

if(WIN32)
	find_package(SDL2 CONFIG REQUIRED)
	find_package(GLEW REQUIRED)
endif(WIN32)

set(CMAKE_C_STANDARD 99)

if(UNIX)
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -lm")
endif(UNIX)

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
		src/draw_model.h "src/external/stb_image.h" "src/util.c" "src/util.h")

if(UNIX)

	add_subdirectory(src/external/cglm)

	target_link_libraries(Engine ${LIB_LIBRARIES} cglm)
	target_include_directories(Engine PUBLIC ${LIB_INCLUDE_DIRS})
	target_compile_options(Engine PUBLIC ${LIB_CFLAGS_OTHER})
endif(UNIX)

if(WIN32)

    add_subdirectory(src/external/cglm)

    target_link_libraries(Engine PRIVATE SDL2::SDL2 SDL2::SDL2main)

    target_link_libraries(Engine PRIVATE GLEW::GLEW)

    target_link_libraries(Engine PRIVATE cglm)
endif(WIN32)