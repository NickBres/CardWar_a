//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;
namespace ariel
{

    class Card
    {
        unsigned int rank;    // (2 - 10, Jack, Queen, King, Ace)
        string suit; // (Hearts, Spades, Diamonds, Clubs)
    public:
        Card(unsigned int rank = 0, string&& suit = "No suit") : rank(rank), suit(move(suit)){};
        string toString();
        int compare(Card &other);
        unsigned int getRank() const
        {
            return this->rank;
        };
        string getSuit()
        {
            return this->suit;
        };
        void setRank(unsigned int rank)
        {
            this->rank = rank;
        };
        void setSuit(string&& suit)
        {
            this->suit = move(suit);
        };
    };
};
