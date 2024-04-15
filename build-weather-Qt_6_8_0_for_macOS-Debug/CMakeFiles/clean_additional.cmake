# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MainProject_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MainProject_autogen.dir/ParseCache.txt"
  "MainProject_autogen"
  )
endif()
