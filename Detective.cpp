#include "Detective.h"

Detective::Detective() : Character("Detective", "Player", "Unknown", false), credibility(100), turnsUsed(0) {
}

Detective::Detective(const std::string& detectiveName)
    : Character(detectiveName, "Detective", "Unknown", false), credibility(100), turnsUsed(0) {
}

void Detective::display() const {
    std::cout << "Detective: " << name << "\n";
    std::cout << "Credibility: " << credibility << "\n";
    std::cout << "Turns used: " << turnsUsed << "\n";
}

std::string Detective::getIdentity() const {
    return name;
}

int Detective::getCredibility() const {
    return credibility;
}

int Detective::getTurnsUsed() const {
    return turnsUsed;
}

void Detective::setCredibility(int newCredibility) {
    credibility = newCredibility;
}

void Detective::setTurnsUsed(int currentTurns) {
    turnsUsed = currentTurns;
}

void Detective::increaseTurn() {
    turnsUsed++;
}

TileRack& Detective::getRack() {
    return rack;
}

void Detective::addLetterToRack(char letter) {
    rack.addTile(letter);
}

bool Detective::hasRackSpace() const {
    return !rack.isFull();
}
