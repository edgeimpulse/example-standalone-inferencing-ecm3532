GETCONFIG(sensoren "SENSOR_MANAGER")
string(COMPARE EQUAL "${sensoren}" y _cmp)
if (_cmp)
file (GLOB sensor "${CMAKE_CURRENT_LIST_DIR}/*.c")
foreach (sensrc ${sensor})
    target_sources(sm PRIVATE ${sensrc})
endforeach()
endif()
