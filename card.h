// card.h
// Author: Zhiyicheng
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
    Card(); 
    Card(char s, string v); 
    char getSuit() const;
    int getVal() const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    friend ostream& operator<<(ostream& a, const Card& c);
private:
    char suit;
    int val;
    int getSuitRank() const;
};
#endif
