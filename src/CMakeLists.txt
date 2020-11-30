
set(SRC main.cpp 
        Game.cpp 
        Keypad.cpp 
        Note.cpp
    )

add_executable(PitchTrainer ${SRC})

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(PitchTrainer sfml-audio sfml-graphics sfml-window sfml-system)