// metal_box.inc.c

struct ObjectHitbox sMetalBoxHitbox = {
    /* interactType:      */ INTERACT_NONE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 220,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 220,
    /* hurtboxHeight:     */ 300,
};

int elevatorTimer = 0;

s32 check_if_moving_over_floor(f32 maxDist, f32 offset) {
    struct Surface *floor;
    f32 xPos = o->oPosX + sins(o->oMoveAngleYaw) * offset;
    f32 zPos = o->oPosZ + coss(o->oMoveAngleYaw) * offset;

    f32 floorHeight = find_floor(xPos, o->oPosY, zPos, &floor);

    return (absf(floorHeight - o->oPosY) < maxDist);
}

void bhv_pushable_loop(void) {
    obj_set_hitbox(o, &sMetalBoxHitbox);
    o->oForwardVel = 0.0f;

    if (obj_check_if_collided_with_object(o, gMarioObject) && gMarioStates[0].flags & MARIO_PUSHING) {
        s16 angleToMario = obj_angle_to_object(o, gMarioObject);
        if (abs_angle_diff(angleToMario, gMarioObject->oMoveAngleYaw) > 0x4000) {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if (check_if_moving_over_floor(8.0f, 150.0f)) {
                o->oForwardVel = 4.0f;
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
            }
        }
    }

    cur_obj_move_using_fvel_and_gravity();
}

void bhv_pushable_elevator_loop(void) {
    obj_set_hitbox(o, &sMetalBoxHitbox);

    // METAL_BOX_NULL,
    // METAL_BOX_MARIO_ON_TOP,
    // METAL_BOX_GOING_UP,
    // METAL_BOX_STOP

    switch(o->oAction){
        case METAL_BOX_NULL:
            if (gMarioObject->platform == o) {
                o->oAction = METAL_BOX_MARIO_ON_TOP;
                elevatorTimer = 0;
            }
            break;
        case METAL_BOX_MARIO_ON_TOP:
            elevatorTimer++;
            if(elevatorTimer >= 60){
                o->oAction = METAL_BOX_GOING_UP;
            }
            break;
        case METAL_BOX_GOING_UP:
            // 768 -> 2140 -- 1372
            o->oVelY = 10.0f;
            o->oPosY += o->oVelY;
            if(o->oPosY >= 1850.0f){
                o->oPosY = 1850.0f;
                o->oAction = METAL_BOX_STOP;
            }
            break;
        case METAL_BOX_STOP:
            o->oVelY = 0.0f;
            o->oPosY = 1850.0f;
            break;
    }
}

f32 xposition;

void bhv_pushable_child_loop(void){
    obj_set_hitbox(o, &sMetalBoxHitbox);

    if(obj_check_if_collided_with_object(o->parentObj, gMarioObject) == 1){
        o->oPosX = xposition + 400.0f;
    }
}

void bhv_pushable_child_init(void){
    obj_set_hitbox(o, &sMetalBoxHitbox);
    
    o->oPosY -= (o->oBehParams2ndByte * 10.0f);
    xposition = o->oPosX;
}
