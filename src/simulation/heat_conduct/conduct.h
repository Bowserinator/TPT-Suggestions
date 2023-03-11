#include <map>
#include <list>
#include <iostream>

#include "simulation/ElementCommon.h"

namespace HEATCONDUCT {
struct HeatConductState {
    unsigned int id;
    double totalTemp;
    unsigned int parentConductorID;
    unsigned int partCount;
};

extern std::map<unsigned int, HeatConductState> heatConductors;
unsigned int get_new_state_id();
unsigned int create_new_state(int part_id);

void reset_averages();
void apply_averages(Simulation * sim);
};