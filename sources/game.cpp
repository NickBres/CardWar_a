//
// Created by Nikita Breslavsky on 23/03/2023.
//

#include "game.hpp"

using namespace std;
using namespace ariel;

void Game::fillCards()
{
    string name = "Hearts";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j < 15; j++)
        {
            this->deck[i * 13 + j - 2].setRank(j);
            this->deck[i * 13 + j - 2].setSuit(name);
        }
        if (i == 0)
        {
            name = "Spades";
        }
        else if (i == 1)
        {
            name = "Diamonds";
        }
        else
        {
            name = "Clubs";
        }
    }
};

void Game::shuffle()
{
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        Card temp = this->deck[i];
        this->deck[i] = this->deck[j];
        this->deck[j] = temp;
    }
};

void Game::splitCards()
{
    for (int i = 0; i < 52; i++)
    {
        this->players[i % 2].addCard(this->deck[i]);
    }
};

void Game::playTurn()
{
    int i = 0;
    string log = "";
    this->players[0].turnsPlayed++;
    this->deck[i++] = this->players[0].playCard();
    log += this->players[0].name + " plays " + this->deck[i - 1].toString() + " | ";
    this->players[1].turnsPlayed++;
    this->deck[i++] = this->players[1].playCard();
    log += this->players[1].name + " plays " + this->deck[i - 1].toString() + " > ";
    int result = this->deck[i - 2].compare(this->deck[i - 1]);
    while (!result and i < 52)
    {
        log += "Draw! \n";
        this->players[0].turnsDraw++;
        this->players[1].turnsDraw++;
        this->players[0].turnsPlayed++;
        this->deck[i++] = this->players[0].playCard();
        this->deck[i++] = this->players[1].playCard();
        this->players[1].turnsPlayed++;
        this->deck[i++] = this->players[0].playCard();
        this->deck[i++] = this->players[1].playCard();
        result = this->deck[i - 2].compare(this->deck[i - 1]);
    }
    if (result > 0)
    { // player 1 wins
        log += this->players[0].name + " wins the turn! \n";
        this->players[0].turnsWon++;
        for (int j = 0; j < i; j++)
        { // take all cards
            this->players[0].takeCard(this->deck[j]);
        }
    }
    else if (result < 0)
    { // player 2 wins
        log += this->players[1].name + " wins the turn! \n";
        this->players[1].turnsWon++;
        for (int j = 0; j < i; j++)
        { // take all cards
            this->players[1].takeCard(this->deck[j]);
        }
    }
    else
    { // draw
        cout << "Draw" << endl;
        winner = 3;
    }
    this->lastTurn = log;
    this->mainLog += log;
    this->checkWin();
};

void Game::printLastTurn()
{
    cout << this->lastTurn << endl;
};

void Game::printLog()
{
    cout << this->mainLog << endl;
};

void Game::checkWin()
{
    if (winner == 3)
    {
        this->mainLog += "Draw! \n";
    }
    else if (this->players[0].cardsLeft() == 0)
    {
        winner = 1;
        this->mainLog += this->players[1].name + " wins the game! \n";
    }
    else if (players[1].cardsLeft() == 0)
    {
        winner = 0;
        this->mainLog += this->players[0].name + " wins the game! \n";
    }
};

void Game::printWiner()
{
    if (this->winner > 0 and this->winner < 3)
    {
        cout << this->players[winner].name << " wins the game!" << endl;
    }
    else if (this->winner == 3)
    {
        cout << "Draw!" << endl;
    }
    else
    {
        cout << "No winner yet" << endl;
    }
};

void Game::printStats()
{
    cout << this->players[0].getStats() << endl;
    cout << this->players[1].getStats() << endl;
};

void Game::playAll()
{
    while (this->winner == -1)
    {
        this->playTurn();
    }
};
