// rotating_platform.inc.c

#include "levels/wf/header.h"
#include "levels/wdw/header.h"

struct WFRotatingPlatformData {
    s16 unused;
    s16 scale;
    const Collision *collisionData;
    s16 collisionDistance;
};

struct WFRotatingPlatformData sWFRotatingPlatformData[] = {
    { 0, 100, wf_seg7_collision_rotating_platform, 2000 },
    { 0, 150, wdw_seg7_collision_rotating_platform, 1000 }
};

void bhv_wf_rotating_wooden_platform_loop(void) {
    if (o->oAction == 0) {
        o->oAngleVelYaw = 0;
        if (o->oTimer > 60) {
            o->oAction++;
        }
    } else {
        o->oAngleVelYaw = 0x100;
        if (o->oTimer > 126) {
            o->oAction = ROTATING_PLATFORM_ACT_STOPPED;
        }
        cur_obj_play_sound_1(SOUND_ENV_ELEVATOR2);
    }
    cur_obj_rotate_face_angle_using_vel();
}

void bhv_rotating_platform_loop(void) {
    s8 speed = GET_BPARAM1(o->oBehParams);
    if (o->oTimer == 0) {
        obj_set_collision_data(o, sWFRotatingPlatformData[o->oBehParams2ndByte].collisionData);
        o->oCollisionDistance = sWFRotatingPlatformData[o->oBehParams2ndByte].collisionDistance;
        cur_obj_scale(sWFRotatingPlatformData[o->oBehParams2ndByte].scale * 0.01f);
    }
    
    o->oAngleVelYaw = speed << 4;
    if(dist_between_objects(o, gMarioObject) <= 375.0f){
        o->oFaceAngleYaw -= o->oAngleVelYaw;
    } else {
        o->oFaceAngleYaw += o->oAngleVelYaw;
    }
    
}

u8 rotating = 0;
// char test123[40], test124[40], test125[50];

void bhv_actually_rotating_platform_init(void) {
    rotating = 0;
}

void bhv_actually_rotating_platform_loop(void) {
    s8 speed = GET_BPARAM1(o->oBehParams);
    if (o->oTimer == 0) {
        obj_set_collision_data(o, sWFRotatingPlatformData[o->oBehParams2ndByte].collisionData);
        o->oCollisionDistance = sWFRotatingPlatformData[o->oBehParams2ndByte].collisionDistance;
        cur_obj_scale(sWFRotatingPlatformData[o->oBehParams2ndByte].scale * 0.01f);
    }
    o->oAngleVelYaw = speed << 4;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    if(dist_between_objects(o, gMarioObject) <= 300.0f){
        rotating = 1;
    }

    if(rotating == 1){
        o->oFaceAngleRoll += (o->oAngleVelYaw / 2);
    }

    if(o->oFaceAngleRoll >= 65000){
        rotating = 0;
        o->oFaceAngleRoll = 0;
    }

    // sprintf(test123, "%d", o->oFaceAngleRoll);
    // print_text(180,180,test123);
    // sprintf(test124, "%d", rotating);
    // print_text(180,160,test124);
    
}