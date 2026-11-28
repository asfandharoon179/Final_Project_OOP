#ifndef SUSPECT_H
#define SUSPECT_H

#include "Character.h"

class Victim : public Character {
public:
    Victim();
    Victim(const std::string& personName, const std::string& personNationality);
    void display() const override;
    std::string getIdentity() const override;
};

class Suspect : public virtual Character {
protected:
    bool interviewed;
    char clueLetter;
    int cluePosition;
    std::string wordOne;
    std::string wordTwo;

public:
    Suspect();
    Suspect(const std::string& personName, const std::string& personRole,
            const std::string& personNationality, bool culpritStatus = false);

    void setClue(char letter, int pos, const std::string& firstWord, const std::string& secondWord);
    char getClueLetter() const;
    int getCluePosition() const;
    std::string getWordOne() const;
    std::string getWordTwo() const;
    bool isInterviewed() const;
    void setInterviewed(bool done);
    void display() const override = 0;
    std::string getIdentity() const override = 0;
};

class BusinessRelations : public virtual Suspect {
public:
    BusinessRelations();
    BusinessRelations(const std::string& personName, const std::string& personNationality,
                      bool culpritStatus = false);
    void display() const override = 0;
    std::string getIdentity() const override = 0;
};

class HouseHelp : public virtual Suspect {
public:
    HouseHelp();
    HouseHelp(const std::string& personName, const std::string& personNationality,
              bool culpritStatus = false);
    void display() const override = 0;
    std::string getIdentity() const override = 0;
};

class CloseRelations : public virtual Suspect {
public:
    CloseRelations();
    CloseRelations(const std::string& personName, const std::string& personNationality,
                   bool culpritStatus = false);
    void display() const override = 0;
    std::string getIdentity() const override = 0;
};

class Cook : public HouseHelp {
public:
    Cook();
    Cook(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

class Guard : public HouseHelp {
public:
    Guard();
    Guard(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

class Servant : public HouseHelp {
public:
    Servant();
    Servant(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

class PartnerOne : public BusinessRelations {
public:
    PartnerOne();
    PartnerOne(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

class PartnerTwo : public BusinessRelations {
public:
    PartnerTwo();
    PartnerTwo(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

class PersonalAssistant : public BusinessRelations, public CloseRelations {
public:
    PersonalAssistant();
    PersonalAssistant(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

class OwnerChild : public CloseRelations {
public:
    OwnerChild();
    OwnerChild(const std::string& personName, const std::string& personNationality, bool culpritStatus = false);
    void display() const override;
    std::string getIdentity() const override;
};

#endif
