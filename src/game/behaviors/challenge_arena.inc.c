// struct challenge{

// }

char time[40];
char text_time[30] = "TIME: ";
char test[100], test2[100], test3[100];

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

    if(currentTime >= (limit*30)){
        sprintf(time, "%d", "DONE");
    }

    print_text(30, 50, text_time);
    print_text(90, 50, time);
}

void bhv_challenge_arena_round_1(void){
    timer(7, o->oTimer);
    print_text(30, 30, "1/5 PICK A PIPE");
}

void bhv_challenge_arena_round_2(void){
    timer(20, o->oTimer);
    print_text(30, 30, "2/5 BLJ");
}

void bhv_challenge_arena_round_3(void){
    survive_timer(20, o->oTimer);
    print_text(30, 30, "3/5 SURVIVE");
}

void bhv_challenge_arena_round_4(void){
    timer(7, o->oTimer);
    print_text(30, 30, "4/5 PLATFORMING");
}

void bhv_challenge_arena_round_5(void){
    timer(7, o->oTimer);
    print_text(30, 30, "5/5 DEFEAT WHOMP");
}


void bhv_challenge_arena_init(void){
   o->oAction = CHALLENGE_NULL; 
}

void bhv_challenge_arena_loop(void){

    // sprintf(test, "%d", gMarioStates[0].challengeRound);
    // print_text(30, 80, test);

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
    }

    switch(o->oAction){
        case CHALLENGE_NULL:
            if (obj_check_if_collided_with_object(o, gMarioObject) == 1){
                gMarioStates[0].challengeRound = 1;
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
        case CHALLENGE_END:
            break;
    }

    
}

// void bhv_challenge_done_init(void) {

// }

void bhv_challenge_done_loop(void) {
    if(obj_check_if_collided_with_object(o, gMarioObject) == 1){
        gMarioStates[0].challengeRound = o->oBehParams2ndByte;
        if(o->oBehParams2ndByte != 0 && gMarioStates[0].challengeRound != o->oBehParams2ndByte){
            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
        }
        // obj_mark_for_deletion(o);
    }
}