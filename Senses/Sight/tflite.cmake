set(TFLITE_INC
        /home/thom/Development/Robotics/Arbie/OS/SourceCode/Arbie/Libraries/tensorflow
        /home/thom/Development/Robotics/Arbie/OS/SourceCode/Arbie/Libraries/tensorflow_deps/abseil-cpp
        /home/thom/Development/Robotics/Arbie/OS/SourceCode/Arbie/Libraries/tensorflow_deps/flatbuffers/include
)

set(TFLITE_LIB /home/thom/Development/Robotics/Arbie/OS/SourceCode/Arbie/Libraries/tensorflow_prebuilt/lib/libtensorflowlite.so)


file(COPY ${TFLITE_LIB} DESTINATION ${CMAKE_BINARY_DIR})


