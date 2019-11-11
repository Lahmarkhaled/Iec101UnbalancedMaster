cmake_minimum_required(VERSION 3.5)

project("IEC101 Unbalaned Master" CXX)

add_subdirectory(Helper)
add_subdirectory(Helper/Findlibraries/UtGeneralUtility)
add_subdirectory(Helper/Findlibraries/IoUtility)

if (${Boost_FOUND})
	add_subdirectory(Iec101UnbalancedMaster)
	add_subdirectory(Iec101UnbalancedMasterGUI)
endif()