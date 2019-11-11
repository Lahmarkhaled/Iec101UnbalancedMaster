####################
file(GLOB IEC_101_SRCS include/*.h src/*.cpp)

file(GLOB IEC_101_PHYSICAL_SRCS include/Physical/*.h src/Physical/*.cpp)

###################
source_group(Iec101 FILES ${IEC_101_SRCS})
source_group(Iec101\\Physical FILES ${IEC_101_PHYSICAL_SRCS})

###################
set(IEC_101_COMBINED_SRCS ${IEC_101_SRCS} ${IEC_101_PHYSICAL_SRCS})

###################

if (GL_USE_STATIC_LIBS)
	add_library(Iec101.UnbalancedMaster STATIC ${IEC_101_COMBINED_SRCS})
	target_compile_definitions(Iec101.UnbalancedMaster PUBLIC -DGL_USE_STATIC_LIBS)
endif()

if (GL_USE_BOOST_IO_CONTEXT)
	target_compile_definitions(Iec101.UnbalancedMaster PUBLIC -DGL_USE_BOOST_IO_CONTEXT)
endif()

set_target_properties(Iec101.UnbalancedMaster PROPERTIES OUTPUT_NAME "Iec101.UnbalancedMaster${Io_Lib_Prefix}")
set_target_properties(Iec101.UnbalancedMaster PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

######################
target_include_directories(Iec101.UnbalancedMaster PUBLIC ${Boost_INCLUDE_DIRS})

if (${WIN32})
	target_include_directories(Iec101.UnbalancedMaster PUBLIC ${CMAKE_INSTALL_PREFIX}/include)
endif()

target_include_directories(Iec101.UnbalancedMaster PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

######################
target_link_libraries(Iec101.UnbalancedMaster ${Io.Utility} ${Ut.GeneralUtility} ${Boost_LIBRARIES})

######################################
install(TARGETS Iec101.UnbalancedMaster
  ARCHIVE DESTINATION "lib"
  LIBRARY DESTINATION "lib"
  RUNTIME DESTINATION "bin")
  
install(DIRECTORY include/ DESTINATION include/Iec101UnbalancedMaster FILES_MATCHING PATTERN ".h")