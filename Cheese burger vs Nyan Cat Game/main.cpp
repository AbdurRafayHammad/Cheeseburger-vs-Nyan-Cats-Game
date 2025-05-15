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
