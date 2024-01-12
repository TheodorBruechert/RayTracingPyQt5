cmake_minimum_required(VERSION 3.15)
project(Renderer)
set(Python_VIRTUALENV FIRST)

# Include pybind11 directory
add_subdirectory(external/pybind11)

# Find OpenCV and GLM if required
find_package(OpenCV REQUIRED)


# Set the path to the GLM library
set(GLM_DIR /usr/local/include/glm)
set(LIBPNG_DIR /usr/local/include/libpng16)
set(PYBIND11_DIR ./myenv/lib/python3.9/site-packages/pybind11/include)
set(PYTHON_INCLUDES /usr/local/Cellar/python\@3.9/3.9.18_1/Frameworks/Python.framework/Versions/3.9/include/python3.9/)
# Include directories for headers (GLM headers)
include_directories(${OpenCV_INCLUDE_DIRS} ${GLM_DIR} ${LIBPNG_DIR} include )


# Gather source files
set(SOURCES
    src/geometries.cpp
    src/helperFunctions.cpp
    src/main.cpp
    src/render.cpp
    src/pyModuleRenderer.cpp
)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)

# Create the Python module using pybind11
pybind11_add_module(rendererModule ${SOURCES})

# Link required libraries (OpenCV and any other necessary libraries)
target_link_libraries(rendererModule PRIVATE ${OpenCV_LIBS})

set_target_properties(rendererModule PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/myenv/lib/python3.9/site-packages)