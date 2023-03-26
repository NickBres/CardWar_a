//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <random>

#include "card.hpp"
#include "player.hpp"

namespace ariel
{
    class Game
    {
        Card deck[52];
        Player p1,p2;
        string lastTurn;
        string mainLog;
        int winner;

    public:
        Game(Player p1, Player p2){
        lastTurn = "";
        mainLog = "";
        winner = -1;
        this->p1 = p1;
        this->p2 = p2;
        this->fillCards();
        random_shuffle(&this->deck[0], &this->deck[52]);
        this->splitCards();
    };

        void fillCards();  // fill the array of cards#include <iostream>
        void swapCards(int i, int j); // swap two cards in array
        void splitCards(); // split cards between two players
        void playTurn();   // make one turn
        void printLastTurn();  
        void printLog();  // print the log of the game
        void checkWin();  // check if there is a winner
        void printWiner();
        void printStats(); // print the stats of the players
        void playAll(); // play the game until the end
        
    };
};
