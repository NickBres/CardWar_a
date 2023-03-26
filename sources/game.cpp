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

void Game::swapCards(int i, int j)
{
    Card temp = this->deck[i];
    this->deck[i] = this->deck[j];
    this->deck[j] = temp;
};

void Game::splitCards()
{
    for (int i = 0; i < 52; i++)
    {
        if (i % 2 == 0)
        {
            this->p1.addCard(this->deck[i]);
        }
        else
        {
            this->p2.addCard(this->deck[i]);
        }
    }
};

void Game::playTurn()
{
    int i = 0;
    string log = "";
    this->p1.turnsPlayed++;
    this->deck[i++] = this->p1.playCard();
    log += this->p1.name + " plays " + this->deck[i - 1].toString() + " | ";
    this->p2.turnsPlayed++;
    this->deck[i++] = this->p2.playCard();
    log += this->p2.name + " plays " + this->deck[i - 1].toString() + " > ";
    int result = this->deck[i - 2].compare(this->deck[i - 1]);
    while (!result and i < 52)
    {
        log += "Draw! \n";
        this->p1.turnsDraw++;
        this->p2.turnsDraw++;
        this->p1.turnsPlayed++;
        this->deck[i++] = this->p1.playCard();
        this->deck[i++] = this->p2.playCard();
        log += this->p1.name + " plays " + this->deck[i - 2].toString() + " | ";
        log += this->p2.name + " plays " + this->deck[i - 1].toString() + " | ";
        this->p2.turnsPlayed++;
        this->deck[i++] = this->p1.playCard();
        this->deck[i++] = this->p2.playCard();
        log += this->p1.name + " plays " + this->deck[i - 2].toString() + " | ";
        log += this->p2.name + " plays " + this->deck[i - 1].toString() + " > ";
        result = this->deck[i - 2].compare(this->deck[i - 1]);
    }
    if (result > 0)
    { // player 1 wins
        log += this->p1.name + " wins the turn! \n";
        this->p1.turnsWon++;
        for (int j = 0; j < i; j++)
        { // take all cards
            this->p1.takeCard(this->deck[j]);
        }
    }
    else if (result < 0)
    { // player 2 wins
        log += this->p2.name + " wins the turn! \n";
        this->p2.turnsWon++;
        for (int j = 0; j < i; j++)
        { // take all cards
            this->p2.takeCard(this->deck[j]);
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
    else if (this->p1.cardsLeft() == 0)
    {
        winner = 2;
        this->mainLog += this->p2.name + " wins the game! \n";
    }
    else if (p2.cardsLeft() == 0)
    {
        winner = 1;
        this->mainLog += this->p1.name + " wins the game! \n";
    }
};

void Game::printWiner()
{
    if (this->winner > 0 and this->winner < 3)
    {
        if (this->winner == 1)
        {
            cout << this->p1.name << " wins the game!" << endl;
        }
        else if (this->winner == 2)
        {
            cout << this->p2.name << " wins the game!" << endl;
        }
        
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
    cout << this->p1.getStats() << endl;
    cout << this->p2.getStats() << endl;
};

void Game::playAll()
{
    while (this->winner == -1)
    {
        this->playTurn();
    }
};
