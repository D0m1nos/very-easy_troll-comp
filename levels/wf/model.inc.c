Lights1 wf_dl_f3dlite_material_lights = gdSPDefLights1(
	0x5F, 0x56, 0x7F,
	0xC1, 0xB1, 0xFF, 0x28, 0x28, 0x28);

Lights1 wf_dl_f3dlite_material_001_lights = gdSPDefLights1(
	0x7F, 0x70, 0x32,
	0xFF, 0xE1, 0x6C, 0x28, 0x28, 0x28);

Lights1 wf_dl_f3dlite_material_002_lights = gdSPDefLights1(
	0x7F, 0x45, 0x3B,
	0xFF, 0x90, 0x7C, 0x28, 0x28, 0x28);

Lights1 wf_dl_death_floor_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Vtx wf_dl_Cube_mesh_layer_1_vtx_0[24] = {
	{{ {-444, -26, 993}, 0, {368, 1008}, {129, 0, 0, 255} }},
	{{ {-444, 26, 993}, 0, {624, 1008}, {129, 0, 0, 255} }},
	{{ {-444, 26, -993}, 0, {624, 752}, {129, 0, 0, 255} }},
	{{ {-444, -26, -993}, 0, {368, 752}, {129, 0, 0, 255} }},
	{{ {-444, -26, -993}, 0, {368, 752}, {0, 0, 129, 255} }},
	{{ {-444, 26, -993}, 0, {624, 752}, {0, 0, 129, 255} }},
	{{ {444, 26, -993}, 0, {624, 496}, {0, 0, 129, 255} }},
	{{ {444, -26, -993}, 0, {368, 496}, {0, 0, 129, 255} }},
	{{ {444, -26, -993}, 0, {368, 496}, {127, 0, 0, 255} }},
	{{ {444, 26, -993}, 0, {624, 496}, {127, 0, 0, 255} }},
	{{ {444, 26, 993}, 0, {624, 240}, {127, 0, 0, 255} }},
	{{ {444, -26, 993}, 0, {368, 240}, {127, 0, 0, 255} }},
	{{ {444, -26, 993}, 0, {368, 240}, {0, 0, 127, 255} }},
	{{ {444, 26, 993}, 0, {624, 240}, {0, 0, 127, 255} }},
	{{ {-444, 26, 993}, 0, {624, -16}, {0, 0, 127, 255} }},
	{{ {-444, -26, 993}, 0, {368, -16}, {0, 0, 127, 255} }},
	{{ {-444, -26, -993}, 0, {112, 496}, {0, 129, 0, 255} }},
	{{ {444, -26, -993}, 0, {368, 496}, {0, 129, 0, 255} }},
	{{ {444, -26, 993}, 0, {368, 240}, {0, 129, 0, 255} }},
	{{ {-444, -26, 993}, 0, {112, 240}, {0, 129, 0, 255} }},
	{{ {444, 26, -993}, 0, {624, 496}, {0, 127, 0, 255} }},
	{{ {-444, 26, -993}, 0, {880, 496}, {0, 127, 0, 255} }},
	{{ {-444, 26, 993}, 0, {880, 240}, {0, 127, 0, 255} }},
	{{ {444, 26, 993}, 0, {624, 240}, {0, 127, 0, 255} }},
};

Gfx wf_dl_Cube_mesh_layer_1_tri_0[] = {
	gsSPVertex(wf_dl_Cube_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(wf_dl_Cube_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx wf_dl_Cube_001_mesh_layer_1_vtx_0[24] = {
	{{ {-436, -1105, 353}, 0, {368, 1008}, {129, 0, 0, 255} }},
	{{ {-436, 1105, 353}, 0, {624, 1008}, {129, 0, 0, 255} }},
	{{ {-436, 1105, -353}, 0, {624, 752}, {129, 0, 0, 255} }},
	{{ {-436, -1105, -353}, 0, {368, 752}, {129, 0, 0, 255} }},
	{{ {-436, -1105, -353}, 0, {368, 752}, {0, 0, 129, 255} }},
	{{ {-436, 1105, -353}, 0, {624, 752}, {0, 0, 129, 255} }},
	{{ {436, 1105, -353}, 0, {624, 496}, {0, 0, 129, 255} }},
	{{ {436, -1105, -353}, 0, {368, 496}, {0, 0, 129, 255} }},
	{{ {436, -1105, -353}, 0, {368, 496}, {127, 0, 0, 255} }},
	{{ {436, 1105, -353}, 0, {624, 496}, {127, 0, 0, 255} }},
	{{ {436, 1105, 353}, 0, {624, 240}, {127, 0, 0, 255} }},
	{{ {436, -1105, 353}, 0, {368, 240}, {127, 0, 0, 255} }},
	{{ {436, -1105, 353}, 0, {368, 240}, {0, 0, 127, 255} }},
	{{ {436, 1105, 353}, 0, {624, 240}, {0, 0, 127, 255} }},
	{{ {-436, 1105, 353}, 0, {624, -16}, {0, 0, 127, 255} }},
	{{ {-436, -1105, 353}, 0, {368, -16}, {0, 0, 127, 255} }},
	{{ {-436, -1105, -353}, 0, {112, 496}, {0, 129, 0, 255} }},
	{{ {436, -1105, -353}, 0, {368, 496}, {0, 129, 0, 255} }},
	{{ {436, -1105, 353}, 0, {368, 240}, {0, 129, 0, 255} }},
	{{ {-436, -1105, 353}, 0, {112, 240}, {0, 129, 0, 255} }},
	{{ {436, 1105, -353}, 0, {624, 496}, {0, 127, 0, 255} }},
	{{ {-436, 1105, -353}, 0, {880, 496}, {0, 127, 0, 255} }},
	{{ {-436, 1105, 353}, 0, {880, 240}, {0, 127, 0, 255} }},
	{{ {436, 1105, 353}, 0, {624, 240}, {0, 127, 0, 255} }},
};

Gfx wf_dl_Cube_001_mesh_layer_1_tri_0[] = {
	gsSPVertex(wf_dl_Cube_001_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(wf_dl_Cube_001_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx wf_dl_Cube_002_mesh_layer_1_vtx_0[24] = {
	{{ {-464, -35, 594}, 0, {368, 1008}, {129, 0, 0, 255} }},
	{{ {-464, 35, 594}, 0, {624, 1008}, {129, 0, 0, 255} }},
	{{ {-464, 35, -594}, 0, {624, 752}, {129, 0, 0, 255} }},
	{{ {-464, -35, -594}, 0, {368, 752}, {129, 0, 0, 255} }},
	{{ {-464, -35, -594}, 0, {368, 752}, {0, 0, 129, 255} }},
	{{ {-464, 35, -594}, 0, {624, 752}, {0, 0, 129, 255} }},
	{{ {464, 35, -594}, 0, {624, 496}, {0, 0, 129, 255} }},
	{{ {464, -35, -594}, 0, {368, 496}, {0, 0, 129, 255} }},
	{{ {464, -35, -594}, 0, {368, 496}, {127, 0, 0, 255} }},
	{{ {464, 35, -594}, 0, {624, 496}, {127, 0, 0, 255} }},
	{{ {464, 35, 594}, 0, {624, 240}, {127, 0, 0, 255} }},
	{{ {464, -35, 594}, 0, {368, 240}, {127, 0, 0, 255} }},
	{{ {464, -35, 594}, 0, {368, 240}, {0, 0, 127, 255} }},
	{{ {464, 35, 594}, 0, {624, 240}, {0, 0, 127, 255} }},
	{{ {-464, 35, 594}, 0, {624, -16}, {0, 0, 127, 255} }},
	{{ {-464, -35, 594}, 0, {368, -16}, {0, 0, 127, 255} }},
	{{ {-464, -35, -594}, 0, {112, 496}, {0, 129, 0, 255} }},
	{{ {464, -35, -594}, 0, {368, 496}, {0, 129, 0, 255} }},
	{{ {464, -35, 594}, 0, {368, 240}, {0, 129, 0, 255} }},
	{{ {-464, -35, 594}, 0, {112, 240}, {0, 129, 0, 255} }},
	{{ {464, 35, -594}, 0, {624, 496}, {0, 127, 0, 255} }},
	{{ {-464, 35, -594}, 0, {880, 496}, {0, 127, 0, 255} }},
	{{ {-464, 35, 594}, 0, {880, 240}, {0, 127, 0, 255} }},
	{{ {464, 35, 594}, 0, {624, 240}, {0, 127, 0, 255} }},
};

Gfx wf_dl_Cube_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(wf_dl_Cube_002_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(wf_dl_Cube_002_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx wf_dl_Plane_mesh_layer_5_vtx_0[4] = {
	{{ {-4862, 0, 4862}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {4862, 0, 4862}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {4862, 0, -4862}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-4862, 0, -4862}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx wf_dl_Plane_mesh_layer_5_tri_0[] = {
	gsSPVertex(wf_dl_Plane_mesh_layer_5_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_wf_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(wf_dl_f3dlite_material_lights),
	gsSPEndDisplayList(),
};

Gfx mat_wf_dl_f3dlite_material_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(wf_dl_f3dlite_material_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_wf_dl_f3dlite_material_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(wf_dl_f3dlite_material_002_lights),
	gsSPEndDisplayList(),
};

Gfx mat_wf_dl_death_floor[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, 0, 0, 0, 0, SHADE, 0, 0, 0, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(wf_dl_death_floor_lights),
	gsSPEndDisplayList(),
};

Gfx wf_dl_Cube_mesh_layer_1[] = {
	gsSPDisplayList(mat_wf_dl_f3dlite_material),
	gsSPDisplayList(wf_dl_Cube_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx wf_dl_Cube_001_mesh_layer_1[] = {
	gsSPDisplayList(mat_wf_dl_f3dlite_material_001),
	gsSPDisplayList(wf_dl_Cube_001_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx wf_dl_Cube_002_mesh_layer_1[] = {
	gsSPDisplayList(mat_wf_dl_f3dlite_material_002),
	gsSPDisplayList(wf_dl_Cube_002_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx wf_dl_Plane_mesh_layer_5[] = {
	gsSPDisplayList(mat_wf_dl_death_floor),
	gsSPDisplayList(wf_dl_Plane_mesh_layer_5_tri_0),
	gsSPEndDisplayList(),
};

Gfx wf_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

