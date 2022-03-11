
if(WIN32)

set(wxBUILD_SHARED OFF)
set(wxUSE_STL ON)
add_subdirectory(lib/wxWidgets)

set(WX_LIB wx::core wx::base)

else()

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
set(WX_LIB ${wxWidgets_LIBRARIES})

endif()

include(cryptopp.cmake)
