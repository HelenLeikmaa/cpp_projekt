# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\kysitlus_Tartu2024_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\kysitlus_Tartu2024_autogen.dir\\ParseCache.txt"
  "kysitlus_Tartu2024_autogen"
  )
endif()
