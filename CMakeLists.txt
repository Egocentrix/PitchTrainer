cmake_minimum_required(VERSION 3.0.0)
project(AudioPlayer VERSION 0.1.0)

add_executable(PitchTrainer main.cpp)

target_link_libraries(PitchTrainer sfml-audio sfml-system)