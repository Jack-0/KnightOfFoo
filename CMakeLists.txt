cmake_minimum_required(VERSION 3.15)
project(TeaPot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w -lsfml-graphics -lsfml-window -lsfml-system")

# Statically link SFML
set(SFML_STATIC_LIBRARIES TRUE)
## In most cases better set in the CMake cache (Windows)
#set(SFML_DIR "./library/frameworks/SFML-2.5.1/lib/cmake/SFML")

add_executable(TeaPot src/main.cpp src/entity/GameObject.cpp src/entity/GameObject.h src/Game.cpp src/Game.h src/state/GameOverState.cpp src/state/GameOverState.h src/state/GameState.h src/state/GameStateMachine.cpp src/state/GameStateMachine.h src/state/PlayState.cpp src/state/PlayState.h src/state/MainMenuState.cpp src/state/MainMenuState.h src/graphics/GraphicsManager.cpp src/graphics/GraphicsManager.h src/utilities/LoaderParams.h src/entity/Entity.h)