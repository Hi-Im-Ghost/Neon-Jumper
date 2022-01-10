cmake_minimum_required(VERSION 3.20)
project(Platformer2D)

set(CMAKE_CXX_STANDARD 14)

add_executable(Platformer2D src/main.cpp src/Map.cpp src/Map.h src/Layer.cpp src/Layer.h src/TileSetMap.cpp src/TileSetMap.h src/TileSet.cpp src/TileSet.h src/TileMap.cpp src/TileMap.h src/LoadMap.cpp src/LoadMap.h src/entities/Player.cpp src/entities/Player.h src/entities/Slime.cpp src/entities/Slime.h src/entities/Enemy.cpp src/entities/Enemy.h src/states/GameState.cpp src/states/GameState.h src/states/MainMenuState.cpp src/states/MainMenuState.h src/states/LevelOneState.cpp src/states/LevelOneState.h src/UI/Button.cpp src/UI/Button.h src/states/LevelTwoState.cpp src/states/LevelTwoState.h src/modules/Animated.cpp src/modules/Animated.h src/modules/Damageable.cpp src/modules/Damageable.h src/modules/PlayerHUD.cpp src/modules/PlayerHUD.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(Platformer2D sfml-system sfml-window sfml-graphics sfml-audio)