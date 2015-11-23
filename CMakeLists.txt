cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

if(NOT GLHELPER_CONFIG_DIR)
set(GLHELPER_CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/defaultconfig)
endif()

add_subdirectory(glhelper)

target_sources(
  glhelper
  PRIVATE
  ${GLHELPER_CONFIG_DIR}/glhelperconfig.hpp
)

target_include_directories(
   glhelper
   SYSTEM
   PUBLIC
   ${GLHELPER_CONFIG_DIR}
)
