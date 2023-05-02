//
// Created by Nikita Breslavsky on 21/03/2023.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <array>


#include "card.hpp"
#include "player.hpp"



namespace ariel
{
    const int NUM_CARDS = 52;

    class Game
    {
        array<Card, NUM_CARDS> deck;   
        Player &p1,&p2;
        string lastTurn;
        string mainLog;
        int winner;

    public:
        Game(Player &player1, Player &player2); // constructor
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
        void takeCards(Player &player,vector<unsigned int> cards); // take the cards that were played in turn
        
    };
};
