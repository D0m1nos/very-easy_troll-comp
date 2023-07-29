/*
    STAR_NULL,
    STAR_100_COINS,
    STAR_200_COINS,
    STAR_300_COINS,
    STAR_400_COINS,
    STAR_500_COINS,
    STAR_600_COINS,
    STAR_700_COINS,
    STAR_800_COINS,
    STAR_900_COINS,
    STAR_1000_COINS,
    STAR_DONE
*/
u32 coins;
u8 started;
u8 dialogDone;

void bhv_1k_coin_star_init(void){
    o->oAction = 0;
    started = 0;
    dialogDone = 0;
}

ObjActionFunc s1kCoinStarActions[] = {
    bhv_1k_coin_star_init,
    bhv_1k_coin_star_100_coins,
    bhv_1k_coin_star_200_coins,
    bhv_1k_coin_star_300_coins,
};

void bhv_1k_coin_star_loop(void) {
    coins = gMarioStates[0].numCoins;
    // switch(o->oAction){
    //     case STAR_NULL:
    //         break;
    //     case STAR_100_COINS:
    //         bhv_1k_coin_star_100_coins();
    //         break;
    //     case STAR_200_COINS:
    //         break;
    //     case STAR_300_COINS:
    //         break;
    //     case STAR_400_COINS:
    //         break;
    //     case STAR_500_COINS:
    //         break;
    //     case STAR_600_COINS:
    //         break;
    //     case STAR_700_COINS:
    //         break;
    //     case STAR_800_COINS:
    //         break;
    //     case STAR_900_COINS:
    //         break;
    //     case STAR_1000_COINS:
    //         break;
    //     case STAR_DONE:
    //         break;
    // }
    
    cur_obj_call_action_function(s1kCoinStarActions);

    if(coins == 10 && started == 0){
        started = 1;
        o->oAction = 1;
    }
}

// if (COURSE_IS_MAIN_COURSE(gCurrCourseNum) && (m->numCoins % 10 == 0) && m->numCoins > 0) {
        // cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_165);
        // set_mario_action(m, ACT_READING_NPC_DIALOG, 0);
        // set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT);
        // if(cutscene_object_with_dialog(CUTSCENE_DIALOG, m, DIALOG_165)){
        //     set_mario_action(m, ACT_IDLE, 0);
        //     set_mario_npc_dialog(MARIO_DIALOG_STOP);
        //     print_text(60,160, "fjmoiewfujOIFJOIESJFOISEJ");
        // }
        // set_mario_action(m, ACT_IDLE, 0);
        // cur_obj_update_dialog(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TEXT_DEFAULT, DIALOG_165, 0);
    // }

// cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_165);
        // set_mario_action(&gMarioStates[0], ACT_READING_NPC_DIALOG, 0);
        // cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_165);
        // set_mario_action(&gMarioStates[0], ACT_READING_NPC_DIALOG, 0);
        // set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT);
        // if(cutscene_object_with_dialog(CUTSCENE_DIALOG, &gMarioStates[0], DIALOG_165)){
        //     set_mario_action(&gMarioStates[0], ACT_IDLE, 0);
        //     set_mario_npc_dialog(MARIO_DIALOG_STOP);
        //     print_text(60,160, "fjmoiewfujOIFJOIESJFOISEJ");
        // }

void bhv_1k_coin_star_100_coins(void){
    if(dialogDone == 1){
        if(coins == 20){
            dialogDone = 0;
            o->oAction = 2;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_165)){
            dialogDone = 1;
        }
    }
}

void bhv_1k_coin_star_200_coins(void){
    if(dialogDone == 1){
        if(coins == 30){
            dialogDone = 0;
            o->oAction = 3;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_163)){
            dialogDone = 1;
        }
    }
}

void bhv_1k_coin_star_300_coins(void){
    if(dialogDone == 1){
        dialogDone = 1;
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_162)){
            dialogDone = 1;
        }
    }
}