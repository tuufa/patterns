# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\patterns_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\patterns_autogen.dir\\ParseCache.txt"
  "patterns_autogen"
  )
endif()
