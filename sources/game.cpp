//
// Created by Nikita Breslavsky on 23/03/2023.
//

#include "game.hpp"

using namespace std;
using namespace ariel;

void Game::fillCards()
{
    string name = "Hearts";
    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 2; j < 15; j++)
        {
            this->deck[i * 13 + j - 2].setRank(j);
            this->deck[i * 13 + j - 2].setSuit(move(name));
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

void Game::shuffleCards()
{
    random_device rd;
    mt19937 g(rd());
    shuffle(this->deck.begin(), this->deck.end(), g);
};

void Game::splitCards()
{
    for (unsigned int i = 0; i < 52; i++)
    {
        if (i % 2 == 0)
        {
            this->p1.addCard(i);
        }
        else
        {
            this->p2.addCard(i);
        }
    }
};

void Game::playTurn()
{
    if (&this->p1 == &this->p2){
        throw runtime_error("Cannot play with the same player!");
        return;
    }
    if (this->winner != -1) // do not play if something wrong
    {
        throw runtime_error("Game is over!");
        return;
    }
    string log = "";                                     // log of the turn
    vector<unsigned int> cards = vector<unsigned int>(); // to store the cards that were drawn

    unsigned int p1Card = this->p1.playCard();
    unsigned int p2Card = this->p2.playCard();
    cards.push_back(p1Card);
    cards.push_back(p2Card);
    log += this->p1.getName() + " plays " + this->deck[p1Card].toString() + " | " + this->p2.getName() + " plays " + this->deck[p2Card].toString();
    if (this->checkWin()) // chech if cards left 
        { 
            if (this->winner == 1)
            {
                log += this->p1.getName() + " wins the game! \n";
                p1.win();
                this->takeCards(this->p1, cards);
            }
            else
            {
                log += this->p2.getName() + " wins the game! \n";
                p2.win();
                this->takeCards(this->p2, cards);
            }
            cards.clear();
            this->lastTurn = log;
            this->mainLog += log + '\n';
            return;
        }
    int compare = this->deck[p1Card].compare(this->deck[p2Card]);
    while (!compare)
    {
        p1.draw();
        p2.draw();
        log += " > Draw > ";

        p1Card = this->p1.playCard();
        p2Card = this->p2.playCard();
        cards.push_back(p1Card);
        cards.push_back(p2Card);
        if (this->checkWin()) // chech if cards left 
        { 
            if (this->winner == 1)
            {
                log += this->p1.getName() + " wins the game! \n";
                p1.win();
                this->takeCards(this->p1, cards);
            }
            else
            {
                log += this->p2.getName() + " wins the game! \n";
                p2.win();
                this->takeCards(this->p2, cards);
            }
            cards.clear();
            this->lastTurn = log;
            this->mainLog += log + '\n';
            return;
        }

        p1Card = this->p1.playCard();
        p2Card = this->p2.playCard();

        log += this->p1.getName() + " plays " + this->deck[p1Card].toString() + " | " + this->p2.getName() + " plays " + this->deck[p2Card].toString();
        cards.push_back(p1Card);
        cards.push_back(p2Card);
        compare = this->deck[p1Card].compare(this->deck[p2Card]);
    }
    if (compare > 0)
    {
        log += " >>> " + this->p1.getName() + " wins the round! \n";
        p1.win();
        this->takeCards(this->p1, cards);
    }
    else if (compare < 0)
    {
        log += " >>> " + this->p2.getName() + " wins the round! \n";
        p2.win();
        this->takeCards(this->p2, cards);
    }
    cards.clear();
    this->lastTurn = log;
    this->mainLog += log;
    this->checkWin();
};

void Game::takeCards(Player &p, vector<unsigned int> cards)
{
    while (cards.empty() == false)
    {
        p.takeCard(cards.back());
        cards.pop_back();
    }
};

void Game::printLastTurn()
{
    cout << this->lastTurn << endl;
};

void Game::printLog()
{
    cout << "_________________________________________________________________________" << endl;
    cout << "                               GAME LOG" << endl;
    cout << "_________________________________________________________________________\n"
         << endl;
    cout << this->mainLog;
    cout << "_________________________________________________________________________" << endl;
};

int Game::checkWin()
{
    if (this->p1.cardsLeft() == 0 and this->p2.cardsLeft() == 0)
    {
        if (this->p1.cardesTaken() > this->p2.cardesTaken())
        {
            this->winner = 1;
            this->mainLog += "\n" + this->p1.getName() + " wins the game! \n";
        }
        else if (this->p1.cardesTaken() < this->p2.cardesTaken())
        {
            this->winner = 2;
            this->mainLog += "\n" + this->p2.getName() + " wins the game! \n";
        }
        else
        {
            //    this->p1.getCardsFromTaken();
            //    this->p2.getCardsFromTaken();
            this->winner = 3;
            this->mainLog += "Draw! \n";
        }
        return 1;
    }
    return 0;
};

void Game::printWiner()
{

    if (this->checkWin())
    {
        if (this->winner == 1)
        {
            cout << this->p1.getName() << " wins the game!" << endl;
        }
        else if (this->winner == 2)
        {
            cout << this->p2.getName() << " wins the game!" << endl;
        }else
        {
            throw runtime_error("Draw!");
        }
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
