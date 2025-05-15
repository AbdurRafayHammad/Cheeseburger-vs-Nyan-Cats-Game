//#include "Cheeseburger.h"
//#include "Color.h"
//#include <iostream>
//
//const int GRID_WIDTH = 20;
//
//Cheeseburger::Cheeseburger() : x(GRID_WIDTH / 2), lives(3), score(0), level(1), shieldActive(false), speedBoost(0) {}
//
//void Cheeseburger::move(char direction) {
//    if (direction == 'a' && x > 0) x--; // Move left
//    if (direction == 'd' && x < GRID_WIDTH - 1) x++; // Move right
//}
//
//void Cheeseburger::displayStats() const {
//    setColor(LIGHTGREEN);
//    std::cout << "Lives: " << lives << " | ";
//    setColor(LIGHTBLUE);
//    std::cout << "Score: " << score << " | ";
//    setColor(LIGHTRED);
//    std::cout << "Level: " << level << std::endl;
//    setColor(WHITE);
//}
//
//void Cheeseburger::levelUp() {
//    level++;
//    if (level % 2 == 0) {
//        lives++;
//    }
//    if (level % 3 == 0) {
//        speedBoost += 50;
//    }
//}
