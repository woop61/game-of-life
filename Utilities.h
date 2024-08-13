#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

const std::vector<std::string> startMessages = {
        "Welcome to game of life!\n",
        "Please, enter one of the commands:\n",
        "S - to start the game.\n",
        "Q - to quit from the game.\n",
};


namespace consoleCommand {

    /**
 * solves size of console's window and sets the cursor there
 */
    int getCentreOfLine(const std::string& text){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

        int centerPos = columns / 2;

        int startPos = centerPos - text.length() / 2;
        COORD coord = { static_cast<SHORT>(startPos), static_cast<SHORT>(csbi.dwCursorPosition.Y) };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        return startPos;
    }


    /**
 * @brief clear console screen when called
 */
    void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
    }

    /**
     * @brief print text at the centre of line to both sides
     * @param text text to print
     */
    void printCenteredText(const std::string& text) {
        int startPos = consoleCommand::getCentreOfLine(text);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int left = text.length() / 2;
        int right = left;
         while (left >= 0 || right < text.length()) {
             if (left >= 0) {
                 COORD leftCoord = {static_cast<SHORT>(startPos + left), static_cast<SHORT>(csbi.dwCursorPosition.Y)};
                 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), leftCoord);
                 std::cout << text[left];
                 left--;
             }

             if (right < text.length()) {
                 COORD rightCoord = {static_cast<SHORT>(startPos + right), static_cast<SHORT>(csbi.dwCursorPosition.Y)};
                 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rightCoord);
                 std::cout << text[right];
                 right++;
             }
         }
    }

    void printStartScreen(){
        clearScreen();
        for (auto message: startMessages) {
            printCenteredText(message);
        }
    }



}