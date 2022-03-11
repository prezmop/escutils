include(ExternalProject)

if(WIN32)

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

endif()
