cmake_minimum_required (VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)

project (escutils)

include(ExternalProject)

if(WIN32)

#use static runtime library for the entire project (because cryptopp)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

ExternalProject_Add(cryptopp
	GIT_REPOSITORY ${CMAKE_SOURCE_DIR}/lib/cryptopp

	CONFIGURE_COMMAND ""
	UPDATE_COMMAND ""
	INSTALL_COMMAND ""
	INSTALL_DIR ""

	BUILD_IN_SOURCE 1
	BUILD_COMMAND msbuild -t:Build -p:Configuration=$<CONFIG> -p:Platform=x64 -m cryptlib.vcxproj
)
set(CRYPTOPP_LIB ${CMAKE_CURRENT_BINARY_DIR}/cryptopp-prefix/src/cryptopp/x64/Output/$<CONFIG>/cryptlib.lib)
set(CRYPTOPP_INCLUDE ${CMAKE_CURRENT_BINARY_DIR}/cryptopp-prefix/src/)

set(wxBUILD_SHARED OFF)
set(wxUSE_STL ON)
add_subdirectory(lib/wxWidgets)

set(WX_LIB wx::core wx::base)

else()

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")

ExternalProject_Add(cryptopp
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
set(WX_LIB ${wxWidgets_LIBRARIES})

endif()

if(WIN32)
add_executable(escutils WIN32)
else()
add_executable(escutils)
endif()
target_sources(escutils PRIVATE
	src/main.cpp
	src/crypto/cryptography.cpp
	src/crypto/nullstripfilter.cpp
	src/mainwindow.cpp
	src/cryptopanel.cpp
	src/wxwin/window.cpp
)
add_dependencies(escutils cryptopp)
target_include_directories(escutils PRIVATE ${CRYPTOPP_INCLUDE})
target_link_libraries(escutils ${CRYPTOPP_LIB})
target_link_libraries(escutils ${WX_LIB})
