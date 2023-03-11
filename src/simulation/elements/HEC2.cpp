#include "simulation/ElementCommon.h"
#include "simulation/heat_conduct/conduct.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_HEC2()
{
	Identifier = "DEFAULT_PT_HEC2";
	Name = "HEC2";
	Colour = PIXPACK(0xCB6351);
	MenuVisible = 1;
	MenuSection = SC_SOLIDS;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 100;

	HeatConduct = 255;
	Description = "Instant heat conductor, because someone complained HEAC was slow.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
}

static const auto isInsulator = [](Simulation* a, int b) -> bool {
	return b && (a->elements[TYP(b)].HeatConduct == 0 || (TYP(b) == PT_HSWC && a->parts[ID(b)].life != 10));
};


static int update(UPDATE_FUNC_ARGS) {
	// If not assigned to a heat conduction group, randomly generate an ID and assign it (floodfill)
    if (parts[i].tmp == 0 || HEATCONDUCT::heatConductors.count(parts[i].tmp) == 0) {
        unsigned int id = HEATCONDUCT::create_new_state(i);
        PropertyValue value;
        value.Integer = id;
        sim->flood_prop(x, y, offsetof(Particle, tmp), value, StructProperty::Integer);
    }

    // If touching non-insulators, increment global temperature and particle count
    int rx, ry, r, rt;
    for (rx=-1; rx<2; rx++)
        for (ry=-1; ry<2; ry++)
            if (BOUNDS_CHECK && (rx || ry)) {
                r = pmap[y+ry][x+rx];
                if (!r) continue;
                rt = TYP(r);

                if (!isInsulator(sim, r) && rt != PT_HEC2) {
                    HEATCONDUCT::heatConductors[parts[i].tmp].partCount++;
                    HEATCONDUCT::heatConductors[parts[i].tmp].totalTemp += parts[ID(r)].temp;
                }
            }
    
	return 0;
}
