cmake_minimum_required(VERSION 3.4.1)

set( ROOT "${CMAKE_SOURCE_DIR}/../.." )
set( PROJECT_ROOT "${ROOT}/SDK" )
set( SUPPORT_LIB_ROOT "${ROOT}/SDK/support-lib" )

file( GLOB JNI_CODE "${PROJECT_ROOT}/cpp/androidGen/*.cpp" "${PROJECT_ROOT}/cpp/androidGen/*.hpp" )
file( GLOB PROJECT_CODE "${PROJECT_ROOT}/cpp/gen/*.cpp" "${PROJECT_ROOT}/cpp/impl/*.cpp" "${PROJECT_ROOT}/cpp/callback/*.cpp" )
file( GLOB PROJECT_HEADERS "${PROJECT_ROOT}/cpp/gen/*.hpp" "${PROJECT_ROOT}/cpp/impl/*.h" "${PROJECT_ROOT}/cpp/callback/*.h" )
file( GLOB YIM_HEADERS "${PROJECT_ROOT}/yim/include/*.h")

file( GLOB DJINNI_CODE "${SUPPORT_LIB_ROOT}/cpp/*.cpp" "${SUPPORT_LIB_ROOT}/jni/*.cpp" )
file( GLOB DJINNI_HEADERS "${SUPPORT_LIB_ROOT}/cpp/*.hpp" "${SUPPORT_LIB_ROOT}/jni/*.hpp" )

include_directories(
    "${SUPPORT_LIB_ROOT}/cpp"
    "${SUPPORT_LIB_ROOT}/jni"
    "${PROJECT_ROOT}/cpp"
    "${PROJECT_ROOT}/cpp/gen"
    "${PROJECT_ROOT}/cpp/impl"
    "${PROJECT_ROOT}/cpp/callback"
    "${PROJECT_ROOT}/yim/include"
    )

add_library( # Sets the name of the library.
             yimrn-lib

             # Sets the library as a shared library.
             SHARED

             ${YIM_HEADERS}
             ${JNI_CODE}
             ${DJINNI_CODE}
             ${DJINNI_HEADERS}
             ${PROJECT_CODE}
             ${PROJECT_HEADERS} )

add_library( yim
             SHARED
             IMPORTED )

set_target_properties(yim
                       PROPERTIES IMPORTED_LOCATION
                       ${PROJECT_ROOT}/yim/lib/android/${ANDROID_ABI}/libyim.so )

#add_library( msc
#             SHARED
#             IMPORTED )
#
#set_target_properties(msc
#                       PROPERTIES IMPORTED_LOCATION
#                       ${PROJECT_ROOT}/yim/lib/android/${ANDROID_ABI}/libmsc.so )

add_library( youme_voice_engine
             SHARED
             IMPORTED )

set_target_properties(youme_voice_engine
                       PROPERTIES IMPORTED_LOCATION
                       ${PROJECT_ROOT}/yim/lib/android/${ANDROID_ABI}/libyoume_voice_engine.so )

#add_library( nlscppsdk
#             SHARED
#             IMPORTED )
#
#set_target_properties(nlscppsdk
#                       PROPERTIES IMPORTED_LOCATION
#                       ${PROJECT_ROOT}/yim/lib/android/${ANDROID_ABI}/libnlscppsdk.so )

#add_library( uscasr
#             SHARED
#             IMPORTED )
#
#set_target_properties(uscasr
#                       PROPERTIES IMPORTED_LOCATION
#                       ${PROJECT_ROOT}/yim/lib/android/${ANDROID_ABI}/libuscasr.so )

#add_library( aliuuid
#             SHARED
#             IMPORTED )
#
#set_target_properties(aliuuid
#                       PROPERTIES IMPORTED_LOCATION
#                       ${PROJECT_ROOT}/yim/lib/android/${ANDROID_ABI}/libuuid.so )

#target_link_libraries( yimrn-lib yim youme_voice_engine nlscppsdk aliuuid)

target_link_libraries( yimrn-lib yim youme_voice_engine)
