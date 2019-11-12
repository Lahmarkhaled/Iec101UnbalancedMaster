set(IEC_101_UNBALANCED_MASTER_GUI ON CACHE BOOL "GUI")

if (NOT ${IEC_101_UNBALANCED_MASTER_GUI})
	return()
endif()
##############

file(GLOB IEC101_MASTER_GUI_SRCS include/*.h src/*.cpp)

source_group(Iec101 FILES ${IEC101_MASTER_GUI_SRCS})

if (${WIN32})
	#add_executable(Iec101.Gui WIN32 ${IEC101_MASTER_GUI_SRCS})
	add_executable(Iec101.Gui ${IEC101_MASTER_GUI_SRCS})
else()
	add_executable(Iec101.Gui ${IEC101_MASTER_GUI_SRCS})
endif()
##############

set_target_properties(Iec101.Gui PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

target_include_directories(Iec101.Gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Iec101.Gui Iec101.UnbalancedMaster ${Io.Utility} ${Ut.GeneralUtility} ${Boost_LIBRARIES})

