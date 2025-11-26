# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtPostgresBackend_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtPostgresBackend_autogen.dir/ParseCache.txt"
  "QtPostgresBackend_autogen"
  )
endif()
