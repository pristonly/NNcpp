cmake_minimum_required(VERSION 2.8)
project("NeuronsLibrary")
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Layers/ActivationFunctions.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Layers/ILayers.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Layers/ITeach.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Layers/Layer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Layers/List.cpp
)
set(HEADERS_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Layers/ActivationFunctions.h
${CMAKE_CURRENT_SOURCE_DIR}/Layers/ILayers.h
${CMAKE_CURRENT_SOURCE_DIR}/Layers/ITeach.h
${CMAKE_CURRENT_SOURCE_DIR}/Layers/Layer.h
${CMAKE_CURRENT_SOURCE_DIR}/Layers/List.h
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Layers)	
add_library(NeuronsLibrary STATIC ${HEADERS_LIB} ${SOURCE_LIB})