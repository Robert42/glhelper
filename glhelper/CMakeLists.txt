cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

project(glhelper)

if(GLEW_ROOT)
set(CMAKE_PREFIX_PATH ${GLEW_ROOT})
endif()

find_package(GLEW)
find_package(OpenGL)

set(GLHELPER_SOURCE
  buffer.cpp
  buffer.hpp
  buffer.inl
  framebufferobject.cpp
  framebufferobject.hpp
  gl.cpp
  gl.hpp
  persistentringbuffer.cpp
  persistentringbuffer.hpp
  samplerobject.cpp
  samplerobject.hpp
  screenalignedtriangle.cpp
  screenalignedtriangle.hpp
  shaderdatametainfo.hpp
  shaderdatametainfo.inl
  shaderobject.cpp
  shaderobject.hpp
  statemanagement.cpp
  statemanagement.hpp
  statemanagement.inl
  texture2d.cpp
  texture2d.hpp
  texture3d.cpp
  texture3d.hpp
  texturebufferview.cpp
  texturebufferview.hpp
  texture.cpp
  textureformats.cpp
  textureformats.hpp
  texture.hpp
  textureview.cpp
  textureview.hpp
  utils/flagoperators.hpp
  utils/pathutils.cpp
  utils/pathutils.hpp
  vertexarrayobject.cpp
  vertexarrayobject.hpp
  ${GLHELPER_CONFIG_FILE}
)

add_library(glhelper ${GLHELPER_SOURCE})

target_include_directories(glhelper PUBLIC ${GLEW_INCLUDE_DIRS})

target_link_libraries(glhelper PUBLIC ${GLEW_LIBRARY} ${OPENGL_gl_LIBRARY})

target_compile_options(glhelper PUBLIC -std=c++11)
