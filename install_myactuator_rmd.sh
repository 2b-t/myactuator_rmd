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

# 1. Install/Upgrade pybind11 (using --user to match previous successful install)
echo "Installing/upgrading pybind11..."
python3 -m pip install --upgrade pybind11 --user

# 2. Install the package
echo "Building and installing myactuator_rmd_py from $PROJECT_DIR..."
# Use --user install. Export CMAKE_COMMAND for the pip subprocess.
export CMAKE_COMMAND="$CMAKE_CMD"
# We keep the deprecated --global-option as it worked with the current setup.py.
# Consider updating to --config-settings if setup.py/build system is modernized.
python3 -m pip install . --user --global-option=build_ext

echo ""
echo "Installation of myactuator_rmd_py completed successfully!"
exit 0 
