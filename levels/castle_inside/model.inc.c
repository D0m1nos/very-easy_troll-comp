Lights1 castle_inside_dl_f3dlite_material_lights = gdSPDefLights1(
	0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x28, 0x28, 0x28);

Vtx castle_inside_dl_Plane_mesh_layer_1_vtx_0[4] = {
	{{ {-640, 0, 640}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {640, 0, 640}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {640, 0, -640}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-640, 0, -640}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx castle_inside_dl_Plane_mesh_layer_1_tri_0[] = {
	gsSPVertex(castle_inside_dl_Plane_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_castle_inside_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(castle_inside_dl_f3dlite_material_lights),
	gsSPEndDisplayList(),
};

Gfx castle_inside_dl_Plane_mesh_layer_1[] = {
	gsSPDisplayList(mat_castle_inside_dl_f3dlite_material),
	gsSPDisplayList(castle_inside_dl_Plane_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx castle_inside_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

