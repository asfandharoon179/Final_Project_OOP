#ifndef DETECTIVE_H
#define DETECTIVE_H

#include "Character.h"
#include "TileRack.h"

class Detective : public Character {
private:
    int credibility;
    int turnsUsed;
    TileRack rack;

public:
    Detective();
    Detective(const std::string& detectiveName);

    void display() const override;
    std::string getIdentity() const override;

    int getCredibility() const;
    int getTurnsUsed() const;
    void setCredibility(int newCredibility);
    void setTurnsUsed(int currentTurns);
    void increaseTurn();
    TileRack& getRack();
    void addLetterToRack(char letter);
    bool hasRackSpace() const;
};

#endif
