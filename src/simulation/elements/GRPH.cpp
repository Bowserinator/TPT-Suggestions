#include "simulation/ElementCommon.h"

int Element_GRPH_update(UPDATE_FUNC_ARGS);
int Element_GRPH_graphics(GRAPHICS_FUNC_ARGS);
static void create(ELEMENT_CREATE_FUNC_ARGS);

void Element::Element_GRPH()
{
	Identifier = "DEFAULT_PT_GRPH";
	Name = "GRPH";
	Colour = PIXPACK(0x2f3028);
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
	Hardness = 1;

	Weight = 100;

	HeatConduct = 192;
	Description = "Graphite. Slow conductor, slows down neutrons";

	Properties = TYPE_SOLID | PROP_SPARKSETTLE | PROP_LIFE_DEC | PROP_CONDUCTS | PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 4300.0f;
	HighTemperatureTransition = PT_PLSM;

	Update = &Element_GRPH_update;
    Graphics = &Element_GRPH_graphics;
	Create = &create;
}

int Element_GRPH_update(UPDATE_FUNC_ARGS)
{
    // tmp3 - last pressure
	int r, rx, ry, rt;
    bool seen_sprk = false;
	int crbn_count = 0;
	int xor_check = 0;

    // Slow down neutrons
    r = sim->photons[y][x];
    if (r && TYP(r) == PT_NEUT) {
        parts[ID(r)].vx *= 0.94f;
        parts[ID(r)].vy *= 0.94f;
    }
 
    // Turn slowly into CO2 at high temperatures
    if (parts[i].temp > 3600.0f + 273.15f && RNG::Ref().chance(1, 100)) {
        sim->part_change_type(i, x, y, PT_CO2);
        return 1;
    }

    // Shatter into powder
    auto press = int(sim->pv[y/CELL][x/CELL] * 64);
	auto diff = press - parts[i].tmp3;
    int resistance = (int)((parts[i].temp / 4000.0f) * 128);

    // Probabilistic: small change, absolute requires larger chance
    if ((diff > 48 + resistance || diff < -48 - resistance) ||
            ((diff > 32 + resistance || diff < - 32 - resistance) && RNG::Ref().chance(1, 100))) {
        sim->part_change_type(i, x, y, PT_GRPP);
        return 1;
    }
	parts[i].tmp3 = press;

    for (rx=-1; rx<2; rx++)
        for (ry=-1; ry<2; ry++)
            if (BOUNDS_CHECK && (rx || ry)) {
                r = pmap[y+ry][x+rx];
                if (!r) {
                    // Burst into flame at high temperatures
                    if (parts[i].temp > 3273.15f && RNG::Ref().chance(1, 1500)) {
                        int j = sim->create_part(-1, x + rx, y + ry, PT_FIRE);
                        if (j > -1) {
                            parts[j].life = RNG::Ref().between(10, 150);
                            parts[j].temp = parts[i].temp;
                        }
                    }
                    continue;
                }
                rt = TYP(r);

                // Purify water
                if (rt == PT_WATR)
                    sim->part_change_type(ID(r), x + rx, y + ry, PT_DSTW);
                else if (rt == PT_SLTW)
                    sim->part_change_type(ID(r), x + rx, y + ry,
                        RNG::Ref().chance(1, 2) ? PT_SALT : PT_DSTW);

                else if (rt == PT_SPRK) {
                    seen_sprk = true;
                    if (parts[ID(r)].ctype == PT_PSCN)
                        xor_check |= 1;
                    else if (parts[ID(r)].ctype == PT_NSCN)
                        xor_check |= 2;
                }
                else if (rt == PT_GRPH || rt == PT_GRPP)
                    ++crbn_count;

                // Convert molten IRON into METL (steel)
                else if (rt == PT_LAVA && parts[ID(r)].ctype == PT_IRON) {
                    parts[ID(r)].ctype = PT_METL;
                    if (RNG::Ref().chance(1, 5)) {
                        sim->kill_part(i);
                        return 0;
                    }
                }
            }

    // Prevent conduction if both PSCN and NSCN
	if (xor_check == 3)
		parts[i].life = 1;

	// Thin wires superconduct
	else if (parts[i].temp < 100.0f && seen_sprk && crbn_count <= 2)
		sim->FloodINST(x, y);
	return 0;
}

int Element_GRPH_graphics(GRAPHICS_FUNC_ARGS) {
    int z = (cpart->tmp - 5) * 5; // Speckles!
	*colr += z;
	*colg += z;
	*colb += z;

	return 0;
}

static void create(ELEMENT_CREATE_FUNC_ARGS) {
	sim->parts[i].tmp = RNG::Ref().between(0, 6);
}
