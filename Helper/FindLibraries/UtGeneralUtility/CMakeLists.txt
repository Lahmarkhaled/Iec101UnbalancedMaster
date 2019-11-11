unset(__UtGeneralUtility CACHE)
unset(__UtGeneralUtilityd CACHE)

if(${WIN32})
    find_library(__UtGeneralUtility NAMES "Ut.GeneralUtility${Io_Lib_Prefix}" PATHS "${CMAKE_INSTALL_PREFIX}/lib")
    find_library(__UtGeneralUtilityd NAMES "Ut.GeneralUtility${Io_Lib_Prefix}d" PATHS "${CMAKE_INSTALL_PREFIX}/lib")
else()
	find_library(__UtGeneralUtility NAMES "Ut.GeneralUtility${Io_Lib_Prefix}")
    find_library(__UtGeneralUtilityd NAMES "Ut.GeneralUtility${Io_Lib_Prefix}d")
endif()

set(Ut.GeneralUtility "")

if(NOT (__UtGeneralUtility STREQUAL "__UtGeneralUtility-NOTFOUND"))
    set(Ut.GeneralUtility "optimized;${__UtGeneralUtility};")
endif()

if(NOT (__UtGeneralUtilityd STREQUAL "__UtGeneralUtilityd-NOTFOUND"))
    set(Ut.GeneralUtility "${Ut.GeneralUtility};debug;${__UtGeneralUtilityd};")
endif()

set(Ut.GeneralUtility ${Ut.GeneralUtility} PARENT_SCOPE)

unset(__UtGeneralUtility CACHE)
unset(__UtGeneralUtilityd CACHE)