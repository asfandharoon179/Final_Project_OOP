#include "Suspect.h"

Victim::Victim() : Character("Unknown Victim", "Victim", "Unknown", false) {
}

Victim::Victim(const std::string& personName, const std::string& personNationality)
    : Character(personName, "Victim", personNationality, false) {
}

void Victim::display() const {
    std::cout << "Victim: " << name << "\n";
}

std::string Victim::getIdentity() const {
    return name;
}

Suspect::Suspect() : Character("Unknown", "Suspect", "Unknown", false), interviewed(false), clueLetter(' '), cluePosition(0), wordOne(""), wordTwo("") {
}

Suspect::Suspect(const std::string& personName, const std::string& personRole,
                 const std::string& personNationality, bool culpritStatus)
    : Character(personName, personRole, personNationality, culpritStatus), interviewed(false), clueLetter(' '), cluePosition(0), wordOne(""), wordTwo("") {
}

void Suspect::setClue(char letter, int pos, const std::string& firstWord, const std::string& secondWord) {
    clueLetter = letter;
    cluePosition = pos;
    wordOne = firstWord;
    wordTwo = secondWord;
}

char Suspect::getClueLetter() const {
    return clueLetter;
}

int Suspect::getCluePosition() const {
    return cluePosition;
}

std::string Suspect::getWordOne() const {
    return wordOne;
}

std::string Suspect::getWordTwo() const {
    return wordTwo;
}

bool Suspect::isInterviewed() const {
    return interviewed;
}

void Suspect::setInterviewed(bool done) {
    interviewed = done;
}

BusinessRelations::BusinessRelations() : Suspect() {
    role = "Business Relation";
}

BusinessRelations::BusinessRelations(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Business Relation", personNationality, culpritStatus), Suspect(personName, "Business Relation", personNationality, culpritStatus) {
}

HouseHelp::HouseHelp() : Suspect() {
    role = "House Help";
}

HouseHelp::HouseHelp(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "House Help", personNationality, culpritStatus), Suspect(personName, "House Help", personNationality, culpritStatus) {
}

CloseRelations::CloseRelations() : Suspect() {
    role = "Close Relation";
}

CloseRelations::CloseRelations(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Close Relation", personNationality, culpritStatus), Suspect(personName, "Close Relation", personNationality, culpritStatus) {
}

Cook::Cook() : Suspect("Cook", "Cook", "Unknown", false), HouseHelp("Cook", "Unknown", false) {
    role = "Cook";
}

Cook::Cook(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Cook", personNationality, culpritStatus), Suspect(personName, "Cook", personNationality, culpritStatus), HouseHelp(personName, personNationality, culpritStatus) {
}

void Cook::display() const {
    std::cout << "Cook: " << name << "\n";
}

std::string Cook::getIdentity() const {
    return name;
}

Guard::Guard() : Suspect("Guard", "Guard", "Unknown", false), HouseHelp("Guard", "Unknown", false) {
    role = "Guard";
}

Guard::Guard(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Guard", personNationality, culpritStatus), Suspect(personName, "Guard", personNationality, culpritStatus), HouseHelp(personName, personNationality, culpritStatus) {
}

void Guard::display() const {
    std::cout << "Guard: " << name << "\n";
}

std::string Guard::getIdentity() const {
    return name;
}

Servant::Servant() : Suspect("Servant", "Servant", "Unknown", false), HouseHelp("Servant", "Unknown", false) {
    role = "Servant";
}

Servant::Servant(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Servant", personNationality, culpritStatus), Suspect(personName, "Servant", personNationality, culpritStatus), HouseHelp(personName, personNationality, culpritStatus) {
}

void Servant::display() const {
    std::cout << "Servant: " << name << "\n";
}

std::string Servant::getIdentity() const {
    return name;
}

PartnerOne::PartnerOne() : Suspect("Partner One", "Partner_1", "Unknown", false), BusinessRelations("Partner One", "Unknown", false) {
    role = "Partner_1";
}

PartnerOne::PartnerOne(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Partner_1", personNationality, culpritStatus), Suspect(personName, "Partner_1", personNationality, culpritStatus), BusinessRelations(personName, personNationality, culpritStatus) {
}

void PartnerOne::display() const {
    std::cout << "Partner One: " << name << "\n";
}

std::string PartnerOne::getIdentity() const {
    return name;
}

PartnerTwo::PartnerTwo() : Suspect("Partner Two", "Partner_2", "Unknown", false), BusinessRelations("Partner Two", "Unknown", false) {
    role = "Partner_2";
}

PartnerTwo::PartnerTwo(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Partner_2", personNationality, culpritStatus), Suspect(personName, "Partner_2", personNationality, culpritStatus), BusinessRelations(personName, personNationality, culpritStatus) {
}

void PartnerTwo::display() const {
    std::cout << "Partner Two: " << name << "\n";
}

std::string PartnerTwo::getIdentity() const {
    return name;
}

PersonalAssistant::PersonalAssistant() : Suspect("PA", "PA", "Unknown", false), BusinessRelations("PA", "Unknown", false), CloseRelations("PA", "Unknown", false) {
    role = "PA";
}

PersonalAssistant::PersonalAssistant(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "PA", personNationality, culpritStatus), Suspect(personName, "PA", personNationality, culpritStatus), BusinessRelations(personName, personNationality, culpritStatus), CloseRelations(personName, personNationality, culpritStatus) {
}

void PersonalAssistant::display() const {
    std::cout << "PA: " << name << "\n";
}

std::string PersonalAssistant::getIdentity() const {
    return name;
}

OwnerChild::OwnerChild() : Suspect("Owner Child", "Child", "Unknown", false), CloseRelations("Owner Child", "Unknown", false) {
    role = "Child";
}

OwnerChild::OwnerChild(const std::string& personName, const std::string& personNationality, bool culpritStatus)
    : Character(personName, "Child", personNationality, culpritStatus), Suspect(personName, "Child", personNationality, culpritStatus), CloseRelations(personName, personNationality, culpritStatus) {
}

void OwnerChild::display() const {
    std::cout << "Owner Child: " << name << "\n";
}

std::string OwnerChild::getIdentity() const {
    return name;
}
