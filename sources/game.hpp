//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <iostream>

#include "card.hpp"
#include "player.hpp"

namespace ariel
{
    class Game
    {
        Card *deck;
        Player *players;
        string lastTurn;
        string mainLog;
        int winner;

    public:
        Game(Player p1, Player p2) {
        deck = new Card[52];
        players = new Player[2];
        lastTurn = "";
        mainLog = "";
        winner = -1;
        players[0] = p1;
        players[1] = p2;
        this->fillCards();
        this->shuffle();
        this->splitCards();
    };

        void fillCards();  // fill the array of cards
        void shuffle();    // shuffle all cards in array
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
