//
// Created by Nikita Breslavsky on 23/03/2023.
//

#include "card.hpp"

using namespace std;
using namespace ariel;

string Card::toString() {
    if (this->rank == 11) {
        return "Jack of " + this->suit;
    } else if (this->rank == 12) {
        return "Queen of " + this->suit;
    } else if (this->rank == 13) {
        return "King of " + this->suit;
    } else if (this->rank == 14) {
        return "Ace of " + this->suit;
    }
    return to_string(this->rank) + " of " + this->suit;
};

int Card::compare(Card& other) { // returns positive if this card is bigger, negative if other is bigger, 0 if equal
    if (this->rank == 14 and other.rank == 2) {
        return -1;
    } else if (this->rank == 2 and other.rank == 14) {
        return 1;
    }
    return this->rank - other.rank;
};

