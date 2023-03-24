//
// Created by Nikita Breslavsky on 21/03/2023.
//

#ifndef CARDWAR_A_PLAYER_H
#define CARDWAR_A_PLAYER_H
#include <string>
#include <iostream>
#include <stack>
#include "card.hpp"

using namespace std;

class Player {
public:
    string name;
    stack <Card> cards;
    stack <Card> cardsTakenStack;
    int turnsPlayed;
    int turnsWon;
    int turnsDraw;
    int cardsTakenCount;

    Player();
    Player(string name);

    Card playCard();

    void addCard(Card card);

    void takeCard(Card card);

    int stackSize();

    int cardsTaken();

    string getStats();

    int cardsLeft();

};

#endif //CARDWAR_A_PLAYER_H
