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
        string name;
        vector<unsigned int> cards;        // cards in hand by index
        vector<unsigned int> cardsTakenStack;  // cards taken by index
        int turnsPlayed; // count of turns played
        int turnsWon;   // count of turns won
        int turnsDraw; // count of turns draw

    public:
        Player(string name = ""): name(name), turnsPlayed(0), turnsWon(0), turnsDraw(0), cards(vector<unsigned int>()), cardsTakenStack(vector<unsigned int>())
        {};
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

        string getName();

        int cardsLeft();

        void win();

        void draw();

        void getCardsFromTaken();
    };
};
