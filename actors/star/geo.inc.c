#include "src/game/envfx_snow.h"

const GeoLayout star_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_star_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8, 9, 18, 0, -90, -90, star_Cylinder_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 11, 9, 18, 0, -90, -90, star_Cylinder_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
