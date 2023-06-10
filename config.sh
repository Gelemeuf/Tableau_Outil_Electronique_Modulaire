#!/bin/bash

# Project directory
project_directory="src/config"

# Path to the executable file
executable="config"

# Check if the executable file exists
if [ ! -f "$project_directory/$executable" ]; then
    echo "Executable file not found. Compiling..."
    
    # Change to the project directory
    cd "$project_directory" || exit
    
    # Compile using Makefile
    make
    
    if [ $? -eq 0 ]; then
        echo "Compilation successful. Running the program..."
        
        # Run the program
        "./$executable"
    else
        echo "Compilation failed. Please check your code."
    fi
else
    echo "Executable file found. Running the program..."
    
    # Run the program
    "./$project_directory/$executable"
fi

