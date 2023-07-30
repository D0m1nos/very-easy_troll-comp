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
    // bhv_1k_coin_star_400_coins,
    bhv_1k_coin_star_500_coins,
    // bhv_1k_coin_star_600_coins,
    bhv_1k_coin_star_700_coins,
    // bhv_1k_coin_star_800_coins,
    // bhv_1k_coin_star_900_coins,
    bhv_1k_coin_star_1000_coins,
};

void bhv_1k_coin_star_loop(void) {
    coins = gMarioStates[0].numCoins;
    
    cur_obj_call_action_function(s1kCoinStarActions);

    if(coins == 100 && started == 0){
        started = 1;
        o->oAction = 1;
    }
}

void bhv_1k_coin_star_100_coins(void){
    if(dialogDone == 1){
        if(coins == 200){
            dialogDone = 0;
            o->oAction = 2;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_170)){
            dialogDone = 1;
        }
    }
}

void bhv_1k_coin_star_200_coins(void){
    if(dialogDone == 1){
        if(coins == 300){
            dialogDone = 0;
            o->oAction = 3;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_171)){
            dialogDone = 1;
        }
    }
}

void bhv_1k_coin_star_300_coins(void){
    if(dialogDone == 1){
        if(coins == 500){
            dialogDone = 0;
            o->oAction = 4;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_172)){
            dialogDone = 1;
        }
    }
}

// void bhv_1k_coin_star_400_coins(void){
//     if(dialogDone == 1){
//         if(coins == 50){
//             dialogDone = 0;
//             o->oAction = 5;
//         }
//     } else {
//         if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_003)){
//             dialogDone = 1;
//         }
//     }
// }

void bhv_1k_coin_star_500_coins(void){
    if(dialogDone == 1){
        if(coins == 700){
            dialogDone = 0;
            o->oAction = 5;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_173)){
            dialogDone = 1;
        }
    }
}

// void bhv_1k_coin_star_600_coins(void){
//     if(dialogDone == 1){
//         if(coins == 70){
//             dialogDone = 0;
//             o->oAction = 7;
//         }
//     } else {
//         if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_005)){
//             dialogDone = 1;
//         }
//     }
// }

void bhv_1k_coin_star_700_coins(void){
    if(dialogDone == 1){
        if(coins == 1000){
            dialogDone = 0;
            o->oAction = 6;
        }
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_174)){
            dialogDone = 1;
        }
    }
}

// void bhv_1k_coin_star_800_coins(void){
//     if(dialogDone == 1){
//         if(coins == 100){
//             dialogDone = 0;
//             o->oAction = 6;
//         }
//     } else {
//         if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_007)){
//             dialogDone = 1;
//         }
//     }
// }

// void bhv_1k_coin_star_900_coins(void){
//     if(dialogDone == 1){
//         if(coins == 100){
//             dialogDone = 0;
//             o->oAction = 10;
//         }
//     } else {
//         if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_008)){
//             dialogDone = 1;
//         }
//     }
// }

void bhv_1k_coin_star_1000_coins(void){
    if(dialogDone == 1){
        dialogDone = 1;
    } else {
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_175)){
            dialogDone = 1;
        }
    }
}