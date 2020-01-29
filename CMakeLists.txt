cmake_minimum_required(VERSION 3.15)
project(Knight_of_foo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w -lsfml-graphics -lsfml-window -lsfml-system")

# Statically link SFML
set(SFML_STATIC_LIBRARIES TRUE)
## In most cases better set in the CMake cache (Windows)
#set(SFML_DIR "./library/frameworks/SFML-2.5.1/lib/cmake/SFML")

add_executable(Knight_of_foo src/main.cpp src/entity/GameObject.cpp src/entity/GameObject.h src/Game.cpp src/Game.h src/state/GameOverState.cpp src/state/GameOverState.h src/state/GameState.h src/state/GameStateMachine.cpp src/state/GameStateMachine.h src/state/PlayState.cpp src/state/PlayState.h src/state/PauseState.cpp src/state/PauseState.h src/state/MainMenuState.cpp src/state/MainMenuState.h src/graphics/GraphicsManager.cpp src/graphics/GraphicsManager.h src/utilities/LoaderParams.h src/entity/Entity.h src/entity/Text.cpp src/entity/Text.h src/entity/Button.cpp src/entity/Button.h src/input/InputHandler.cpp src/input/InputHandler.h src/world/World.cpp src/world/World.h src/entity/Tile.cpp src/entity/Tile.h src/entity/player/Player.cpp src/entity/player/Player.h src/entity/mob/Enemy.cpp src/entity/mob/Enemy.h)