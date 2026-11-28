#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "DynamicArray.h"
#include <iostream>
#include <string>

struct Tile {
    char letter;
    int position;
    bool filled;

    Tile();
    Tile(char newLetter, int newPosition);
    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

class Scrabble {
private:
    DynamicArray<Tile> wordOne;
    DynamicArray<Tile> wordTwo;

public:
    Scrabble();
    Scrabble(const Scrabble& other);
    Scrabble& operator=(const Scrabble& other);
    ~Scrabble();

    void placeLetter(int rowNumber, int position, char letter);
    bool revealLetter(int rowNumber, int position) const;
    std::string getWordString(int rowNumber) const;
    void showBoard() const;
    bool isRowComplete(int rowNumber) const;
    bool isBoardReady() const;
    void resetBoard();

    friend std::ostream& operator<<(std::ostream& out, const Scrabble& board);
};

#endif
