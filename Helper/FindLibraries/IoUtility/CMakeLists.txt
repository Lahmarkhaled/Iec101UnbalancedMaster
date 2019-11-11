unset(__IoUtility CACHE)
unset(__IoUtilityd CACHE)

if(${WIN32})
    find_library(__IoUtility NAMES "Io.Utility${Io_Lib_Prefix}" PATHS "${CMAKE_INSTALL_PREFIX}/lib")
    find_library(__IoUtilityd NAMES "Io.Utility${Io_Lib_Prefix}d" PATHS "${CMAKE_INSTALL_PREFIX}/lib")
else()
	find_library(__IoUtility NAMES "Io.Utility${Io_Lib_Prefix}")
    find_library(__IoUtilityd NAMES "Io.Utility${Io_Lib_Prefix}d")
endif()

set(Io.Utility "")

if(NOT (__IoUtility STREQUAL "__IoUtility-NOTFOUND"))
    set(Io.Utility "optimized;${__IoUtility};")
endif()

if(NOT (__IoUtilityd STREQUAL "__IoUtilityd-NOTFOUND"))
    set(Io.Utility "${Io.Utility};debug;${__IoUtilityd};")
endif()

set(Io.Utility ${Io.Utility} PARENT_SCOPE)

unset(__IoUtility CACHE)
unset(__IoUtilityd CACHE)