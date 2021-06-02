if(NOT PREFER_BUNDLED_LIBS)
  set(CMAKE_MODULE_PATH ${ORIGINAL_CMAKE_MODULE_PATH})
  find_package(DPP)
  set(CMAKE_MODULE_PATH ${OWN_CMAKE_MODULE_PATH})
  if(DPP_FOUND)
    set(DPP_BUNDLED OFF)
    set(DPP_DEP)
  endif()
endif()

if(NOT DPP_FOUND)
  set(DPP_SRC_DIR other/dpp/src)
  set(DPP_INCLUDEDIR other/dpp/include)
  file(GLOB DPP_SRC ${DPP_SRC_DIR}/* ${DPP_INCLUDEDIR}/*)
  add_library(dpp EXCLUDE_FROM_ALL OBJECT ${DPP_SRC})
  target_include_directories(dpp PRIVATE ${DPP_INCLUDEDIR})

  set(DPP_DEP $<TARGET_OBJECTS:dpp>)
  set(DPP_INCLUDE_DIRS ${DPP_INCLUDEDIR})
  set(DPP_LIBRARIES)

  list(APPEND TARGETS_DEP dpp)

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(DPP DEFAULT_MSG DPP_INCLUDEDIR)

  set(DPP_BUNDLED ON)
endif()