GETCONFIG(varen "HAL_SPI_SLAVE")
string(COMPARE EQUAL "${varen}" y _cmp)
if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/src)
    if (_cmp)
        file (GLOB tmr "${CMAKE_CURRENT_LIST_DIR}/src/*.c")
        foreach (tsrc ${tmr})
            target_sources(hal PRIVATE ${tsrc})
        endforeach()
    endif()
endif()
