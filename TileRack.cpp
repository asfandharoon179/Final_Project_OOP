#include "TileRack.h"
#include "GameException.h"
#include <sstream>

TileRack::TileRack() : tiles(15), count(0) {
}

TileRack::TileRack(const TileRack& other) : tiles(other.tiles), count(other.count) {
}

TileRack& TileRack::operator=(const TileRack& other) {
    if (this != &other) {
        tiles = other.tiles;
        count = other.count;
    }
    return *this;
}

TileRack::~TileRack() {
}

void TileRack::addTile(char letter) {
    if (count >= 15) {
        throw RackFullException();
    }
    tiles[count] = letter;
    count++;
}

void TileRack::removeTile(char letter) {
    for (int i = 0; i < count; ++i) {
        if (tiles[i] == letter) {
            for (int j = i; j < count - 1; ++j) {
                tiles[j] = tiles[j + 1];
            }
            count--;
            return;
        }
    }
    throw RackEmptyException();
}

std::string TileRack::displayRack() const {
    std::stringstream output;
    if (count == 0) {
        return "(empty)";
    }

    output << "(";
    for (int i = 0; i < count; ++i) {
        output << tiles[i];
        if (i + 1 < count) {
            output << " ";
        }
    }
    output << ")";
    return output.str();
}

bool TileRack::isFull() const {
    return count >= 15;
}

bool TileRack::isEmpty() const {
    return count == 0;
}

int TileRack::getCount() const {
    return count;
}

char TileRack::getTileAt(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Tile index is invalid.");
    }
    return tiles[index];
}

TileRack TileRack::operator+(const TileRack& other) const {
    TileRack combined;
    for (int i = 0; i < count; ++i) {
        combined.addTile(tiles[i]);
    }
    for (int i = 0; i < other.count; ++i) {
        combined.addTile(other.tiles[i]);
    }
    return combined;
}

bool TileRack::operator==(const TileRack& other) const {
    if (count != other.count) {
        return false;
    }
    for (int i = 0; i < count; ++i) {
        if (tiles[i] != other.tiles[i]) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const TileRack& rack) {
    out << rack.displayRack();
    return out;
}
