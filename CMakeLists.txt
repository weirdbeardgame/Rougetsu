cmake_minimum_required(VERSION 3.28)
project(Rougetsu)

set(CMAKE_CXX_STANDARD 20)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#include(raylib)
include(glfw)
include(glad)
include(glm)

glad_add_library(glad_gl_core_mx_33 REPRODUCIBLE MX API gl:core=3.3)

add_executable(Rougetsu 
        main.cpp
        common/packfile.cpp
        
        # Graphics
        Graphics/graph3d/gra3dSGD.cpp
        Graphics/graph3d/sgd_types.h
        Graphics/graph3d/g3dDebug.cpp
        Graphics/graph3d/gra3d.cpp
        Graphics/graph3d/g3dCore.cpp
        Graphics/graph3d/gra3dDma.cpp
        Graphics/graph3d/gra3dShadow.cpp
        Graphics/graph3d/gra3dSGDData.cpp
        Graphics/graph3d/g3dUtil.h
        Graphics/obj_draw_ctrl.h
        utils.cpp
        utils.h
        sce/libvu0.cpp
        sce/libvu0.h
        Graphics/render/renderer.cpp
        Graphics/render/renderer.h
        Graphics/render/Vu1Mem.cpp
        Graphics/render/Vu1Mem.h
        Graphics/graph3d/g3d_types.h
        ingame/plyr/man_data.h
        ingame/plyr/plyr_mdl.h
        Graphics/motion/motion.h
        ingame/plyr/plyr_mdl.cpp
        Graphics/motion/motion.h
)

target_link_libraries(Rougetsu glad_gl_core_mx_33 glfw glm::glm)
