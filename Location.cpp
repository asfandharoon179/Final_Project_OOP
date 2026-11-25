#include "Location.h"

Location::Location() : name("Unknown"), boardPosition(0), letter(' '), searched(false) {
}

Location::Location(const std::string& placeName, int placePosition, char placeLetter)
    : name(placeName), boardPosition(placePosition), letter(placeLetter), searched(false) {
}
