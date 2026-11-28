#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    std::string role;
    std::string nationality;
    bool isCulprit;

public:
    Character();
    Character(const std::string& personName, const std::string& personRole,
             const std::string& personNationality, bool culpritStatus);
    virtual ~Character() = default;

    virtual void display() const = 0;
    virtual std::string getIdentity() const = 0;

    std::string getName() const;
    std::string getRole() const;
    std::string getNationality() const;
    bool getIsCulprit() const;
    void setRole(const std::string& newRole);
    void setIsCulprit(bool culpritStatus);

    friend std::ostream& operator<<(std::ostream& out, const Character& person);
    friend class GameEngine;
};

#endif
