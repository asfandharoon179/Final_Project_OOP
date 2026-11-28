#include "Scrabble.h"
#include "GameException.h"
#include <sstream>

Tile::Tile() : letter(' '), position(0), filled(false) {
}

Tile::Tile(char newLetter, int newPosition) : letter(newLetter), position(newPosition), filled(newLetter != ' ') {
}

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
    out << tile.letter;
    return out;
}

Scrabble::Scrabble() : wordOne(7), wordTwo(8) {
    wordOne.fill(Tile(' ', 0));
    wordTwo.fill(Tile(' ', 0));
}

Scrabble::Scrabble(const Scrabble& other) : wordOne(other.wordOne), wordTwo(other.wordTwo) {
}

Scrabble& Scrabble::operator=(const Scrabble& other) {
    if (this != &other) {
        wordOne = other.wordOne;
        wordTwo = other.wordTwo;
    }
    return *this;
}

Scrabble::~Scrabble() {
}

void Scrabble::placeLetter(int rowNumber, int position, char letter) {
    if (position < 1) {
        throw InvalidPositionException();
    }

    if (rowNumber == 1) {
        if (position > wordOne.getSize()) {
            throw InvalidPositionException();
        }
        wordOne[position - 1] = Tile(letter, position);
    } else if (rowNumber == 2) {
        if (position > wordTwo.getSize()) {
            throw InvalidPositionException();
        }
        wordTwo[position - 1] = Tile(letter, position);
    } else {
        throw InvalidPositionException();
    }
}

bool Scrabble::revealLetter(int rowNumber, int position) const {
    if (rowNumber == 1) {
        if (position < 1 || position > wordOne.getSize()) {
            return false;
        }
        return wordOne[position - 1].filled;
    }
    if (rowNumber == 2) {
        if (position < 1 || position > wordTwo.getSize()) {
            return false;
        }
        return wordTwo[position - 1].filled;
    }
    return false;
}

std::string Scrabble::getWordString(int rowNumber) const {
    std::string result;
    if (rowNumber == 1) {
        for (int i = 0; i < wordOne.getSize(); ++i) {
            result += wordOne[i].letter;
        }
    } else if (rowNumber == 2) {
        for (int i = 0; i < wordTwo.getSize(); ++i) {
            result += wordTwo[i].letter;
        }
    }
    return result;
}

void Scrabble::showBoard() const {
    std::cout << "Scrabble:\n";
    std::cout << "Word 1: ";
    for (int i = 0; i < wordOne.getSize(); ++i) {
        std::cout << "[" << wordOne[i].letter << "] ";
    }
    std::cout << "\nWord 2: ";
    for (int i = 0; i < wordTwo.getSize(); ++i) {
        std::cout << "[" << wordTwo[i].letter << "] ";
    }
    std::cout << "\n";
}

bool Scrabble::isRowComplete(int rowNumber) const {
    if (rowNumber == 1) {
        for (int i = 0; i < wordOne.getSize(); ++i) {
            if (!wordOne[i].filled) {
                return false;
            }
        }
        return true;
    }
    if (rowNumber == 2) {
        for (int i = 0; i < wordTwo.getSize(); ++i) {
            if (!wordTwo[i].filled) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Scrabble::isBoardReady() const {
    return isRowComplete(1) && isRowComplete(2);
}

void Scrabble::resetBoard() {
    wordOne.fill(Tile(' ', 0));
    wordTwo.fill(Tile(' ', 0));
}

std::ostream& operator<<(std::ostream& out, const Scrabble& board) {
    board.showBoard();
    return out;
}
