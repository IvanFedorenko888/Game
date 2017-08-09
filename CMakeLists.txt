cmake_minimum_required(VERSION 3.8)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp view.cpp view.h item.h player.h door.h room.h listen.h listener.h model.h controller.h model.cpp controller.cpp)
add_executable(Game ${SOURCE_FILES})