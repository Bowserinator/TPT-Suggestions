#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
int Element_GRPH_update(UPDATE_FUNC_ARGS);
int Element_GRPH_graphics(GRAPHICS_FUNC_ARGS);
static void create(ELEMENT_CREATE_FUNC_ARGS);

void Element::Element_GRPP()
{
	Identifier = "DEFAULT_PT_GRPP";
	Name = "GRPP";
	Colour = PIXPACK(0x434534);
	MenuVisible = 1;
	MenuSection = SC_POWDERS;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.2f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 1;

	Weight = 87;

	HeatConduct = 190;
	Description = "Graphite Powder.";

	Properties = TYPE_PART | PROP_LIFE_DEC | PROP_CONDUCTS | PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 4000.0f;
	HighTemperatureTransition = PT_PLSM;

	Update = &update;
    Graphics = &Element_GRPH_graphics;
	Create = &create;
}

static int update(UPDATE_FUNC_ARGS)
{
    // Reform into solid
    if (parts[i].temp > 3300.0f && sim->pv[y/CELL][x/CELL] > 20.0f && RNG::Ref().chance(1, 500)) {
        sim->part_change_type(i, x, y, PT_GRPH);
        auto press = int(sim->pv[y/CELL][x/CELL] * 64);
        parts[i].tmp3 = press;
        return 1;
    }

	Element_GRPH_update(UPDATE_FUNC_SUBCALL_ARGS);
	return 0;
}

static void create(ELEMENT_CREATE_FUNC_ARGS) {
	sim->parts[i].tmp = RNG::Ref().between(0, 6);
}
