# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Viches_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Viches_autogen.dir/ParseCache.txt"
  "Viches_autogen"
  )
endif()
