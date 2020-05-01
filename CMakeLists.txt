#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.15)

project(KnightOfFoo)

include_directories("${PROJECT_BINARY_DIR}")
# Define sources and executable
set(EXECUTABLE_NAME "myproject")
#add_executable( main.cpp)
add_executable(${EXECUTABLE_NAME} src/main.cpp src/entity/GameObject.cpp src/entity/GameObject.h src/Game.cpp src/Game.h src/state/GameOverState.cpp src/state/GameOverState.h src/state/GameState.h src/state/GameStateMachine.cpp src/state/GameStateMachine.h src/state/PlayState.cpp src/state/PlayState.h src/state/PauseState.cpp src/state/PauseState.h src/state/MainMenuState.cpp src/state/MainMenuState.h src/graphics/GraphicsManager.cpp src/graphics/GraphicsManager.h src/utilities/LoaderParams.h src/entity/Entity.h src/entity/Text.cpp src/entity/Text.h src/entity/Button.cpp src/entity/Button.h src/input/InputHandler.cpp src/input/InputHandler.h src/world/World.cpp src/world/World.h src/entity/Tile.cpp src/entity/Tile.h src/entity/player/Player.cpp src/entity/player/Player.h src/entity/mob/Enemy.cpp src/entity/mob/Enemy.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)