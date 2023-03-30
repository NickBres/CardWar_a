//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
    public:
        string name;
        vector<unsigned int> cards;        // cards in hand by index
        vector<unsigned int> cardsTakenStack;  // cards taken by index
        int turnsPlayed;
        int turnsWon;
        int turnsDraw;

        Player(string name = "")
        {
            this->name = name;
            this->turnsPlayed = 0;
            this->turnsWon = 0;
            this->turnsDraw = 0;
            this->cards = vector<unsigned int>();
            this->cardsTakenStack = vector<unsigned int>();
        };
        ~Player(){
            this->cards.clear();
            this->cardsTakenStack.clear();
        };

        unsigned int playCard(); // returns the index of the card played

        void addCard(unsigned int  cardIndex); 

        void takeCard(unsigned int cardIndex);

        int stacksize();

        int cardesTaken();

        string getStats();

        int cardsLeft();
    };
};
