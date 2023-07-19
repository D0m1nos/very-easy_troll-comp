void bhv_challenge_start(f32 marioYPos){
    
    if(o->oTimer == 0){ //TODO: dividere in più state, cambiare questo in tipo quicksand transporter
        gMarioStates[0].pos[1] += 100.0f;
        gMarioStates[0].faceAngle[0] = 0;
        gMarioStates[0].faceAngle[1] = 16384;
        gMarioStates[0].faceAngle[2] = 0;
        set_mario_action(&gMarioStates[0], ACT_IDLE, 0);
    // } else if(o->oTimer <= 90){
    //     gMarioStates[0].vel[1] = 0.0f;
    //     gMarioStates[0].vel[0] = 0.0f;
    //     gMarioStates[0].vel[2] = 0.0f;
    //     gMarioStates[0].forwardVel = 0.0f;
    } else if(o->oTimer <= 120){
        gMarioStates[0].vel[0] = -50.0f;
        gMarioStates[0].vel[1] = 0.0f;
        gMarioStates[0].vel[2] = 0.0f;
        gMarioStates[0].forwardVel = -50.0f;
        gMarioStates[0].pos[0] -= 50.0f;
    } else if(o->oTimer <= 180){
        gMarioStates[0].vel[1] = -20.0f;
        gMarioStates[0].vel[0] = 0.0f;
        gMarioStates[0].vel[2] = 0.0f;
        gMarioStates[0].pos[1] -= 20.0f;
    } else {
        o->oAction = CHALLENGE_ROUND_1;
    }

    char text[30];
    // sprintf(text, "%d", o->oTimer);
    // gMarioStates[0].pos[1] = marioYPos;
    sprintf(text, "%f", gMarioStates[0].pos[1]);
    print_text(50, 50, text);
}

void bhv_challenge_round_1(void){

    char ax[30], ay[30], az[30];
    sprintf(ax, "%d", gMarioStates[0].faceAngle[0]);
    print_text(50, 80, ax);
    sprintf(ay, "%d", gMarioStates[0].faceAngle[1]);
    print_text(50, 60, ay);
    sprintf(az, "%d", gMarioStates[0].faceAngle[2]);
    print_text(50, 40, az);
    
}

void bhv_challenge_init(void){
    o->oAction = CHALLENGE_NULL;
}

void bhv_challenge_loop(void){

    switch(o->oAction){
        case CHALLENGE_NULL:
            if (obj_check_if_collided_with_object(o, gMarioObject) == 1){
                // play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
                o->oAction = CHALLENGE_START;
            }
            break;
        case CHALLENGE_START:
            bhv_challenge_start(gMarioStates[0].pos[1]);
            break;
        case CHALLENGE_ROUND_1:
            bhv_challenge_round_1();
            break;
        // case CHALLENGE_ROUND_2:
        
        //     break;
        // case CHALLENGE_END:
        //     o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        //     break;
    }

    
}