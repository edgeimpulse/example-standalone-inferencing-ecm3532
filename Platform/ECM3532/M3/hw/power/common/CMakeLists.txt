GETCONFIG(pmen "PM_MON")
string(COMPARE EQUAL "${pmen}" y _pmen)
if (_pmen)
    file (GLOB POW "${CMAKE_CURRENT_LIST_DIR}/src/*.c")
    foreach (psrc ${POW})
        target_sources(pm PRIVATE ${psrc})
    endforeach()
endif ()
