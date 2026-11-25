#ifndef LOCATION_H
#define LOCATION_H

#include <string>

struct Location {
    std::string name;
    int boardPosition;
    char letter;
    bool searched;

    Location();
    Location(const std::string& placeName, int placePosition, char placeLetter);
};

#endif
