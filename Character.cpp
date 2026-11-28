#include "Character.h"
Character::Character() : name("Unknown"), role("Unknown"), nationality("Unknown"), isCulprit(false) {
}

Character::Character(const std::string& personName, const std::string& personRole,
                     const std::string& personNationality, bool culpritStatus)
    : name(personName), role(personRole), nationality(personNationality), isCulprit(culpritStatus) {
}

std::string Character::getName() const {
    return name;
}

std::string Character::getRole() const {
    return role;
}

std::string Character::getNationality() const {
    return nationality;
}

bool Character::getIsCulprit() const {
    return isCulprit;
}

void Character::setRole(const std::string& newRole) {
    role = newRole;
}

void Character::setIsCulprit(bool culpritStatus) {
    isCulprit = culpritStatus;
}

std::ostream& operator<<(std::ostream& out, const Character& person) {
    out << person.name << " (" << person.role << ", " << person.nationality << ")";
    return out;
}
