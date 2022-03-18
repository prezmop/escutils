cmake_minimum_required (VERSION 3.21)

add_library(libescutils STATIC
	mainwindow.cpp
	cryptopanel.cpp
	crypto/cryptography.cpp
	crypto/nullstripfilter.cpp
	wxwin/window.cpp
)
add_dependencies(libescutils cryptopp)
target_include_directories(libescutils PUBLIC ${CRYPTOPP_INCLUDE})
target_link_libraries(libescutils ${CRYPTOPP_LIB})
target_link_libraries(libescutils ${WX_LIB})
target_include_directories(libescutils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
add_executable(escutils WIN32 main.cpp)
else()
add_executable(escutils main.cpp)
endif()

target_link_libraries(escutils libescutils)

if(BUILD_TESTING)
	add_subdirectory(test)
endif()
