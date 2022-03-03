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
		
#add_library(libcryptopp STATIC IMPORTED GLOBAL) 
#add_dependencies(libcryptopp libcryptopp_build)
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/include/)
#set_target_properties(libcryptopp_build PROPERTIES
#	IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/lib/libcryptopp.a
#	INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/include/
#)
#target_include_directories(libcryptopp INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/include/) 
#target_link_libraries(libcryptopp INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/lib/libcryptopp.a)

#find_package(wxWidgets REQUIRED gl core base)

set(wxBUILD_SHARED OFF)
set(wxUSE_STL ON)
add_subdirectory(lib/wxWidgets)
	
add_executable(escutils src/main.cpp src/cryptography.cpp src/mainwindow.cpp src/wxwin/window.cpp)
target_include_directories(escutils PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/include/)
target_link_libraries(escutils ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/lib/libcryptopp.a)
target_link_libraries(escutils wx::core wx::base)
