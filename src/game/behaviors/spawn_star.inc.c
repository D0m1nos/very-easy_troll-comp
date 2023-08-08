// spawn_star.inc.c

#include "include/seq_ids.h"
#include "levels/wf/header.inc.h"
#include "game/print.h"

struct sPuppySpline splineCutsceneCamera[] = {
    {{ 477, 45, 31 }, 0, 20 },
    {{ 477, 45, 31 }, 1, 20 },
    {{ 477, 129, 31 }, 2, 20 },
    {{ 530, 553, -3 }, 3, 20 },
    {{ 773, 1214, -128 }, 4, 40 },
    {{ 3331, 1248, -1181 }, 5, 100 },
    {{ -635, 1099, 1936 }, 6, 10 },
    {{ 2761, 1253, 199 }, 7, 100 },
    {{ 2175, 1282, -392 }, 8, 10 },
    {{ 1185, 1183, -531 }, 9, 25 },
    {{ 601, 1315, 483 }, 10, 20 },
    {{ 879, 1313, 597 }, 11, 25 },
    {{ 1070, 1313, 638 }, 12, 20 },
    {{ 1319, 1313, 692 }, 13, 10 },
    {{ 1629, 1313, 628 }, 14, 10 },
    {{ 1844, 1313, 514 }, 15, 10 },
    {{ 1918, 1313, 463 }, 16, 10 },
    {{ 1976, 1313, 409 }, 17, 10 },
    {{ 2032, 1313, 344 }, 18, 10 },
    {{ 2084, 1313, 257 }, 19, 10 },
    {{ 2093, 1313, 130 }, 20, 10 },
    {{ 2031, 1313, 28 }, 21, 10 },
    {{ 2224, 1313, -114 }, 22, 10 },
    {{ 2367, 1313, -194 }, 23, 10 },
    {{ 2634, 1301, -329 }, 24, 10 },
    {{ 2687, 742, -354 }, -1, 10 },
};

struct sPuppySpline splineCutsceneFocus[] = {
    {{ 717, -1, 51 }, 0, 20 },
    {{ 717, -1, 51 }, 1, 20 },
    {{ 717, 303, 51 }, 2, 20 },
    {{ 758, 758, 25 }, 3, 20 },
    {{ 944, 1143, -71 }, 4, 40 },
    {{ 2906, 1170, -879 }, 5, 100 },
    {{ -136, 1055, 1512 }, 6, 10 },
    {{ 2469, 1174, 179 }, 7, 100 },
    {{ 2019, 1196, -274 }, 8, 10 },
    {{ 1260, 1120, -381 }, 9, 25 },
    {{ 812, 1221, 397 }, 10, 20 },
    {{ 1025, 1219, 484 }, 11, 25 },
    {{ 1328, 1219, 530 }, 12, 20 },
    {{ 1467, 1219, 522 }, 13, 10 },
    {{ 1574, 1219, 501 }, 14, 10 },
    {{ 1665, 1219, 472 }, 15, 10 },
    {{ 1726, 1219, 443 }, 16, 10 },
    {{ 1791, 1219, 394 }, 17, 10 },
    {{ 1853, 1219, 333 }, 18, 10 },
    {{ 1876, 1219, 268 }, 19, 10 },
    {{ 1886, 1219, 191 }, 20, 10 },
    {{ 1859, 1219, 78 }, 21, 10 },
    {{ 1797, 1219, 144 }, 22, 10 },
    {{ 1719, 1219, 201 }, 23, 10 },
    {{ 1621, 1219, 245 }, 24, 10 },
    {{ 1594, 932, 254 }, -1, 10 },
};


static struct ObjectHitbox sCollectStarHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

f32 maxHeight = 1050.0f;
u8 groundPoundState = 0;
u8 spinVel = 0;
u8 roundDone = 0;
u8 starGone = 0;
u32 tempTimer = 0;
u8 actuallyStarted = 0;
u8 skipped = 0;

void bhv_collect_star_init(void) {
    
    o->oAction = 0;
    maxHeight = 1050.0f;
    groundPoundState = 0;
    spinVel = 0;
    roundDone = 0;
    starGone = 0;
    tempTimer = 0;
    actuallyStarted = 0;
    skipped = 0;
    cur_obj_become_intangible();

    s8 starId = GET_BPARAM1(o->oBehParams);
#ifdef GLOBAL_STAR_IDS
    u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(starId / 7));
    if (currentLevelStarFlags & (1 << (starId % 7))) {
#else
    u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
    if (currentLevelStarFlags & (1 << starId)) {
#endif
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TRANSPARENT_STAR];
    } else {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_STAR];
    }

    obj_set_hitbox(o, &sCollectStarHitbox);
}

void bhv_collect_star_loop(void) {
    o->oFaceAngleYaw += 0x800;
    cur_obj_become_intangible();

    if(dist_between_objects(o, gMarioObject) <= 300.0f){
        starGone = 1;
    }

    if(starGone == 1){
        o->oPosY -= 40.0f;
        if(o->oPosY <= 400.0f){
            o->oPosY = 400.0f;
        }
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

ObjActionFunc sStarBossActions[] = {
    bhv_star_boss_idle,
    bhv_star_boss_starting,
    bhv_star_boss_flame_rain,
    bhv_star_boss_ground_pound,
    bhv_star_boss_duplication
};

void bhv_collect_star_boss_loop(void) {
    if(roundDone == 0){
        cur_obj_become_intangible();
        gMarioStates[0].challengeRound = 7;
    } else {
        cur_obj_become_tangible();
        gMarioStates[0].challengeRound = 8;
    }

    if(o->oPosY > maxHeight){
        o->oPosY = maxHeight;
    }

    cur_obj_call_action_function(sStarBossActions);

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

void bhv_star_boss_idle(void) {
    o->oHomeY = 5.0f;

    o->oFaceAngleYaw += 0x800;

    if(lateral_dist_between_objects(o, gMarioObject) <= 500.0f){
        starGone = 1;
    }

    if(starGone == 1) {
        o->oAction = 1;
    }

}

s32 boss_cutscene(void) {
    if(gMarioStates[0].canSkip == 1){
        print_text(120, 20, "PRESS A TO SKIP");
        if(gPlayer1Controller->buttonPressed & A_BUTTON){
            skipped = 1;
            return TRUE;
        }
    }
    return puppycam_move_spline(splineCutsceneCamera, splineCutsceneFocus, PUPPYSPLINE_FOLLOW, 0);
}



void bhv_star_boss_starting(void) {

    set_mario_action(&gMarioStates[0], ACT_READING_NPC_DIALOG, 0);

    if(o->oTimer == 0){
        gMarioStates[0].pos[1] = 20.0f;
        puppycam_activate_cutscene(&boss_cutscene, 1);
        stop_background_music(SEQUENCE_ARGS(4, SEQ_SAND_CANYON));
        o->oFaceAngleYaw = 16000;
    }

    if(skipped == 1){
        skipped = 0;
        o->oPosY = maxHeight;
        o->oAction = 2;
    }


    if(o->oPosY != maxHeight){
        o->oPosY += 20.0f;
        if(o->oPosY >= maxHeight){
            o->oPosY = maxHeight;
            spinVel = 0;
        }
    } else {
        o->oFaceAngleYaw += 733 * spinVel; // 11000 max
    
        if(o->oTimer % (30-(spinVel*1)) == 0 && spinVel < 15){
            play_sound(SOUND_OBJ_BOWSER_SPINNING, gGlobalSoundSource);
            spinVel++;
        }

        if(spinVel == 15){
            if(tempTimer == 0){
                tempTimer = o->oTimer;
            }
            if(o->oTimer - tempTimer == 150){
                o->oAction = 2;
            } else { 
                o->oFaceAngleYaw += 1000;
                if(o->oTimer - tempTimer == 30){
                    cur_obj_shake_screen(SHAKE_POS_SMALL);
                }
                if(o->oTimer - tempTimer == 60){
                    cur_obj_play_sound_2(SOUND_OBJ_BOWSER_LAUGH);
                }
            }
        }
    }
}

void bhv_star_boss_flame_rain(void) {
    f32 randomPosX, randomPosZ;
    u8 i;
    struct Object *enemy;
    ModelID16 model;

    if(actuallyStarted == 1 && o->oTimer == 0){
        spawn_object(o, MODEL_NONE, bhvThreeCoinsSpawn);
    }

    if(actuallyStarted == 0){
        actuallyStarted = 1;
        gMarioStates[0].canSkip = 1;
        spawn_object(gMarioObject, MODEL_NONE, bhvChallengeArena);
        set_mario_action(&gMarioStates[0], ACT_IDLE, 0);
    }
    
    if(o->oTimer > 30){
        o->oFaceAngleYaw += 3000;
        // z: -1600 -> 2300 | x: -500 -> 3500
        if(o->oTimer % 10 == 0){
            for (i = 0; i < 20; i++) {
                randomPosX = random_float() * 3500.0f - 400.0f; 
                randomPosZ = random_float() * 3600.0f - 1500.0f; 

                if(i % 2 == 0){
                    model = MODEL_BLUE_FLAME;
                } else {
                    model = MODEL_RED_FLAME;
                }
                enemy = spawn_object(o, model, bhvFlameGravity);
                
                enemy->oPosX = randomPosX;
                enemy->oPosY = o->oPosY+50.0f;
                enemy->oPosZ = randomPosZ;
            }
        }
    }

    if(o->oTimer > (30*10)){
        groundPoundState = 0;
        o->oAction = 3;
    }
}

void spawn_circle_flame(s32 offset, f32 bounciness) {
    u8 i;
    struct Object *flame;

    for(i = 0; i < 40; i++){
        flame = spawn_object(o, MODEL_RED_FLAME_SHADOW, bhvFlameBouncingCustom);
        flame->oMoveAngleYaw = (2048 * i) + offset;
        flame->oBounciness = bounciness;
        // flame->oBounciness = (random_float()*-1) - 1.2f;
        obj_scale(flame, 7.0f);
    }
}

void bhv_star_boss_ground_pound(void) {

    o->oFaceAngleYaw += 0x800;

    if(o->oTimer > 30) {
        switch(groundPoundState){
            case 0:
                //down
                o->oVelY += -20.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY < o->oHomeY) {
                    o->oPosY = o->oHomeY;
                    o->oVelY = 0.0f;
                    cur_obj_shake_screen(SHAKE_POS_SMALL);
                    cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
                    spawn_circle_flame(0, -1.8f);
                    groundPoundState++;
                }
                break;
            case 1:
                //up
                o->oVelY += +10.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY > maxHeight) {
                    o->oPosY = maxHeight;
                    o->oVelY = 0.0f;
                    groundPoundState++;
                }
                break;
            case 2:
                //down
                o->oVelY += -30.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY < o->oHomeY) {
                    o->oPosY = o->oHomeY;
                    o->oVelY = 0.0f;
                    cur_obj_shake_screen(SHAKE_POS_SMALL);
                    cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
                    spawn_circle_flame(1024, -1.8f);
                    groundPoundState++;
                }
                break;
            case 3:
                //up
                o->oVelY += +15.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY > maxHeight) {
                    o->oPosY = maxHeight;
                    o->oVelY = 0.0f;
                    groundPoundState++;
                }
                break;
            case 4:
                //down
                o->oVelY += -40.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY < o->oHomeY) {
                    o->oPosY = o->oHomeY;
                    o->oVelY = 0.0f;
                    cur_obj_shake_screen(SHAKE_POS_SMALL);
                    cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
                    spawn_circle_flame(0, -2.0f);
                    groundPoundState++;
                }
                break;
            case 5:
                //up
                o->oVelY += +20.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY > maxHeight) {
                    o->oPosY = maxHeight;
                    o->oVelY = 0.0f;
                    groundPoundState++;
                }
                break;
            case 6:
                o->oAction = 4;
                break;
        }
    }
}

void bhv_star_boss_duplication(void) {
    u8 i;
    struct Object *amp;

    o->oFaceAngleYaw += 0x800;

    if(o->oTimer == 75) {
        for (i = 0; i < 14; i++) {
            amp = spawn_object(o, MODEL_STAR, bhvCirclingAmp);
            amp->oBehParams2ndByte = i+4;
        }
        for (i = 0; i < 14; i++) {
            amp = spawn_object(o, MODEL_STAR, bhvCirclingAmp);
            amp->oBehParams2ndByte = i+4;
            amp->oMoveAngleYaw += 32000;
        }
        for (i = 0; i < 14; i++) {
            amp = spawn_object(o, MODEL_STAR, bhvCirclingAmp);
            amp->oBehParams2ndByte = i+4;
            amp->oMoveAngleYaw += 16000;
        }
        for (i = 0; i < 14; i++) {
            amp = spawn_object(o, MODEL_STAR, bhvCirclingAmp);
            amp->oBehParams2ndByte = i+4;
            amp->oMoveAngleYaw += 48000;
        }
    }

    if(o->oTimer > 360){
        spinVel = 0;
        
        if(maxHeight > 150.0f){
            maxHeight -= 150.0f;
        } else {
            maxHeight = 150.0f;
        }

        if(roundDone == 0) {
            roundDone = 1;
            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
        }

        o->oAction = 2;
    }
}

void bhv_star_spawn_init(void) {
    s16 yaw;
    vec3f_get_lateral_dist_and_yaw(&o->oPosVec, &o->oHomeVec, &o->oStarSpawnDisFromHome, &yaw);
    o->oMoveAngleYaw = yaw;
    o->oVelY = (o->oHomeY - o->oPosY) / 30.0f;
    o->oForwardVel = o->oStarSpawnDisFromHome / 30.0f;
    o->oStarSpawnVelY = o->oPosY;

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
    if (o->oBehParams2ndByte == SPAWN_STAR_ARC_CUTSCENE_BP_DEFAULT_STAR || gCurrCourseNum == COURSE_BBH) {
#else
    if (o->oBehParams2ndByte == SPAWN_STAR_ARC_CUTSCENE_BP_DEFAULT_STAR) {
#endif
        cutscene_object(CUTSCENE_STAR_SPAWN, o);
    } else {
        cutscene_object(CUTSCENE_RED_COIN_STAR_SPAWN, o);
    }

    set_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
    cur_obj_become_intangible();
}

void bhv_star_spawn_loop(void) {
    switch (o->oAction) {
        case SPAWN_STAR_ARC_CUTSCENE_ACT_START:
            o->oFaceAngleYaw += 0x1000;
            if (o->oTimer > 20) {
                o->oAction = SPAWN_STAR_ARC_CUTSCENE_ACT_GO_TO_HOME;
            }
            break;

        case SPAWN_STAR_ARC_CUTSCENE_ACT_GO_TO_HOME:
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oStarSpawnVelY += o->oVelY;
            o->oPosY = o->oStarSpawnVelY + sins((o->oTimer * 0x8000) / 30) * 400.0f;
            o->oFaceAngleYaw += 0x1000;
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            cur_obj_play_sound_1(SOUND_ENV_STAR);
            if (o->oTimer == 29) {
                o->oAction = SPAWN_STAR_ARC_CUTSCENE_ACT_BOUNCE;
                o->oForwardVel = 0;
                // Set to exact home coordinates
                vec3f_copy(&o->oPosVec, &o->oHomeVec);
                play_power_star_jingle();
            }
            break;

        case SPAWN_STAR_ARC_CUTSCENE_ACT_BOUNCE:
            if (o->oTimer < 20) {
                o->oVelY = 20 - o->oTimer;
            } else {
                o->oVelY = -10.0f;
            }

            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oFaceAngleYaw = o->oFaceAngleYaw - o->oTimer * 0x10 + 0x1000;
            cur_obj_play_sound_1(SOUND_ENV_STAR);

            if (o->oPosY < o->oHomeY) {
                cur_obj_play_sound_2(SOUND_GENERAL_STAR_APPEARS);
                cur_obj_become_tangible();
                o->oPosY = o->oHomeY;
                o->oAction = SPAWN_STAR_ARC_CUTSCENE_ACT_END;
            }
            break;

        case SPAWN_STAR_ARC_CUTSCENE_ACT_END:
            o->oFaceAngleYaw += 0x800;
            if (o->oTimer == 20) {
                gObjCutsceneDone = TRUE;
                clear_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                obj_mark_for_deletion(o);
                o->oInteractStatus = INT_STATUS_NONE;
            }
            break;
    }
}

struct Object *spawn_star(struct Object *starObj, f32 x, f32 y, f32 z) {
    starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStarSpawnCoordinates, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
    starObj->oBehParams = o->oBehParams;
    vec3f_set(&starObj->oHomeVec, x, y, z);
    starObj->oFaceAnglePitch = 0;
    starObj->oFaceAngleRoll = 0;
    return starObj;
}

void spawn_default_star(f32 x, f32 y, f32 z) {
    struct Object *starObj = NULL;
    starObj = spawn_star(starObj, x, y, z);
    starObj->oBehParams2ndByte = SPAWN_STAR_ARC_CUTSCENE_BP_DEFAULT_STAR;
}

void spawn_red_coin_cutscene_star(f32 x, f32 y, f32 z) {
    struct Object *starObj = NULL;
    starObj = spawn_star(starObj, x, y, z);
    starObj->oBehParams2ndByte = SPAWN_STAR_ARC_CUTSCENE_BP_HIDDEN_STAR;
}

void spawn_no_exit_star(f32 x, f32 y, f32 z) {
    struct Object *starObj = NULL;
    starObj = spawn_star(starObj, x, y, z);
    starObj->oBehParams2ndByte = SPAWN_STAR_ARC_CUTSCENE_BP_HIDDEN_STAR;
    starObj->oInteractionSubtype |= INT_SUBTYPE_NO_EXIT;
}

void bhv_hidden_red_coin_star_init(void) {
    struct Object *starObj = NULL;

    if (gCurrCourseNum != COURSE_JRB) {
        spawn_object(o, MODEL_TRANSPARENT_STAR, bhvRedCoinStarMarker);
    }

    s16 numRedCoinsRemaining = count_objects_with_behavior(bhvRedCoin);
    if (numRedCoinsRemaining == 0) {
        starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        starObj->oBehParams = o->oBehParams;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    o->oHiddenStarTriggerCounter = 8 - numRedCoinsRemaining;
}

void bhv_hidden_red_coin_star_loop(void) {
    gRedCoinsCollected = o->oHiddenStarTriggerCounter;

    switch (o->oAction) {
        case HIDDEN_STAR_ACT_INACTIVE:
            if (o->oHiddenStarTriggerCounter == 8) {
                o->oAction = HIDDEN_STAR_ACT_ACTIVE;
            }
            break;

        case HIDDEN_STAR_ACT_ACTIVE:
            if (o->oTimer > 2) {
                spawn_red_coin_cutscene_star(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}


void bhv_font_test(void){
    print_text(20,200, "0123456789");
    print_text(20,180, "ABCDEFGHIJKLM");
    print_text(20,160, "NOPQRSTUVWXYZ");
    print_text(20,140, "--- /// ??? !!!");
    print_text(20,120, "& %% : ; ' ");
}