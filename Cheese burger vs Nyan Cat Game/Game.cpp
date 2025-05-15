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
