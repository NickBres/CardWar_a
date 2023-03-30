//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

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
        Game(Player &p1, Player &p2): p1(p1), p2(p2){
        lastTurn = "";
        mainLog = "";
        winner = -1;
        this->p1 = p1;
        this->p2 = p2;
        this->fillCards();
        this->shuffleCards();
        this->splitCards();
    };
        ~Game(){};

        void fillCards();  // fill the array of cards#include <iostream>
        void shuffleCards(); // shuffle the array of cards
        void splitCards(); // split cards between two players
        void playTurn();   // make one turn
        void printLastTurn();  
        void printLog();  // print the log of the game
        int checkWin();  // check if there is a winner
        void printWiner();
        void printStats(); // print the stats of the players
        void playAll(); // play the game until the end
        
    };
};
