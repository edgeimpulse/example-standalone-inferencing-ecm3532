if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/../../m3/csp/src")
    target_include_directories(csp PUBLIC "${CMAKE_CURRENT_LIST_DIR}/inc")
else ()
    include_directories("${CMAKE_CURRENT_LIST_DIR}/inc")
endif ()
