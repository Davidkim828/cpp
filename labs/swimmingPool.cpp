#include <iostream>
using namespace std;

class swimmingPool {
private:
    double length;      // in feet
    double width;       // in feet
    double depth;       // in feet
    double fill_rate;   // in gallons per minute
    double drain_rate;  // in gallons per minute
    double current_volume; // current water in gallons

    static constexpr double GALLONS_PER_CUBIC_FOOT = 7.48;

public:
    // ----- Constructors -----
    swimmingPool() {
        length = width = depth = fill_rate = drain_rate = current_volume = 0;
    }

    swimmingPool(double l, double w, double d, double fRate, double dRate, double current = 0) {
        length = l;
        width = w;
        depth = d;
        fill_rate = fRate;
        drain_rate = dRate;
        current_volume = current;
    }

    // ----- Calculate how much water to add to reach a target level -----
    void cal_water_add(double targetGallons) {
        double capacity = length * width * depth * GALLONS_PER_CUBIC_FOOT;
        if (targetGallons > capacity)
            cout << "Target exceeds pool capacity.\n";
        else
            cout << "Water needed to reach target: "
                 << targetGallons - current_volume << " gallons.\n";
    }

    // ----- Calculate time required to add a certain amount of water -----
    void cal_time_add(double gallonsToAdd) {
        if (fill_rate <= 0) {
            cout << "Cannot fill — fill rate is zero.\n";
            return;
        }
        cout << "Time required to add " << gallonsToAdd << " gallons: "
             << gallonsToAdd / fill_rate << " minutes.\n";
    }

    // ----- Calculate time required to drain a certain amount of water -----
    void cal_time_drains(double gallonsToDrain) {
        if (drain_rate <= 0) {
            cout << "Cannot drain — drain rate is zero.\n";
            return;
        }
        cout << "Time required to drain " << gallonsToDrain << " gallons: "
             << gallonsToDrain / drain_rate << " minutes.\n";
    }

    // ----- Add water for a certain time -----
    void add_water(double minutes) {
        double added = fill_rate * minutes;
        double capacity = length * width * depth * GALLONS_PER_CUBIC_FOOT;
        current_volume += added;
        if (current_volume > capacity) current_volume = capacity;
        cout << "Water added for " << minutes << " minutes. Current volume: "
             << current_volume << " gallons.\n";
    }

    // ----- Drain water for a certain time -----
    void drain_water(double minutes) {
        double drained = drain_rate * minutes;
        current_volume -= drained;
        if (current_volume < 0) current_volume = 0;
        cout << "Water drained for " << minutes << " minutes. Current volume: "
             << current_volume << " gallons.\n";
    }

    // ----- Optional: show pool status -----
    void displayStatus() const {
        cout << "\n--- Pool Status ---\n";
        cout << "Dimensions: " << length << " x " << width << " x " << depth << " ft\n";
        cout << "Fill rate: " << fill_rate << " gpm, Drain rate: " << drain_rate << " gpm\n";
        cout << "Current volume: " << current_volume << " gallons\n";
    }
};

// ----- Example main -----
int main() {
    swimmingPool pool(30, 15, 6, 300, 200, 4000);
    pool.displayStatus();

    pool.cal_water_add(7000);
    pool.cal_time_add(2000);
    pool.cal_time_drains(1000);

    pool.add_water(10);
    pool.drain_water(5);
    pool.displayStatus();

    return 0;
}
