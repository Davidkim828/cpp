#include "swimmingPool.h"

int main() {
    swimmingPool pool(30, 15, 6, 300, 200);

    pool.cal_water_add(5000);   // if currently 5000 gallons in pool
    pool.cal_time_add(2000);
    pool.cal_time_drain(1000);

    pool.add_water(10);
    pool.drain_water(5);

    return 0;
}
