cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Set the source files for your project
set(SOURCES
    main.cpp
    random.cpp
    render.cpp
)

# Add the executable target
add_executable(prog ${SOURCES})

# Set the include directories
target_include_directories(prog PRIVATE /opt/homebrew/Cellar/sfml/2.6.1/include)

# Set the library directories
target_link_directories(prog PRIVATE /opt/homebrew/Cellar/sfml/2.6.1/lib)

# Link the required libraries
target_link_libraries(prog PRIVATE sfml-graphics sfml-window sfml-system)

# Define a custom target to run the executable
add_custom_target(run
    COMMAND ./prog
    DEPENDS prog
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
