# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MyMqttTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MyMqttTest_autogen.dir/ParseCache.txt"
  "MyMqttTest_autogen"
  )
endif()
