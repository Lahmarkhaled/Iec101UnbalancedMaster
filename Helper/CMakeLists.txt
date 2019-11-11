add_definitions(-DUNICODE -D_UNICODE)

########
set(IoHelper_PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(IO_PARALLEL_BUILD ON CACHE BOOL "Enable parallel build")
set(IO_USE_PCH OFF CACHE BOOL "Use pre-compiled headers")
set(GL_USE_STATIC_LIBS ON CACHE BOOL "Use static libraries")
set(GL_USE_BOOST_IO_CONTEXT ON CACHE BOOL "Use new boost io_context")

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d PARENT_SCOPE)
endif()

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)

if(${WIN32})
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../../install" PARENT_SCOPE)
endif()

if(${WIN32})
  set(BOOST_ROOT "C:/local/boost_1_65_1" CACHE PATH "")
  set(BOOST_INCLUDEDIR "C:/local/boost_1_65_1" CACHE PATH "")
  set(BOOST_LIBRARYDIR "C:/local/boost_1_65_1/lib64-msvc-14.1" CACHE PATH "")
  
  set(Qt5_DIR "C:/Qt/5.12.3/msvc2017_64/lib/cmake" CACHE PATH "")
  set(Qt5Widgets_DIR "${Qt5_DIR}/Qt5Widgets" PARENT_SCOPE)
  set(Qt5Network_DIR "${Qt5_DIR}/Qt5Network" PARENT_SCOPE)
  
  set(Protobuf_SRC_ROOT_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/protobuf" CACHE PATH "")
  
  set(GTEST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/gtest" CACHE PATH "")
  set(GTEST_MSVC_SEARCH "MD" CACHE STRING "")
  
  if(MSVC)
	if(IO_PARALLEL_BUILD)
	  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP" PARENT_SCOPE)
    endif()
  endif()
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" PARENT_SCOPE)
endif()

########
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "")

find_package(Boost COMPONENTS date_time filesystem system regex serialization locale)

########
if(Boost_FOUND)
  ################################
  set(Boost_FOUND ${Boost_FOUND} PARENT_SCOPE)
  set(Boost_INCLUDE_DIRS ${Boost_INCLUDE_DIRS} PARENT_SCOPE)
  set(Boost_LIBRARIES ${Boost_LIBRARIES} PARENT_SCOPE)
  
  ################################
  if(Boost_USE_STATIC_LIBS)
	set(Boost_Lib_Prefix "s")
  else()
    set(Boost_Lib_Prefix "d")
  endif()
  
  if(GL_USE_STATIC_LIBS)
    set(Io_Lib_Prefix "_${Boost_Lib_Prefix}s" PARENT_SCOPE)
  else()
    set(Io_Lib_Prefix "_${Boost_Lib_Prefix}d" PARENT_SCOPE)
  endif()
  
  ################################
  find_package(GTest)
  
  if(GTEST_FOUND)
    set(GTEST_FOUND ${GTEST_FOUND} PARENT_SCOPE)
    set(GTEST_INCLUDE_DIRS ${GTEST_INCLUDE_DIRS} PARENT_SCOPE)
    set(GTEST_LIBRARIES ${GTEST_LIBRARIES} PARENT_SCOPE)
    set(GTEST_MAIN_LIBRARIES ${GTEST_MAIN_LIBRARIES} PARENT_SCOPE)
    set(GTEST_BOTH_LIBRARIES ${GTEST_BOTH_LIBRARIES} PARENT_SCOPE)
  endif()
endif()