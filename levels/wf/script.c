#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, wf_geo_0007E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, wf_geo_000820), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, wf_geo_000860), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, wf_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, wf_geo_000890), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, wf_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, wf_geo_0008E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, wf_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, wf_geo_000940), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, wf_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, wf_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, wf_geo_0009D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, wf_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x11, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x01, -6254, -386, 0),
		WARP_NODE(0x07, LEVEL_WF, 0x02, 0x0A, WARP_CHECKPOINT),
		WARP_NODE(0x08, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0x09, LEVEL_WF, 0x01, 0x09, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_THWOMP, 28, 1214, 6, 0, 0, 0, 0x00000000, bhvThwomp3),
		OBJECT(MODEL_BLUE_COIN, -2229, 68, -37, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 172, 100, -19, 0, -90, 0, (169 << 16), bhvMessagePanel),
		OBJECT(MODEL_YELLOW_COIN, 1067, 68, -26, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_STAR, 4830, 982, -15, 0, 0, 0, (0 << 24), bhvStar),
		OBJECT(MODEL_EXCLAMATION_BOX, 3367, 229, -18, 0, 0, 0, (4 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 3610, 768, -16, 0, 0, 0, (5 << 16), bhvExclamationBox),
		OBJECT(MODEL_YELLOW_COIN, 1167, 68, -26, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_CHUCKYA, 5127, 2105, -592, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_YELLOW_COIN, 1267, 68, -26, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1367, 68, -26, 0, 90, 0, 0x00000000, bhvEvilYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1467, 68, -26, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 1858, 152, 570, 0, -180, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_1UP, 2228, 70, -37, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_NONE, 3980, 2142, 571, 0, -180, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 4765, 2142, 286, 0, -180, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 4370, 2142, -661, 0, 0, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 5003, 2301, -269, 0, 0, 0, 0x00000000, bhvQuicksandTransporter),
		OBJECT(MODEL_1UP, 5257, 2212, -37, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_CHUCKYA, 5519, 2105, -602, 0, -37, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_AMP, 5652, 2148, -368, 0, 0, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, 5823, 2148, -226, 0, 0, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, 6018, 2148, -50, 0, 0, 0, 0x00000000, bhvHomingAmp),
		OBJECT(MODEL_NONE, 6319, 1811, -36, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_YELLOW_COIN, 6319, 1667, -36, 0, 0, 0, (80 << 16), bhvEvilYellowCoinWithChild),
		OBJECT(MODEL_HEART, 5374, 713, -509, 0, 0, 0, (0x08 << 16), bhvRecoveryHeart),
		OBJECT(MODEL_NONE, 4830, 805, 18, 0, 0, 0, (0 << 16), bhvChallengeDone),
		OBJECT(MODEL_NONE, 5453, 744, 588, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 90, 5453, 744, 588),
		OBJECT(MODEL_NONE, 4833, 753, 1, 0, 0, 0, (0x07 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 5374, 713, -509, 0, 0, 0, (0x08 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 5374, 713, -509, 0, 0, 0, (0x09 << 16), bhvDeathWarp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SAND_CANYON),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB0, LEVEL_WF, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB1, LEVEL_WF, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 13, 109, -6, 0, 0, 0, 0x00000000, bhvChallengeArena),
		OBJECT(MODEL_BITS_WARP_PIPE, 802, 27, -1417, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 1885, 25, -551, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 2130, 27, -40, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 1793, 22, 553, 0, 0, 0, (0xB1 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 1925, 41, -1566, 45, -56, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, -447, 25, -1142, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 1999, 136, 1493, -90, 30, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, -996, 25, 570, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, -1676, -46, -344, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 522, 27, 1553, 0, 0, 0, (0xB0 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, wf_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(wf_area_3_collision),
		MACRO_OBJECTS(wf_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, wf_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB1, LEVEL_WF, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x04, 6236, 8144, -85),
		OBJECT(MODEL_NONE, 31, 58, 44, 0, 0, 0, (2 << 16), bhvChallengeDone),
		OBJECT(MODEL_NONE, 9823, 8169, 207, 0, 0, 0, (6 << 16), bhvChallengeDone),
		OBJECT(MODEL_NONE, 10, 79, 57, 0, 0, 0, 0x00000000, bhvChallengeArena),
		OBJECT(MODEL_BLACK_BOBOMB, 10945, 8066, 1572, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -82205, 0, -22430),
		OBJECT(MODEL_BITS_WARP_PIPE, 3843, 19, 193, 0, 0, 0, (0xB1 << 16), bhvWarpPipe),
		OBJECT(MODEL_BITS_WARP_PIPE, 13717, 8077, 416, 0, 0, 0, (0xB1 << 16), bhvWarpPipe),
		TERRAIN(wf_area_4_collision),
		MACRO_OBJECTS(wf_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, wf_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB1, LEVEL_WF, 0x06, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 31, 58, 44, 0, 0, 0, (3 << 16), bhvChallengeDone),
		OBJECT(MODEL_NONE, 24, 79, 37, 0, 0, 0, 0x00000000, bhvChallengeArena),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -82205, 0, -32017),
		OBJECT(MODEL_BITS_WARP_PIPE, 1566, 19, 354, 0, 0, 0, (0xB1 << 16), bhvWarpPipe),
		TERRAIN(wf_area_5_collision),
		MACRO_OBJECTS(wf_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, wf_area_6),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB1, LEVEL_WF, 0x07, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 31, 58, 44, 0, 0, 0, (4 << 16), bhvChallengeDone),
		OBJECT(MODEL_NONE, 24, 109, 96, 0, 0, 0, 0x00000000, bhvChallengeArena),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -82205, 0, -41298),
		OBJECT(MODEL_BITS_WARP_PIPE, 1566, 19, 379, 0, 0, 0, (0xB1 << 16), bhvWarpPipe),
		TERRAIN(wf_area_6_collision),
		MACRO_OBJECTS(wf_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(7, wf_area_7),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB1, LEVEL_WF, 0x08, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 31, 58, 44, 0, 0, 0, (5 << 16), bhvChallengeDone),
		OBJECT(MODEL_NONE, 24, 109, 56, 0, 0, 0, 0x00000000, bhvChallengeArena),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -82205, 0, -50875),
		OBJECT(MODEL_BITS_WARP_PIPE, 1566, 19, 340, 0, 0, 0, (0xB1 << 16), bhvWarpPipe),
		TERRAIN(wf_area_7_collision),
		MACRO_OBJECTS(wf_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(8, wf_area_8),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x08, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 1486, 203, 273, 0, 0, 0, (0 << 24), bhvStar),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -91724, 0, -50875),
		TERRAIN(wf_area_8_collision),
		MACRO_OBJECTS(wf_area_8_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BRAWL_BREAKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -91724, 0, -50875),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
