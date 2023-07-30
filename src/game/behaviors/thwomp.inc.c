// thwomp.inc.c

void grindel_thwomp_act_on_ground(void) {
    if (o->oTimer == 0) {
        o->oThwompRandomTimer = random_float() * 10.0f + 20.0f;
    }
    if (o->oTimer > o->oThwompRandomTimer) {
        o->oAction = GRINDEL_THWOMP_ACT_RISING;
    }
}

void grindel_thwomp_act_falling(void) {
    o->oVelY += -4.0f;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oVelY = 0.0f;
        o->oAction = GRINDEL_THWOMP_ACT_LAND;
    }
}

void grindel_thwomp_act_land(void) {
    if (o->oTimer == 0 && o->oDistanceToMario < 1500.0f) {
        cur_obj_shake_screen(SHAKE_POS_SMALL);
        cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
        // cur_obj_play_sound_2(SOUND_GENERAL_OINK);
    }
    if (o->oTimer >= 10) {
        o->oAction = GRINDEL_THWOMP_ACT_ON_GROUND;
    }
}

void grindel_thwomp_act_floating(void) {
    o->oAction = GRINDEL_THWOMP_ACT_FALLING;
    if (o->oTimer == 0) {
        o->oThwompRandomTimer = random_float() * 30.0f + 10.0f;
    }
    if (o->oTimer > o->oThwompRandomTimer) {
        o->oAction = GRINDEL_THWOMP_ACT_FALLING;
    }
}

void grindel_thwomp_act_rising(void) {
    if (o->oBehParams2ndByte + 20 < o->oTimer) {
        o->oAction = GRINDEL_THWOMP_ACT_FLOATING;
        o->oPosY += 5.0f;
    } else {
        o->oPosY += 10.0f;
    }
}

ObjActionFunc sGrindelThwompActions[] = {
    grindel_thwomp_act_rising,
    grindel_thwomp_act_floating,
    grindel_thwomp_act_falling,
    grindel_thwomp_act_land,
    grindel_thwomp_act_on_ground
};

void bhv_grindel_thwomp_loop(void) {
    cur_obj_call_action_function(sGrindelThwompActions);
}

void grindel_fast_thwomp_act_falling(void) {
    o->oVelY += -15.0f;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oVelY = 0.0f;
    }
}

u8 reading = 0;
struct Object *thwomp;

void bhv_message_panel_interaction(void) {

    if(o->oTimer == 0){
        thwomp = spawn_object(o, MODEL_THWOMP, bhvThwomp3);
        thwomp->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }

    if(gMarioStates[0].action == ACT_READING_SIGN && dist_between_objects(gMarioObject, o) <= 110.0f){
        thwomp->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        thwomp->oVelY += -15.0f;
        thwomp->oPosY += thwomp->oVelY;
        if (thwomp->oPosY < thwomp->oHomeY) {
            thwomp->oPosY = thwomp->oHomeY;
            thwomp->oVelY = 0.0f;
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
            gMarioStates[0].healCounter = 0;
            gMarioStates[0].hurtCounter = 100;
        }
    }
}