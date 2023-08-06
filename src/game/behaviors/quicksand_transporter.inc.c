char text[30];
u8 soundPlayed;

#include "game/print.h"

void timer_quicksand(u32 limit, u32 currentTime){
    if(currentTime % 30 == 0){
        sprintf(text, "%d", limit-(currentTime/30));
        play_sound(SOUND_GENERAL_BIG_CLOCK, gGlobalSoundSource);
    }
    
    if(currentTime > (limit*30)){
        sprintf(text, "%d", 3);
    }

    print_text(220,110,text);
}

void bhv_quicksand_transporter_push_back(void){
    
    set_mario_action(&gMarioStates[0], ACT_READING_NPC_DIALOG, 0);

    if(o->oTimer == 0){
        stop_background_music(SEQUENCE_ARGS(4, SEQ_SAND_CANYON));
        gMarioStates[0].pos[1] += 250.0f;
    } else if(o->oTimer <= (30 * 3)){
        timer_quicksand(3, o->oTimer-1);
        
    } else { 
        if(soundPlayed == 0){
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_DUCK_TALES_MOON), 0);
            soundPlayed = 1;
        }

        // fino a X: -2233
        if(gMarioStates[0].pos[0] > -2233.0f && gMarioStates[0].pos[0] != -2233.0f) {
            gMarioStates[0].pos[0] -= 30.0f;
        } else {
            gMarioStates[0].pos[0] = -2233.0f;
        }

        // fino a Z: -36
        if(gMarioStates[0].pos[2] != -36.0f) {
            if(gMarioStates[0].pos[2] > 0.0f){ 
                gMarioStates[0].pos[2] -= 10.0f;
                if(gMarioStates[0].pos[2] < -36.0f) {
                    gMarioStates[0].pos[2] = -36.0f;
                }
            } else {
                gMarioStates[0].pos[2] += 10.0f;
                if(gMarioStates[0].pos[2] > -36.0f) {
                    gMarioStates[0].pos[2] = -36.0f;
                }
            }
        } else {
            gMarioStates[0].pos[2] = -36.0f;
        }

        if(gMarioStates[0].pos[0] == -2233.0f && gMarioStates[0].pos[2] == -36.0f) {       
            o->oAction = QUICKSAND_TRANSPORTER_PUSH_DOWN;
        }
        
    }
}

void bhv_quicksand_transporter_push_down(void){

    set_mario_action(&gMarioStates[0], ACT_READING_NPC_DIALOG, 0);

    print_text(60, 140, ""); // ???????????

    if(gMarioStates[0].pos[1] > 50.0f){ // fino a Y: 50
        gMarioStates[0].pos[1] -= 20.0f;
    } else {
        gMarioStates[0].pos[1] = 50.0f;
        set_mario_action(&gMarioStates[0], ACT_IDLE, 0);
        o->oAction = QUICKSAND_TRANSPORTER_END;
    }

   
    
}

void bhv_quicksand_transporter_init(void){
    soundPlayed = 0;
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
            o->oAction = QUICKSAND_TRANSPORTER_NULL;
            break;
    }

    
}