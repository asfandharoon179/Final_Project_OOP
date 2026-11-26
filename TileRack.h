#ifndef TILE_RACK_H
#define TILE_RACK_H

#include "DynamicArray.h"
#include <string>

class TileRack {
private:
    DynamicArray<char> tiles;
    int count;

public:
    TileRack();
    TileRack(const TileRack& other);
    TileRack& operator=(const TileRack& other);
    ~TileRack();

    void addTile(char letter);
    void removeTile(char letter);
    std::string displayRack() const;
    bool isFull() const;
    bool isEmpty() const;
    int getCount() const;
    char getTileAt(int index) const;
    TileRack operator+(const TileRack& other) const;
    bool operator==(const TileRack& other) const;

    friend std::ostream& operator<<(std::ostream& out, const TileRack& rack);
};

#endif
