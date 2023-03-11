#include <map>
#include "simulation/heat_conduct/conduct.h"
#include "simulation/ElementCommon.h"

namespace HEATCONDUCT {
    std::map<unsigned int, HeatConductState> heatConductors;

    unsigned int get_new_state_id() {
        int state;
        do {
            state = RNG::Ref().between(1, 100000000);
            // State doesn't already exist
            if (heatConductors.count(state) == 0)
                break;
        } while (true);
        return state;
    }
    
    /**
     * Creates a new conductor region
     * @param part_id Id of parent conductor
     * @return ID of state to floodfill 
     */
    unsigned int create_new_state(int part_id) {
        unsigned int id = get_new_state_id();
        struct HeatConductState state;
        state.id = id;
        state.parentConductorID = part_id;
        state.partCount = 0;
        state.totalTemp = 0.0;
        heatConductors[id] = state;
        return id;
    }

    /**
     * Pre-particle loop - reset all state averages
     */
    void reset_averages() {
        for (auto const& x : heatConductors) {
            heatConductors[x.first].partCount = 0;
            heatConductors[x.first].totalTemp = 0.0;
        }
    }

    /**
     * For each group, floodfill the average temperature of all touching particles 
     */
    void apply_averages(Simulation * sim) {
        for (auto const& x : heatConductors) {
            if (heatConductors[x.first].partCount > 0) {
                int id = heatConductors[x.first].parentConductorID;
                int x1 = (int)(sim->parts[id].x + 0.5f);
                int y1 = (int)(sim->parts[id].y + 0.5f);
                float averageTemp = (float)(heatConductors[x.first].totalTemp / heatConductors[x.first].partCount);

                PropertyValue value;
			    value.Float = averageTemp;
                sim->flood_prop(x1, y1, offsetof(Particle, temp), value, StructProperty::Float);
            }
        }
    }
}