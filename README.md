Header file:
Chesseburger.h
//#pragma once
//
//class Cheeseburger {
//public:
//    int x, lives, score, level;
//    bool shieldActive;
//    int speedBoost;
//
//    Cheeseburger();
//
//    void move(char direction);
//    void displayStats() const;
//    void levelUp();
//};

Color.h
//#pragma once
//
//#include <windows.h>
//
//// Color codes
//enum Color {
//    BLACK = 0,
//    BLUE = 1,
//    GREEN = 2,
//    CYAN = 3,
//    RED = 4,
//    MAGENTA = 5,
//    BROWN = 6,
//    LIGHTGRAY = 7,
//    DARKGRAY = 8,
//    LIGHTBLUE = 9,
//    LIGHTGREEN = 10,
//    LIGHTCYAN = 11,
//    LIGHTRED = 12,
//    LIGHTMAGENTA = 13,
//    YELLOW = 14,
//    WHITE = 15
//};
//
//void setColor(Color color);
 Powerup.h
//#pragma once
//#include <string>
//
//class PowerUp {
//public:
//    int x, y;
//    std::string type;
//    bool active;
//
//    PowerUp();
//
//    void spawn(std::string powerType);
//    void fall();
//};

Nyancat.h
//#pragma once
//
//class NyanCat {
//public:
//    int x, y;
//    bool active;
//
//    NyanCat();
//
//    void spawn();
//    void fall();
//};
Friend.h
//#pragma once
//
//class Friend {
//public:
//    int x, y;
//    bool active;
//
//    Friend();
//
//    void spawn();
//    void fall();
//};
Game.h
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
.Cpp files
Game.cpp
//#include "Game.h"
//#include "Color.h"
//#include <iostream>
//#include <fstream>
//#include <conio.h>
//#include <windows.h>
//
//Game::Game(std::string mode) : isRunning(true), isPaused(false), message(""), scoreMultiplier(1), difficulty(mode) {}
//
//std::string Game::getDifficultyLevel() {
//    return difficulty;
//}
//
//int Game::getGameSpeed() {
//    int baseSpeed = (difficulty == "Easy") ? 500 : 300;
//    return baseSpeed - player.speedBoost;
//}
//
//void Game::displayGrid() {
//    system("cls");
//    for (int i = 0; i < GRID_HEIGHT; i++) {
//        for (int j = 0; j < GRID_WIDTH; j++) {
//            if (i == GRID_HEIGHT - 1 && j == player.x) {
//                setColor(YELLOW);
//                std::cout << "C"; // Cheeseburger
//            }
//            else if (isNyanCatAt(i, j)) {
//                setColor(RED);
//                std::cout << "N"; // Nyan Cat
//            }
//            else if (isPowerUpAt(i, j)) {
//                setColor(MAGENTA);
//                std::cout << "P"; // Power-Up
//            }
//            else if (isFriendAt(i, j)) {
//                setColor(GREEN);
//                std::cout << "F"; // Friend
//            }
//            else {
//                setColor(WHITE);
//                std::cout << "."; // Empty Space
//            }
//        }
//        std::cout << std::endl;
//    }
//    setColor(WHITE);
//    std::cout << "Difficulty: " << getDifficultyLevel() << std::endl;
//    player.displayStats();
//    if (!message.empty()) {
//        std::cout << message << std::endl;
//    }
//    std::cout << "Press 's' to activate the power-up you've collected!" << std::endl;
//    std::cout << "Press 'p' to pause/resume the game." << std::endl;
//}
//
//bool Game::isNyanCatAt(int i, int j) {
//    for (int k = 0; k < MAX_NYAN_CATS; k++) {
//        if (nyanCats[k].active && nyanCats[k].x == j && nyanCats[k].y == i)
//            return true;
//    }
//    return false;
//}
//
//bool Game::isPowerUpAt(int i, int j) {
//    for (int k = 0; k < MAX_POWERUPS; k++) {
//        if (powerUps[k].active && powerUps[k].x == j && powerUps[k].y == i)
//            return true;
//    }
//    return false;
//}
//
//bool Game::isFriendAt(int i, int j) {
//    for (int k = 0; k < MAX_FRIENDS; k++) {
//        if (friends[k].active && friends[k].x == j && friends[k].y == i)
//            return true;
//    }
//    return false;
//}
//
//void Game::checkCollisions() {
//    message = ""; // Clear previous messages
//
//    // Check collisions with Nyan Cats
//    for (int k = 0; k < MAX_NYAN_CATS; k++) {
//        if (nyanCats[k].active) {
//            if (nyanCats[k].y == GRID_HEIGHT - 1 && nyanCats[k].x == player.x) {
//                // Nyan Cat collides with Cheeseburger
//                if (!player.shieldActive) {
//                    player.lives--;
//                    message = "Nyan Cat hit! Lives -1";
//                    displayMessageForDuration(1500);
//                    if (player.lives <= 0) {
//                        isRunning = false;
//                        message = "Game Over!";
//                        displayMessageForDuration(1500); // Display "Game Over" for 1.5 seconds
//                        saveHighScore();
//                    }
//                }
//                else {
//                    message = "Shield protected you!";
//                    displayMessageForDuration(1500);
//                }
//                nyanCats[k].active = false;
//            }
//            else if (nyanCats[k].y == GRID_HEIGHT - 1) {
//                // Nyan Cat passes Cheeseburger
//                player.score += 1;
//                nyanCats[k].active = false;
//                if (player.score % 10 == 0) {
//                    player.levelUp();
//                    message = "Level Up! Reached Level " + std::to_string(player.level);
//                    displayMessageForDuration(1500);
//                }
//            }
//        }
//    }
//
//    // Check collisions with Power-Ups
//    for (int k = 0; k < MAX_POWERUPS; k++) {
//        if (powerUps[k].active && powerUps[k].y == GRID_HEIGHT - 1 && powerUps[k].x == player.x) {
//            if (powerUps[k].type == "Score Multiplier") {
//                scoreMultiplier = 2;
//                message = "Collected Power-Up: Score Multiplier!";
//                displayMessageForDuration(1500); // Display for 1.5 seconds
//            }
//            else if (powerUps[k].type == "Shield") {
//                player.shieldActive = true;
//                message = "Collected Power-Up: Shield!";
//                displayMessageForDuration(1500); // Display for 1.5 seconds
//            }
//            else if (powerUps[k].type == "Speed Boost") {
//                player.speedBoost += 50;
//                message = "Collected Power-Up: Speed Boost!";
//                displayMessageForDuration(1500); // Display for 1.5 seconds
//            }
//            powerUps[k].active = false;
//        }
//    }
//
//    // Check collisions with Friends
//    for (int k = 0; k < MAX_FRIENDS; k++) {
//        if (friends[k].active && friends[k].y == GRID_HEIGHT - 1 && friends[k].x == player.x) {
//            player.lives++;
//            message = "Friend gave you an extra life!";
//            displayMessageForDuration(1500); // Display for 1.5 seconds
//            friends[k].active = false;
//        }
//    }
//}
//
//void Game::activatePowerUp() {
//    if (scoreMultiplier > 1) {
//        player.score *= scoreMultiplier;
//        scoreMultiplier = 1;
//        message = "Score Multiplier Activated!";
//        displayMessageForDuration(1500); // Display for 1.5 seconds
//    }
//}
//
//void Game::spawnObjects() {
//    if (rand() % 20 == 0) {
//        for (int k = 0; k < MAX_NYAN_CATS; k++) {
//            if (!nyanCats[k].active) {
//                nyanCats[k].spawn();
//                break;
//            }
//        }
//    }
//    if (rand() % 30 == 0) {
//        for (int k = 0; k < MAX_POWERUPS; k++) {
//            if (!powerUps[k].active) {
//                std::string powerType = (rand() % 3 == 0) ? "Shield" : (rand() % 2 == 0) ? "Speed Boost" : "Score Multiplier";
//                powerUps[k].spawn(powerType);
//                break;
//            }
//        }
//    }
//    if (rand() % 40 == 0) {
//        for (int k = 0; k < MAX_FRIENDS; k++) {
//            if (!friends[k].active) {
//                friends[k].spawn();
//                break;
//            }
//        }
//    }
//}
//
//void Game::displayMessageForDuration(int duration) {
//    displayGrid();
//    Sleep(duration);
//    message = ""; // Clear the message after duration
//}
//
//void Game::saveHighScore() {
//    std::ifstream scoreFile("scores.txt");
//    std::ofstream tempFile("temp.txt");
//    std::string line;
//    bool scoreAdded = false;
//
//    while (std::getline(scoreFile, line)) {
//        int currentScore;
//        sscanf_s(line.c_str(), "%d", &currentScore);
//        if (player.score > currentScore && !scoreAdded) {
//            tempFile << player.score << std::endl;
//            scoreAdded = true;
//        }
//        tempFile << line << std::endl;
//    }
//
//    if (!scoreAdded) {
//        tempFile << player.score << std::endl;
//    }
//
//    scoreFile.close();
//    tempFile.close();
//
//    remove("scores.txt");
//}
//
//void Game::run() {
//    while (isRunning) {
//        if (!isPaused) {
//            displayGrid();
//            if (_kbhit()) {
//                char input = _getch();
//                if (input == 'a' || input == 'd') player.move(input);
//                else if (input == 's') activatePowerUp();
//                else if (input == 'p') isPaused = !isPaused;
//            }
//
//            spawnObjects();
//            checkCollisions();
//
//            for (int k = 0; k < MAX_NYAN_CATS; k++) nyanCats[k].fall();
//            for (int k = 0; k < MAX_POWERUPS; k++) powerUps[k].fall();
//            for (int k = 0; k < MAX_FRIENDS; k++) friends[k].fall();
//
//            Sleep(getGameSpeed());
//        }
//        else {
//            displayGrid();
//            std::cout << "Game Paused. Press 'p' to resume." << std::endl;
//            if (_kbhit()) {
//                char input = _getch();
//                if (input == 'p') isPaused = !isPaused;
//            }
//            Sleep(100);
//        }
//    }
//    displayGrid();
//    std::cout << "Game Over! Final Score: " << player.score << ", Level Reached: " << player.level << std::endl;
//    std::cout << "Press Enter to return to the main menu..." << std::endl;
//    std::cin.ignore();
//    std::cin.get();
//}

Cheeseburger.cpp
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
Color.cpp
//#include "Color.h"
//
//void setColor(Color color) {
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
Friend.cpp
//#include "Friend.h"
//#include <cstdlib>
//
//const int GRID_HEIGHT = 15;
//
//Friend::Friend() : x(0), y(0), active(false) {}
//
//void Friend::spawn() {
//    x = rand() % GRID_HEIGHT;
//    y = 0;
//    active = true;
//}
//
//void Friend::fall() {
//    if (active) y++;
//    if (y >= GRID_HEIGHT) active = false;
//}
Nyancat.cpp
//#include "NyanCat.h"
//#include <cstdlib>
//
//const int GRID_HEIGHT = 15;
//
//NyanCat::NyanCat() : x(0), y(0), active(false) {}
//
//void NyanCat::spawn() {
//    x = rand() % GRID_HEIGHT;
//    y = 0;
//    active = true;
//}
//
//void NyanCat::fall() {
//    if (active) y++;
//    if (y >= GRID_HEIGHT) active = false;
//}
Powerup.cpp
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

Main.cpp
//#include "Game.h"
//#include "Color.h"
//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include<fstream>
//void displayMainMenu() {
//    setColor(LIGHTCYAN);
//    std::cout << "===================================" << std::endl;
//    setColor(LIGHTGREEN);
//    std::cout << "          GAME PROJECT             " << std::endl;
//    setColor(LIGHTCYAN);
//    std::cout << "===================================" << std::endl;
//    setColor(WHITE);
//    std::cout << "1. Start Game" << std::endl;
//    std::cout << "2. Instructions" << std::endl;
//    std::cout << "3. Highest Score" << std::endl;
//    std::cout << "4. About Us" << std::endl;
//    std::cout << "5. Exit" << std::endl;
//    setColor(LIGHTCYAN);
//    std::cout << "===================================" << std::endl;
//    setColor(WHITE);
//    std::cout << "Enter your choice: ";
//}
//
//void displayInstructions() {
//    setColor(LIGHTGREEN);
//    std::cout << "Instructions:" << std::endl;
//    setColor(WHITE);
//    std::cout << "Use 'a' to move left and 'd' to move right." << std::endl;
//    std::cout << "Avoid the Nyan Cats and collect Power-Ups and Friends." << std::endl;
//    std::cout << "Press 's' to activate the power-up you've collected." << std::endl;
//    std::cout << "Press 'p' to pause/resume the game." << std::endl;
//    std::cout << "Press Enter to return to the main menu..." << std::endl;
//    std::cin.ignore();
//    std::cin.get();
//}
//
//void displayHighestScores() {
//    std::ifstream scoreFile("scores.txt");
//    if (scoreFile.is_open()) {
//        std::string line;
//        setColor(LIGHTMAGENTA);
//        std::cout << "Highest Scores:" << std::endl;
//        setColor(WHITE);
//        while (std::getline(scoreFile, line)) {
//            std::cout << line << std::endl;
//        }
//        scoreFile.close();
//    }
//    else {
//        std::cout << "No scores available." << std::endl;
//    }
//    std::cout << "Press Enter to return to the main menu..." << std::endl;
//    std::cin.ignore();
//    std::cin.get();
//}
//
//void displayAboutUs() {
//    setColor(LIGHTCYAN);
//    std::cout << "================= ABOUT US =====================" << std::endl;
//    setColor(WHITE);
//    std::cout << "1. Abdur Rafay 23F-0622" << std::endl;
//    std::cout << "2. Furqan Ahmed 23F-0596" << std::endl;
//    setColor(LIGHTCYAN);
//    std::cout << "================================================" << std::endl;
//    setColor(WHITE);
//    std::cout << "Press Enter to return to the main menu..." << std::endl;
//    std::cin.ignore();
//    std::cin.get();
//}
//
//std::string selectDifficulty() {
//    std::string difficulty;
//    setColor(LIGHTGREEN);
//    std::cout << "Select Difficulty:" << std::endl;
//    setColor(WHITE);
//    std::cout << "1. Easy" << std::endl;
//    std::cout << "2. Hard" << std::endl;
//    setColor(LIGHTGREEN);
//    std::cout << "Select an option: ";
//    setColor(WHITE);
//    int choice;
//    std::cin >> choice;
//    std::cin.ignore(); // Ignore the newline character left in the input buffer
//    if (choice == 1) {
//        difficulty = "Easy";
//    }
//    else {
//        difficulty = "Hard";
//    }
//    return difficulty;
//}
//
//int main() {
//    srand(static_cast<unsigned int>(time(0)));
//
//    int choice;
//    while (true) {
//        system("cls");
//        displayMainMenu();
//        std::cin >> choice;
//        std::cin.ignore(); // Ignore the newline character left in the input buffer
//
//        switch (choice) {
//        case 1: {
//            std::string difficulty = selectDifficulty();
//            Game game(difficulty);
//            game.run();
//            break;
//        }
//        case 2:
//            displayInstructions();
//            break;
//        case 3:
//            displayHighestScores();
//            break;
//        case 4:
//            displayAboutUs();
//            break;
//        case 5:
//            return 0;
//        default:
//            std::cout << "Invalid choice. Please try again." << std::endl;
//            Sleep(1000);
//        }
//    }
//
//    return 0;
//}

