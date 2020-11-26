
add_executable(PitchTrainer main.cpp Note.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(PitchTrainer sfml-audio sfml-system)