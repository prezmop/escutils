cmake_minimum_required (VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")

project (escutils)

include(ExternalProject)
ExternalProject_Add(libcryptopp
	GIT_REPOSITORY ${CMAKE_SOURCE_DIR}/lib/cryptopp
	
	CONFIGURE_COMMAND ""
	UPDATE_COMMAND ""
	
	INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp
	BUILD_IN_SOURCE 1
	BUILD_COMMAND make
	INSTALL_COMMAND make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp
	)

set(wxBUILD_SHARED OFF)
set(wxUSE_STL ON)
add_subdirectory(lib/wxWidgets)
	
add_executable(escutils src/main.cpp src/cryptography.cpp src/mainwindow.cpp src/wxwin/window.cpp)
target_include_directories(escutils PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/include/)
target_link_libraries(escutils ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/lib/libcryptopp.a)
target_link_libraries(escutils wx::core wx::base)
