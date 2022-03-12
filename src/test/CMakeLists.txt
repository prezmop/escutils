cmake_minimum_required (VERSION 3.21)

find_package(Catch2 REQUIRED)
add_executable(escutilstest testmain.cpp
	crypto/reversefilter_test.cpp
	crypto/nullpadfilter_test.cpp
	crypto/nullstripfilter_test.cpp
	crypto/bypassablefilter_test.cpp
)
target_link_libraries(escutilstest Catch2::Catch2 libescutils)

include(CTest)
include(Catch)
catch_discover_tests(escutilstest)
