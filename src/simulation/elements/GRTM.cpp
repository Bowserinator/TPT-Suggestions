#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_GRTM()
{
	Identifier = "DEFAULT_PT_GRTM";
	Name = "GRTM";
	Colour = PIXPACK(0x5bc94d);
	MenuVisible = 1;
	MenuSection = SC_NUCLEAR;
	Enabled = 1;

	Advection = 0.6f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f  * CFDS;
	Falldown = 2;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 20;

	Weight = 35;

	DefaultProperties.temp = 273.15f;
	HeatConduct = 5;
	Description = "Gravitonium. A liquid GPMP, gravity varies with temperature.";

	Properties = TYPE_LIQUID | PROP_NEUTPENETRATE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
	Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (parts[i].temp>=256.0f+273.15f)
        parts[i].temp=256.0f+273.15f;
    if (parts[i].temp<= -256.0f+273.15f)
        parts[i].temp = -256.0f+273.15f;
    sim->gravmap[(y/CELL)*XCELLS+(x/CELL)] = 0.005f*(parts[i].temp-273.15);
	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
    // Blue when repel, green when attract, lighter = more strong
	float q = fabs((cpart->temp + 273.15f) / 256.0f) * 0.7f + 0.3f;
    if (cpart -> temp > 273.15f) {
        *colr = (int)(91 * q); 
        *colg = (int)(201 * q);
        *colb = (int)(77 * q);
    } else {
        *colr = (int)(77 * q); 
        *colg = (int)(162 * q);
        *colb = (int)(201 * q);
    }
	*pixel_mode |= PMODE_BLUR;
	return 0;
}
