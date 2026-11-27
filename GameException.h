#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <exception>
#include <string>

class GameException : public std::exception {
private:
    std::string message;

public:
    explicit GameException(const std::string& errorMessage) : message(errorMessage) {
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidPositionException : public GameException {
public:
    InvalidPositionException() : GameException("The selected position is not valid.") {
    }
};

class RackFullException : public GameException {
public:
    RackFullException() : GameException("The tile rack is already full.") {
    }
};

class RackEmptyException : public GameException {
public:
    RackEmptyException() : GameException("The tile rack is empty.") {
    }
};

class InvalidWordException : public GameException {
public:
    InvalidWordException() : GameException("The word is not valid for this game.") {
    }
};

#endif
