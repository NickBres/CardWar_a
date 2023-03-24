//
// Created by Nikita Breslavsky on 21/03/2023.
//

#ifndef CARDWAR_A_CARD_H
#define CARDWAR_A_CARD_H

#include <string>

using namespace std;

class Card {
    int rank; // (2 - 10, Jack, Queen, King, Ace)
    string suit; // (Hearts, Spades, Diamonds, Clubs)
public:
    Card() {
        this->rank = 0;
        this->suit = "";
    };

    Card(int rank, string suit) {
        this->rank = rank;
        this->suit = suit;
    };
    string toString();
    int compare(Card other);
    int getRank() {
        return this->rank;
    };
    string getSuit() {
        return this->suit;
    };
    ~Card();
};

#endif //CARDWAR_A_CARD_H
