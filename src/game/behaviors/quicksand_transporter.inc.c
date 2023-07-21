char text[30];
u8 soundPlayed = 0;

void bhv_quicksand_transporter_push_back(void){
    
    // set mario to idle state every frame to prevent escape
    set_mario_action(&gMarioStates[0], ACT_IDLE, 0);

    if(o->oTimer == 0){ // first frame -> raise mario, make him face forwards
        gMarioStates[0].pos[1] += 250.0f;
        gMarioStates[0].faceAngle[0] = 0;
        gMarioStates[0].faceAngle[1] = 16384;
        gMarioStates[0].faceAngle[2] = 0;
    } else if(o->oTimer <= (30 * 3)){
        gMarioStates[0].vel[0] = 0.0f;
        gMarioStates[0].vel[1] = 0.0f;
        gMarioStates[0].vel[2] = 0.0f;
        gMarioStates[0].forwardVel = 0.0f;

        if(o->oTimer%30==0){
            sprintf(text, "%d", 4-(o->oTimer/30));
            //TODO: play sound clock ticking
            play_sound(SOUND_GENERAL_BIG_CLOCK, gGlobalSoundSource);
            //TODO: play sound mario screaming
        }

        print_text(220,110,text);
    } else if(o->oTimer <= (30 * 8)){ // push mario back for 4 seconds
        if(soundPlayed == 0){
            play_sound(SOUND_GENERAL_SCREAM, gGlobalSoundSource);
            soundPlayed = 1;
        }
        gMarioStates[0].vel[0] = -50.0f;
        gMarioStates[0].vel[1] = 0.0f;
        gMarioStates[0].vel[2] = 0.0f;
        gMarioStates[0].forwardVel = -50.0f;
        gMarioStates[0].pos[0] -= 50.0f;
    } else {
        o->oAction = QUICKSAND_TRANSPORTER_PUSH_DOWN;
    }

    // char text[30];
    // sprintf(text, "%f", gMarioStates[0].pos[1]);
    // print_text(50, 50, text);
}

void bhv_quicksand_transporter_push_down(void){

    // set mario to idle state every frame to prevent escape
    set_mario_action(&gMarioStates[0], ACT_IDLE, 0);

    if(o->oTimer <= 60){ // push mario down for 2 seconds
        gMarioStates[0].vel[0] = 0.0f;
        gMarioStates[0].vel[1] = -20.0f;
        gMarioStates[0].vel[2] = 0.0f;
        gMarioStates[0].pos[1] -= 20.0f;
    } else {
        o->oAction = QUICKSAND_TRANSPORTER_END;
    }
    
}

void bhv_quicksand_transporter_init(void){
    o->oAction = QUICKSAND_TRANSPORTER_NULL;
}

void bhv_quicksand_transporter_loop(void){

    switch(o->oAction){
        case QUICKSAND_TRANSPORTER_NULL:
            if (obj_check_if_collided_with_object(o, gMarioObject) == 1){
                // play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
                o->oAction = QUICKSAND_TRANSPORTER_PUSH_BACK;
            }
            break;
        case QUICKSAND_TRANSPORTER_PUSH_BACK:
            bhv_quicksand_transporter_push_back();
            break;
        case QUICKSAND_TRANSPORTER_PUSH_DOWN:
            bhv_quicksand_transporter_push_down();
            break;
        case QUICKSAND_TRANSPORTER_END:
            // o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            o->oAction = QUICKSAND_TRANSPORTER_NULL;
            // obj_mark_for_deletion(o);
            break;
    }

    
}