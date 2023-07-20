void bhv_quicksand_transporter_push_back(void){

    // set mario to idle state every frame to prevent escape
    set_mario_action(&gMarioStates[0], ACT_IDLE, 0);

    if(o->oTimer == 0){ // first frame -> raise mario 100.0f, make him face forwards
        gMarioStates[0].pos[1] += 100.0f;
        gMarioStates[0].faceAngle[0] = 0;
        gMarioStates[0].faceAngle[1] = 16384;
        gMarioStates[0].faceAngle[2] = 0;
    } else if(o->oTimer <= 120){ // push mario back for 4 seconds
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

    

    // char ax[30], ay[30], az[30];
    // sprintf(ax, "%d", gMarioStates[0].faceAngle[0]);
    // print_text(50, 80, ax);
    // sprintf(ay, "%d", gMarioStates[0].faceAngle[1]);
    // print_text(50, 60, ay);
    // sprintf(az, "%d", gMarioStates[0].faceAngle[2]);
    // print_text(50, 40, az);
    
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
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            // obj_mark_for_deletion(o);
            break;
    }

    
}