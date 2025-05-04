#!/bin/bash

# install_myactuator_rmd.sh
# Installs the myactuator_rmd_py package from the current directory.
# Assumes prerequisites like Python 3, pip, a C++ compiler, and CMake are installed.

# Exit immediately if a command exits with a non-zero status.
set -e

# --- Configuration ---
# Specify the path to your CMake executable if it's not in the default PATH
# or if you need a specific version (like the one from snap).
# Leave empty to use the default 'cmake' found in PATH.
CMAKE_EXECUTABLE="/snap/bin/cmake"
# Project directory (assumes the script is run from the project root)
PROJECT_DIR="$(pwd)"

# --- Prerequisite Checks ---
echo "Checking prerequisites..."

# Check for Python 3 & pip
if ! command -v python3 &> /dev/null; then
    echo "Error: python3 not found."
    exit 1
fi
if ! python3 -m pip --version &> /dev/null; then
    echo "Error: pip not found for python3."
    exit 1
fi
echo "Python 3 and pip found."

# Determine CMake command
if [ -n "$CMAKE_EXECUTABLE" ]; then
    if ! command -v "$CMAKE_EXECUTABLE" &> /dev/null; then
        echo "Error: Specified CMAKE_EXECUTABLE '$CMAKE_EXECUTABLE' not found."
        exit 1
    fi
    CMAKE_CMD="$CMAKE_EXECUTABLE"
    echo "Using specified CMake: $CMAKE_CMD"
else
    if ! command -v cmake &> /dev/null; then
        echo "Error: cmake not found in PATH. Install CMake or set CMAKE_EXECUTABLE."
        exit 1
    fi
    CMAKE_CMD="cmake"
    echo "Using CMake from PATH: $(command -v cmake)"
fi

# --- Installation Steps ---
echo "Starting installation of myactuator_rmd_py..."

# 1. Install/Upgrade required packages (using --user to match previous successful install)
echo "Installing/upgrading required packages..."
python3 -m pip install --upgrade pip wheel build pybind11 setuptools --user

# 2. Build the wheel
echo "Building wheel for myactuator_rmd_py from $PROJECT_DIR..."
export CMAKE_COMMAND="$CMAKE_CMD"
python3 -m pip wheel . --no-deps -w dist/

# 3. Install the wheel
echo "Installing the wheel..."
python3 -m pip install --user --force-reinstall dist/myactuator_rmd_py*.whl

echo ""
echo "Installation of myactuator_rmd_py completed successfully!"
exit 0 
