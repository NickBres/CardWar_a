//
// Created by Nikita Breslavsky on 23/03/2023.
//
#include "player.hpp"

using namespace std;
using namespace ariel;

Card Player::playCard()
{
    Card card;
    if (!this->cards.empty())
    { // first check if player has cards in his stack
        card = this->cards.top();
        this->cards.pop();
        return card;
    }
    else if (!this->cardsTakenStack.empty())
    { // if not, check if he has cards in his taken stack
        while (!this->cardsTakenStack.empty())
        {
            this->cards.push(this->cardsTakenStack.top());
            this->cardsTakenStack.pop();
        }
        card = this->cards.top();
        this->cards.pop();
        return card;
    }
    else
    {
        cout << "Player " << this->name << " has no cards left" << endl;
        card = Card();
        return card;
    }
};

void Player::addCard(Card card)
{
    this->cards.push(card);
};

void Player::takeCard(Card card)
{
    this->cardsTakenStack.push(card);
    this->cardsTakenCount++;
};

int Player::stacksize()
{
    return this->cards.size();
};

int Player::cardesTaken()
{
    return this->cardsTakenCount;
};

string Player::getStats()
{
    if (this->turnsPlayed == 0)
    {
        return "Player " + this->name + " has not played any turns yet";
    }
    string winRate = to_string((int)(this->turnsWon / this->turnsPlayed * 100)) + "%";
    string drawRate = to_string((float)this->turnsDraw / (float)this->turnsPlayed * 100) + "%";
    return "Player " + this->name + " has played " + to_string(this->turnsPlayed) + " turns. Win rate: " + winRate + ". Draw rate: " + drawRate + ". Cards taken: " + to_string(this->cardsTakenCount) + ". Cards left: " + to_string(this->cardsLeft()) + ".";
};

int Player::cardsLeft()
{
    return this->cards.size() + this->cardsTakenStack.size();
};
