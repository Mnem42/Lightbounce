# CMakeList.txt : CMake project for Lightbounce, include source and define
# project specific logic here.
#

message("Compiling Lightbounce library")

# Add source to this project's executable.
add_executable (Lightbounce "Lightbounce.cpp" "Lightbounce.h" "core.h" "light_evolver.h" "pixels.h" "pixel_enums.h" "static_macros.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lightbounce PROPERTY CXX_STANDARD 20)
  message("cmake version is greater than 3.12")
else()
  message("cmake version is less than 3.12")
endif()

# TODO: Add tests and install targets if needed.
