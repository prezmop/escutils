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
set(CRYPTOPP_LIB ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/lib/libcryptopp.a)
set(CRYPTOPP_INCLUDE ${CMAKE_CURRENT_BINARY_DIR}/lib/cryptopp/include/)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(escutils src/main.cpp src/crypto/cryptography.cpp src/crypto/nullstripfilter.cpp src/mainwindow.cpp src/wxwin/window.cpp)
target_include_directories(escutils PRIVATE ${CRYPTOPP_INCLUDE})
target_link_libraries(escutils ${CRYPTOPP_LIB})
target_link_libraries(escutils ${wxWidgets_LIBRARIES})
