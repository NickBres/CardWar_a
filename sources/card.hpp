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
        int rank;    // (2 - 10, Jack, Queen, King, Ace)
        string suit; // (Hearts, Spades, Diamonds, Clubs)
    public:
        Card(int rank = 0, string suit = "")
        {
            this->rank = rank;
            this->suit = suit;
        };
        ~Card(){};
        string toString();
        int compare(Card &other);
        int getRank()
        {
            return this->rank;
        };
        string getSuit()
        {
            return this->suit;
        };
        void setRank(int rank)
        {
            this->rank = rank;
        };
        void setSuit(string suit)
        {
            this->suit = suit;
        };
    };
};
