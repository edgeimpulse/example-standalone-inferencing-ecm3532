GETCONFIG(varen "STUB_DRV")
string(COMPARE EQUAL "${varen}" y _cmp)
if (_cmp)
file (GLOB allsrc "${CMAKE_CURRENT_LIST_DIR}/*.c")
foreach (srcf ${allsrc})
    target_sources(${PROJECT_NAME}.elf PRIVATE ${srcf})
endforeach()
endif()
