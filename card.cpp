// card.cpp
// Author: Zhiyicheng
// Implementation of the classes defined in card.h

#include "card.h"

Card::Card() {
    suit = 'c';
    val = 0;
}

Card::Card(char s, string v) {
    suit = s;
    
    if (v == "a") {
        val = 1;
    }
    else if (v == "j") {
        val = 11;
    }
    else if (v == "q") {
        val = 12;
    }
    else if (v == "k") {
        val = 13;
    }
    else {
        val = stoi(v);
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getVal() const {
    return val;
}


int Card::getSuitRank() const {
    if (suit == 'c') return 1;
    if (suit == 'd') return 2;
    if (suit == 's') return 3;
    if (suit == 'h') return 4;
    return 0;
}
bool Card::operator<(const Card& other) const {

    if (getSuitRank() != other.getSuitRank()) {
    return getSuitRank() < other.getSuitRank();
    }
    return val < other.val;
}

bool Card::operator>(const Card& other) const {
    return other < *this; 
}

bool Card::operator==(const Card& other) const {
    return (suit == other.suit) && (val == other.val);
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& a, const Card& c) {
    a << c.suit << " "; if (c.val == 1) a << "a";
    else if (c.val == 11) a << "j";
    else if (c.val == 12) a << "q";
    else if (c.val == 13) a << "k";
    else a << c.val;
    return a;
}
