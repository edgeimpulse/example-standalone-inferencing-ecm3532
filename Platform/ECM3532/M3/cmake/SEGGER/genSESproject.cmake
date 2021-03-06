function (generate_ses_project TARGET_NAME)
    set(target_sources "")
    
    get_target_property(target_sources1 ${TARGET_NAME} SOURCES)
    set(target_sources "${target_sources1}")
    get_target_property(target_include_dirs1 ${TARGET_NAME} INCLUDE_DIRECTORIES)
    set(target_include_dirs "${target_include_dirs1}")

    if (TARGET csp)
        get_target_property(target_sources2 "csp" SOURCES)
        set(target_sources "${target_sources};${target_sources2}")
        get_target_property(target_include_dirs2 "csp" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs2}")
    endif()
    if (TARGET freertos)
        get_target_property(target_sources3 "freertos" SOURCES)
        set(target_sources "${target_sources};${target_sources3}")
        get_target_property(target_include_dirs3 "freertos" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs3}")
    endif()
    if (TARGET hal)
        get_target_property(target_sources4 "hal" SOURCES)
        set(target_sources "${target_sources};${target_sources4}")
        get_target_property(target_include_dirs4 "hal" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs4}")
    endif()
    if (TARGET iodev)
        get_target_property(target_sources5 "iodev" SOURCES)
        set(target_sources "${target_sources};${target_sources5}")
        get_target_property(target_include_dirs5 "iodev" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs5}")
    endif()
    if (TARGET eta_nn_functions)
        get_target_property(target_sources6 "eta_nn_functions" SOURCES)
        set(target_sources "${target_sources};${target_sources6}")
        get_target_property(target_include_dirs6 "eta_nn_functions" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs6}")
    endif()
    if (TARGET executor)
        get_target_property(target_sources7 "executor" SOURCES)
        set(target_sources "${target_sources};${target_sources7}")
        get_target_property(target_include_dirs7 "executor" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs7}")
    endif()
    if (TARGET pm)
        get_target_property(target_sources8 "pm" SOURCES)
        set(target_sources "${target_sources};${target_sources8}")
        get_target_property(target_include_dirs8 "pm" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs8}")
    endif()
    if (TARGET rpc)
        get_target_property(target_sources9 "rpc" SOURCES)
        set(target_sources "${target_sources};${target_sources9}")
        get_target_property(target_include_dirs9 "rpc" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs9}")
    endif()
    if (TARGET sm)
        #message("sm enabled")
        get_target_property(target_sources10 "sm" SOURCES)
        set(target_sources "${target_sources};${target_sources10}")
        get_target_property(target_include_dirs10 "sm" INCLUDE_DIRECTORIES)
        set(target_include_dirs "${target_include_dirs};${target_include_dirs10}")
    endif()

    #message("target_sources ${target_sources}\n\n")
    #message("target_include_dirs ${target_include_dirs}\n\n")

    list(REMOVE_DUPLICATES target_sources)
    list(REMOVE_DUPLICATES target_include_dirs)

    if(EXISTS "${TesnsaiSDKDir}/soc/${getsoc}/m3/csp/src" OR
        EXISTS "${PROJ_DIR}/hw/csp/${getsoc}/m3/csp/src")
        #message("csp src present")
    else ()
        #message("csplib added")
        set(target_sources "${target_sources};${csplib}")
    endif()

    if(EXISTS "${PROJ_DIR}/../../../Thirdparty/FreeRTOS")
        #message("freertos src present")
    else ()
        #message("freertoslib added")
        set(target_sources "${target_sources};${freertoslib}")
    endif ()

    if(EXISTS "${PROJ_DIR}/hw/hal/${socname}/uart/src" OR
        EXISTS "${PROJ_DIR}/hw/hal/common/uart/src")
        #message("hal src present")
    else ()
        #message("hallib added")
        set(target_sources "${target_sources};${hallib}")
    endif ()

    if(EXISTS "${PROJ_DIR}/hw/drivers")
        #message("iodev src present")
    else ()
        #message("iodevlib added")
        set(target_sources "${target_sources};${iodevlib}")
    endif ()

if (TARGET rpc)
    if(EXISTS "${PROJ_DIR}/framework/rpc/src")
        #message("rpc src present")
    else ()
        #message("rpclib added")
        set(target_sources "${target_sources};${rpclib}")
    endif()
endif ()

if (TARGET pm)
    if(EXISTS "${PROJ_DIR}/hw/power/${socname}/src")
        #message("pm src present")
    else ()
        #message("pmlib added")
        set(target_sources "${target_sources};${pmlib}")
    endif ()
endif ()

if (TARGET executor)
    if(EXISTS "${PROJ_DIR}/framework/executor/src")
        #message("executor src present")
    else ()
        #message("executorlib added")
        set(target_sources "${target_sources};${executorlib}")
    endif ()

    if(EXISTS "${PROJ_DIR}/NN_Kernels/src")
        #message("nn src present")
    else ()
        #message("nn_lib added")
        set(target_sources "${target_sources};${nn_lib}")
    endif ()
endif()

if (TARGET sm)
    if(EXISTS "${PROJ_DIR}/framework/sensor_mgr/src")
        #message("sm src present")
    else ()
        #message("slib added")
        set(target_sources "${target_sources};${smlib}")
    endif ()
endif ()


    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.json
    "{
    \"target\": {
        \"name\": \"${TARGET_NAME}\",
        \"sources\": \"${target_sources}\",
        \"includes\": \"${target_include_dirs}\",
        \"defines\":\"\"
    }
}")

    execute_process(
        COMMAND ${Python_EXECUTABLE} ${PROJ_DIR}/cmake/SEGGER/genSESproject.py "${PROJ_DIR}/../../../Applications/${PROJECT_NAME}/build/${PROJECT_NAME}.elf.json" ${PROJ_DIR}/../../../Applications/${PROJECT_NAME}
        WORKING_DIRECTORY .
    )
    message("Inc path :: ${PROJECT_NAME}")
endfunction ()
