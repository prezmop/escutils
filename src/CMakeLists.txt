
if(WIN32)
add_executable(escutils WIN32)
else()
add_executable(escutils)
endif()
target_sources(escutils PRIVATE
	main.cpp
	mainwindow.cpp
	cryptopanel.cpp
	crypto/cryptography.cpp
	crypto/nullstripfilter.cpp
	wxwin/window.cpp
)
add_dependencies(escutils cryptopp)
target_include_directories(escutils PRIVATE ${CRYPTOPP_INCLUDE})
target_link_libraries(escutils ${CRYPTOPP_LIB})
target_link_libraries(escutils ${WX_LIB})
