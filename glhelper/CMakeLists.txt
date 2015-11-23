cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

project(glhelper)

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
)

add_library(glhelper ${GLHELPER_SOURCE})
