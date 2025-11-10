#include <iostream>
using namespace std;

class swimmingPool {
private:
    double length;      // feet
    double width;       // feet
    double depth;       // feet
    double fill_rate;   // gallons per minute
    double drain_rate;  // gallons per minute

    static constexpr double GAL_PER_CUFT = 7.48052;

    // helper: total volume of pool in gallons
    double capacityGallons() const {
        return length * width * depth * GAL_PER_CUFT;
    }

public:
    // ----- constructors -----
    swimmingPool() {
        length = width = depth = 0.0;
        fill_rate = drain_rate = 0.0;
    }

    swimmingPool(double l, double w, double d,
                 double fRate, double dRate) {
        length = l;
        width  = w;
        depth  = d;
        fill_rate  = fRate;
        drain_rate = dRate;
    }

    // Determine amount of water (in gallons) needed to fill
    // currentGallons = how much water is already in the pool
    void cal_water_add(double currentGallons) const {
        double cap = capacityGallons();
        double needed = cap - currentGallons;
        if (needed < 0) needed = 0;

        cout << "Water needed to completely fill the pool: "
             << needed << " gallons" << endl;
    }

    // Determine time (in minutes) to ADD a certain number of gallons
    void cal_time_add(double gallonsToAdd) const {
        if (fill_rate <= 0) {
            cout << "Cannot fill the pool (fill_rate is zero)." << endl;
            return;
        }
        double minutes = gallonsToAdd / fill_rate;
        cout << "Time to add " << gallonsToAdd << " gallons: "
             << minutes << " minutes" << endl;
    }

    // Determine time (in minutes) to DRAIN a certain number of gallons
    void cal_time_drain(double gallonsToDrain) const {
        if (drain_rate <= 0) {
            cout << "Cannot drain the pool (drain_rate is zero)." << endl;
            return;
        }
        double minutes = gallonsToDrain / drain_rate;
        cout << "Time to drain " << gallonsToDrain << " gallons: "
             << minutes << " minutes" << endl;
    }

    // Add water for a specific amount of time (minutes)
    void add_water(double minutes) const {
        double added = fill_rate * minutes;
        cout << "In " << minutes << " minutes, "
             << added << " gallons of water will be added." << endl;
    }

    // Drain water for a specific amount of time (minutes)
    void drain_water(double minutes) const {
        double drained = drain_rate * minutes;
        cout << "In " << minutes << " minutes, "
             << drained << " gallons of water will be drained." << endl;
    }
};


