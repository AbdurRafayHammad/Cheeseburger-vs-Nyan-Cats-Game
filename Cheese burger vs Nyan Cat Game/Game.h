//#pragma once
//
//#include "Cheeseburger.h"
//#include "NyanCat.h"
//#include "PowerUp.h"
//#include "Friend.h"
//#include <string>
//
//const int GRID_WIDTH = 20;
//const int GRID_HEIGHT = 15;
//const int MAX_NYAN_CATS = 10;
//const int MAX_POWERUPS = 5;
//const int MAX_FRIENDS = 3;
//const int MAX_LEVEL = 5;
//
//class Game {
//private:
//    Cheeseburger player;
//    NyanCat nyanCats[MAX_NYAN_CATS];
//    PowerUp powerUps[MAX_POWERUPS];
//    Friend friends[MAX_FRIENDS];
//    bool isRunning;
//    bool isPaused;
//    std::string message;
//    int scoreMultiplier;
//    std::string difficulty;
//
//    std::string getDifficultyLevel();
//    int getGameSpeed();
//    void displayGrid();
//    bool isNyanCatAt(int i, int j);
//    bool isPowerUpAt(int i, int j);
//    bool isFriendAt(int i, int j);
//    void checkCollisions();
//    void activatePowerUp();
//    void spawnObjects();
//    void displayMessageForDuration(int duration);
//    void saveHighScore();
//
//public:
//    Game(std::string mode);
//    void run();
//};
