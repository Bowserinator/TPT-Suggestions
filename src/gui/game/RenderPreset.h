#pragma once
#include "common/String.h"
#include <vector>

class RenderPreset
{
public:
	String Name;
	std::vector<unsigned int> RenderModes;
	std::vector<unsigned int> DisplayModes;
	unsigned int ColourMode;

	RenderPreset(): Name(""), ColourMode(0) {}
	RenderPreset(String name, std::vector<unsigned int> renderModes, std::vector<unsigned int> displayModes, unsigned int colourMode):
		Name(name),
		RenderModes(renderModes),
		DisplayModes(displayModes),
		ColourMode(colourMode)
	{}
};
