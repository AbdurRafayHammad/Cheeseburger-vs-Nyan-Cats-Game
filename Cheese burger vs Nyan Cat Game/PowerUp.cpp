//#include "PowerUp.h"
//#include <cstdlib>
//
//const int GRID_HEIGHT = 15;
//
//PowerUp::PowerUp() : x(0), y(0), type("Score Boost"), active(false) {}
//
//void PowerUp::spawn(std::string powerType) {
//    x = rand() % GRID_HEIGHT;
//    y = 0;
//    type = powerType;
//    active = true;
//}
//
//void PowerUp::fall() {
//    if (active) y++;
//    if (y >= GRID_HEIGHT) active = false;
//}
