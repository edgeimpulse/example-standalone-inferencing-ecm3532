    set (DOXYGEN_PROJECT_NAME "TENSAI\" \"Flow\" \"Platform\" \"SW\" \"API")
    set(DOXYGEN_PROJECT_NUMBER "${PKG_NAME}_${VERSION}")
    set( DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../../../../Docs/API/doxy")
    set (DOXYGEN_INPUT "index.md ../hw/hal/common/include ../hw/drivers/spi_flash/common/spi_flash.h ../hw/drivers/opt3001/eta_devices_opt3001.h ../hw/hal/${getsoc}/include ../../Common/sensor_mgr/inc/sal.h ../framework/serial_proto/include/serial_proto.h")
    set(DOXYGEN_DOXYFILE_ENCODING UTF-8)
    set(DOXYGEN_INPUT_ENCODING UTF-8)
    set(DOXYGEN_ALLOW_UNICODE_NAMES NO)
    set(DOXYGEN_IN "${PROJECT_BINARY_DIR}/CMakeDoxyfile.in")
    set(DOXYGEN_OUT "${PROJECT_BINARY_DIR}/Doxyfile")
    set(DOXYGEN_INDEX_FILE "${PROJECT_BINARY_DIR}/doc_doxygen/html/index.html")
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE index.md)
    set( DOXYGEN_FILE_PATTERNS *.h )
    set(DOXYGEN_EXCLUDE_PATTERNS */cmake/* */.git/* */.svn/* */.hg/* */CMakeFiles/* */_CPack_Packages/* DartConfiguration.tcl CMakeLists.txt CMakeCache.txt)
    set( DOXYGEN_COLLABORATION_GRAPH YES )
    set( DOXYGEN_EXTRACT_ALL YES )
    set( DOXYGEN_CLASS_DIAGRAMS YES )
    set( DOXYGEN_HIDE_UNDOC_RELATIONS YES )
    set( DOXYGEN_HAVE_DOT NO )
    set( DOXYGEN_CLASS_GRAPH YES )
    set( DOXYGEN_CALL_GRAPH YES )
    set( DOXYGEN_CALLER_GRAPH YES )
    #set(DOXYGEN_CREATE_SUBDIRS NO)
    set(DOXYGEN_SEPARATE_MEMBER_PAGES NO)
    set(DOXYGEN_TAB_SIZE 4)
    set( DOXYGEN_COLLABORATION_GRAPH YES )
    set( DOXYGEN_BUILTIN_STL_SUPPORT YES )
    set( DOXYGEN_EXTRACT_PRIVATE NO )
    set( DOXYGEN_EXTRACT_PACKAGE YES )
    set( DOXYGEN_EXTRACT_STATIC YES )
    set(DOXYGEN_MARKDOWN_SUPPORT YES)
    set(DOXYGEN_GENERATE_DOCSET NO)
    set(DOXYGEN_DISABLE_INDEX YES)
    set(DOXYGEN_MAN_LINKS NO)
    set( DOXYGEN_FULL_PATH_NAMES  YES )
    set(DOXYGEN_HTML_TIMESTAMP YES)
    #set (DOXYGEN_STRIP_FROM_PATH  ..)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set( DOXYGEN_SHORT_NAMES YES)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_EXAMPLE_RECURSIVE YES)
    set(DOXYGEN_VERBATIM_HEADERS NO)
    set( DOXYGEN_EXTRACT_LOCALMETHODS YES )
    set( DOXYGEN_UML_LOOK YES )
    set( DOXYGEN_UML_LIMIT_NUM_FIELDS 50 )
    set( DOXYGEN_TEMPLATE_RELATIONS YES )
    set( DOXYGEN_LATEX_HIDE_INDICES YES )
    set( DOXYGEN_DOT_GRAPH_MAX_NODES 100 )
    set( DOXYGEN_MAX_DOT_GRAPH_DEPTH 0 )
    set( DOXYGEN_DOT_TRANSPARENT YES )
    set( DOXYGEN_MACRO_EXPANSION NO )
    set ( DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES )
    set ( DOXYGEN_SHOW_INCLUDE_FILES NO)

    set (DOXYGEN_HTML_EXTRA_STYLESHEET ${CMAKE_CURRENT_LIST_DIR}/resources/css/custom.css)
    set (DOXYGEN_PROJECT_LOGO ${CMAKE_CURRENT_LIST_DIR}/resources/etacompute-logo_large.png)
    set(DOXYGEN_HTML_HEADER ${CMAKE_CURRENT_LIST_DIR}/resources/header.html)
    set(DOXYGEN_HTML_FOOTER ${CMAKE_CURRENT_LIST_DIR}/resources/footer.html)
    set( DOXYGEN_GENERATE_TREEVIEW YES)
	set(DOXYGEN_TREEVIEW_WIDTH 280)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    add_custom_command(
        OUTPUT ${DOXYGEN_INDEX_FILE}
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        DEPENDS ${DOXYGEN_OUT}
        COMMENT "Generating API documentation with Doxygen"
        )
    add_custom_target(doxy DEPENDS ${DOXYGEN_INDEX_FILE})
