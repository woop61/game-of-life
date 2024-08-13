#pragma once
#include <iostream>
#include <cstdlib>
#include "Utilities.h"
#include "GameBoard.h"
#include <string>

class Game {
public:
    Game()= default;
    bool game() const;
private:
    GameBoard Board;
};

bool Game::game() const {
    consoleCommand::printStartScreen();
    char input;
    do {
        std::cin >> input;
        if (input == 'S'){
            Board.start;
        }
        else if (input == 'Q'){
            return false;
        } else {
            consoleCommand::printCenteredText("Invalid command! Please try again!\n");
        }
    } while (true);
}


