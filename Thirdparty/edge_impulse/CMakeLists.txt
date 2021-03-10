file(GLOB EI_SDK "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/*.c")





file(GLOB TF "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/micro/*.cc"
             "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/*.cc"
             "${CMAKE_CURRENT_LIST_DIR}/tflite-model/*.cpp")
file(GLOB TFKERNEL "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/micro/kernels/*.cc")
file(GLOB TFCORE "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/core/api/*.cc")
file(GLOB TFCOMMON "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/c/*.c")
file(GLOB TFINTERNAL "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/kernels/internal/*.cc"
                     "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/kernels/*.cc")
file(GLOB EIPORT "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/porting/ecm3532/*.cpp")
file(GLOB DSP "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/dsp/kissfft/*.cpp"
              "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/dsp/dct/*.cpp")
file(GLOB CMSIS "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/*.c"
                "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/*.c"
                "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/*.c"
                "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/*.c"
                "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/*.c")
file(GLOB TENSAIMODEL "${CMAKE_CURRENT_LIST_DIR}/tensaiflow-model/*.c")


foreach (ei_sdk ${EI_SDK})
    target_sources(edgeimpulse PRIVATE ${ei_sdk})
endforeach()

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/porting")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/classifier")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/model-parameters")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/tflite-model")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/dsp")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/tensaiflow-model")

foreach (ei_tf ${TF})
    target_sources(edgeimpulse PRIVATE ${ei_tf})
endforeach()

foreach (ei_tfkernel ${TFKERNEL})
    target_sources(edgeimpulse PRIVATE ${ei_tfkernel})
endforeach()

foreach (ei_tfcore ${TFCORE})
    target_sources(edgeimpulse PRIVATE ${ei_tfcore})
endforeach()

foreach (ei_tfcommon ${TFCOMMON})
    target_sources(edgeimpulse PRIVATE ${ei_tfcommon})
endforeach()

foreach (ei_tfinternal ${TFINTERNAL})
    target_sources(edgeimpulse PRIVATE ${ei_tfinternal})
endforeach()

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/tensorflow/lite/micro")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/third_party/flatbuffers/include")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/third_party/gemmlowp")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/third_party/ruy")

foreach (ei_port ${EIPORT})
    target_sources(edgeimpulse PUBLIC ${ei_port})
endforeach()

foreach (ei_dsp ${DSP})
    target_sources(edgeimpulse PRIVATE ${ei_dsp})
endforeach()

target_include_directories(edgeimpulse PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/PrivateInclude")

target_include_directories(edgeimpulse PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/edge-impulse-sdk/CMSIS/DSP/Include")

foreach (ei_cmsis ${CMSIS})
    target_sources(edgeimpulse PRIVATE ${ei_cmsis})
endforeach()

foreach (ei_tensaimodel ${TENSAIMODEL})
    target_sources(edgeimpulse PUBLIC ${ei_tensaimodel})
endforeach()