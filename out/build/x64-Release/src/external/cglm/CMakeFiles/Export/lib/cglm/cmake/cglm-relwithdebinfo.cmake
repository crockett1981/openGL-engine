#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cglm::cglm" for configuration "RelWithDebInfo"
set_property(TARGET cglm::cglm APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(cglm::cglm PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/cglm.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/cglm.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS cglm::cglm )
list(APPEND _IMPORT_CHECK_FILES_FOR_cglm::cglm "${_IMPORT_PREFIX}/lib/cglm.lib" "${_IMPORT_PREFIX}/lib/cglm.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
