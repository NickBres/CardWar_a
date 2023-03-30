//
// Created by Nikita Breslavsky on 23/03/2023.
//
#include "player.hpp"

using namespace std;
using namespace ariel;

unsigned int Player::playCard()
{
    unsigned int cardIndex;
    if (!this->cards.empty())
    { // first check if player has cards in his stack
        cardIndex = this->cards.back();
        this->cards.pop_back();
        this->turnsPlayed++;
        return cardIndex;
    }
    else if (!this->cardsTakenStack.empty()) // take cards from taken stack if player has no cards in his stack
    {
        while (!this->cardsTakenStack.empty())
        {
            this->cards.push_back(this->cardsTakenStack.back());
            this->cardsTakenStack.pop_back();
        }
        return this->playCard();
    }
    cout << "Player " << this->name << " has no cards left" << endl;
    return 53; // return 53 if player has no cards left. 53 is an invalid index for the deck
};

void Player::addCard(unsigned int cardIndex)
{
    this->cards.push_back(cardIndex);
};

void Player::takeCard(unsigned int cardIndex)
{
    this->cardsTakenStack.push_back(cardIndex);
};

int Player::stacksize()
{
    return this->cards.size();
};

int Player::cardesTaken()
{
    return this->cardsTakenStack.size();
};

string Player::getStats()
{
    if (this->turnsPlayed == 0)
    {
        return "Player " + this->name + " has not played any turns yet";
    }
    string winRate = to_string(int((float)this->turnsWon / (float)this->turnsPlayed * 100)) + "%";
    string drawRate = to_string(int((float)this->turnsDraw / (float)this->turnsPlayed * 100)) + "%";
    return "Player " + this->name + " has played " + to_string(this->turnsPlayed) + " turns. Win rate: " 
    + winRate + ". Draw rate: " + drawRate + ". Draw count: " + to_string(this->turnsDraw) +
    ". Cards won: " + to_string(this->cardsTakenStack.size()) + ". Cards left: " + to_string(this->cardsLeft()) + ".";
};

int Player::cardsLeft()
{
    return this->cards.size() + this->cardsTakenStack.size();
};

string Player::getName()
{
    return this->name;
};

void Player::win()
{
    this->turnsWon++;
};

void Player::draw()
{
    this->turnsDraw++;
};
