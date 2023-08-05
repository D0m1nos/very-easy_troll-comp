char time[40];
char text_time[30] = "TIME: ", text_done[30] = "ENTER THE PIPE";
char test[100], test2[100], test3[100], test4[100];
u8 marioStopped = 0;
u8 previousAction;

void timer(u32 limit, u32 currentTime){
    if(currentTime % 30 == 0){
        sprintf(time, "%d", limit-(currentTime/30));
    }

    if(currentTime == (limit*30)){
        set_mario_action(&gMarioStates[0], ACT_STANDING_DEATH, 0);
    }
    
    if(currentTime > (limit*30)){
        sprintf(time, "%d", 0);
    }

    print_text(30, 50, text_time);
    print_text(90, 50, time);
}

void survive_timer(u32 limit, u32 currentTime){
    if(currentTime % 30 == 0){
        sprintf(time, "%d", (limit-5)-(currentTime/30));
    }

    if(currentTime == (limit*30)){
        spawn_object_relative(0xB1, 0, 0, 0, o, MODEL_BITS_WARP_PIPE, bhvWarpPipe);
    }

    print_text(30, 50, text_time);
    if(currentTime <= (limit*30)){
        print_text(90, 50, time);
    } else {
        print_text(90, 50, text_done);
    }
    
}

void bhv_challenge_arena_round_1(void){
    timer(8, o->oTimer);
    print_text(30, 30, "1/5 PICK A PIPE");
}

void bhv_challenge_arena_round_2(void){
    if(gMarioStates[0].challengeRound == 2){
        timer(20, o->oTimer);
        print_text(30, 30, "2/5 BLJ");
    } else if (gMarioStates[0].challengeRound == 6){
        timer(30, o->oTimer);
        print_text(30, 30, "ACTUALLY CAN YOU BOMB");
        print_text(30, 10, "CLIP");
    }
}

void bhv_challenge_arena_round_3(void){
    survive_timer(20, o->oTimer);
    print_text(30, 30, "3/5 SURVIVE");
}

void bhv_challenge_arena_round_4(void){
    timer(60, o->oTimer);
    print_text(30, 30, "4/5 PLATFORMING");
}

void bhv_challenge_arena_round_5(void){
    if(o->oTimer % 150 == 0 && gMarioStates[0].healCounter < 32){
        gMarioStates[0].healCounter += 4;
    }
    print_text(30, 30, "5/5 DEFEAT WHOMP");
}

void bhv_challenge_arena_round_6(void){
    if(o->oTimer == 0){
        play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_REFLUXIO_2), 0);
    }

    if(gMarioStates[0].challengeRound == 7) {
        print_text(30, 30, "6/5 ?????");
    } else if(gMarioStates[0].challengeRound == 8) {
        print_text(30, 30, "6/5 GRAB THE STAR");
    }
}


void bhv_challenge_arena_init(void){
   o->oAction = CHALLENGE_NULL; 
}

void bhv_challenge_arena_loop(void){

    switch(gMarioStates[0].challengeRound){
        case 2:
            o->oAction = CHALLENGE_ROUND_2;
            break;
        case 3:
            o->oAction = CHALLENGE_ROUND_3;
            break;
        case 4:
            o->oAction = CHALLENGE_ROUND_4;
            break;
        case 5:
            o->oAction = CHALLENGE_ROUND_5;
            break;
        case 7:
        case 8:
            o->oAction = CHALLENGE_ROUND_6;
            break;
    }

    switch(o->oAction){
        case CHALLENGE_NULL:
            if (obj_check_if_collided_with_object(o, gMarioObject) == 1){
                gMarioStates[0].challengeRound = 1;
                marioStopped = 0;
                o->oAction = CHALLENGE_ROUND_1;
            }
            break;
        case CHALLENGE_ROUND_1:
            bhv_challenge_arena_round_1();
            break;
        case CHALLENGE_ROUND_2:
            bhv_challenge_arena_round_2();
            break;
        case CHALLENGE_ROUND_3:
            bhv_challenge_arena_round_3();
            break;
        case CHALLENGE_ROUND_4:
            bhv_challenge_arena_round_4();
            break;
        case CHALLENGE_ROUND_5:
            bhv_challenge_arena_round_5();
            break;
        case CHALLENGE_ROUND_6:
            bhv_challenge_arena_round_6();
            break;
        case CHALLENGE_END:
            break;
    }

    if(previousAction != o->oAction){
        gMarioStates[0].healCounter = 31;
        gMarioStates[0].hurtCounter = 0;
        if(o->oAction != CHALLENGE_ROUND_6){
            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
        }
    }

    previousAction = o->oAction;
}

void bhv_challenge_done_loop(void) {
    if(obj_check_if_collided_with_object(o, gMarioObject) == 1){
        gMarioStates[0].challengeRound = o->oBehParams2ndByte;

        if(marioStopped == 0 && o->oBehParams2ndByte == 6){
            marioStopped = 1;
            gMarioStates[0].forwardVel = 0.0f;
            gMarioStates[0].vel[0] = 0.0f;
            gMarioStates[0].vel[1] = 0.0f;
            gMarioStates[0].vel[2] = 0.0f;
        }

        // obj_mark_for_deletion(o);
    }
}

void bhv_survival_loop(void) {
    f32 randomPosX, randomPosZ;
    struct Object *enemy;
    if(o->oTimer < (30*10)){
        if(o->oTimer % 30 == 0){
            randomPosX = random_float() * 3638.0f - 335.0f; // da -335 a +3303
            randomPosZ = random_float() * 3900.0f - 1585.0f; // da -1585 a +2315
            enemy = spawn_object(o, MODEL_GOOMBA, bhvGoomba);
            
            enemy->oPosX = randomPosX;
            enemy->oPosY = o->oPosY;
            enemy->oPosZ = randomPosZ;
        }
    } else if(o->oTimer < (30*20)) {
        if(o->oTimer % 30 == 0){
            randomPosX = random_float() * 3638.0f - 335.0f; // da -335 a +3303
            randomPosZ = random_float() * 3900.0f - 1585.0f; // da -1585 a +2315
            enemy = spawn_object(o, MODEL_CHUCKYA, bhvChuckya);
            
            enemy->oPosX = randomPosX;
            enemy->oPosY = o->oPosY;
            enemy->oPosZ = randomPosZ;
        }
    }
}