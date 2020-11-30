
add_executable(PitchTrainer main.cpp Game.cpp Keypad.cpp Note.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(PitchTrainer sfml-audio sfml-graphics sfml-window sfml-system)