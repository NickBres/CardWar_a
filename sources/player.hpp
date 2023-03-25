//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <string>
#include <iostream>
#include <stack>
#include "card.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
    public:
        string name;
        stack<Card> cards;
        stack<Card> cardsTakenStack;
        int turnsPlayed;
        int turnsWon;
        int turnsDraw;
        int cardsTakenCount;

        Player(){
            this->setDefault();
        };

        Player(string name)
        {
            this->name = name;
            this->turnsPlayed = 0;
            this->turnsWon = 0;
            this->turnsDraw = 0;
            this->cardsTakenCount = 0;
            this->cards = stack<Card>();
            this->cardsTakenStack = stack<Card>();
        };

        void setDefault()
        {
            this->name = "";
            this->turnsPlayed = 0;
            this->turnsWon = 0;
            this->turnsDraw = 0;
            this->cardsTakenCount = 0;
            this->cards = stack<Card>();
            this->cardsTakenStack = stack<Card>();
        };

        Card playCard();

        void addCard(Card card);

        void takeCard(Card card);

        int stacksize();

        int cardesTaken();

        string getStats();

        int cardsLeft();
    };
};
