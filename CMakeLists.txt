cmake_minimum_required(VERSION 2.8)
project( videocapture_gstreamer_pipeline )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( videocapture_gstreamer_pipeline src/videocapture_gstreamer_pipeline.cpp )
target_link_libraries( videocapture_gstreamer_pipeline ${OpenCV_LIBS} )
