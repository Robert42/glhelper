cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

if(NOT GLHELPER_CONFIG_DIR)
set(GLHELPER_CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/defaultconfig)
endif()

set(GLHELPER_CONFIG_FILE ${GLHELPER_CONFIG_DIR}/glhelperconfig.hpp)

add_subdirectory(glhelper)

target_include_directories(
   glhelper
   SYSTEM
   PUBLIC
   ${GLHELPER_CONFIG_DIR}
   ${CMAKE_CURRENT_SOURCE_DIR}
)
