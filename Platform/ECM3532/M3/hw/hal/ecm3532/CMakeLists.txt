set(getsoc "CONFIG_SOC")
CONFIGVAL(soc ${getsoc})
SUBDIRLIST(SDIRS ${CMAKE_CURRENT_LIST_DIR})

FOREACH(subdir ${SDIRS})
    ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
