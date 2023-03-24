//
// Created by Nikita Breslavsky on 23/03/2023.
//
#include <string>
#include <iostream>
#include <stack>
#include "card.hpp"

using namespace std;

class Player {
public:
    string name;
    stack<Card> cards;
    stack<Card> cardsTakenStack;
    int turnsPlayed;
    int turnsWon;
    int turnsDraw;
    int cardsTakenCount;

    Player() {};

    Player(string name) {
        this->name = name;
        this->turnsPlayed = 0;
        this->turnsWon = 0;
        this->turnsDraw = 0;
        this->cardsTakenCount = 0;
        this->cards = stack<Card>();
        this->cardsTakenStack = stack<Card>();
    };

    Card playCard() {
        if (!this->cards.empty()) { // first check if player has cards in his stack
            return this->cards.pop();
        } else if (!this->cardsTakenStack.empty()) { // if not, check if he has cards in his taken stack
            while (!this->cardsTakenStack.empty()) {
                this->cards.push(this->cardsTakenStack.pop());
            }
            return this->cards.pop();
        } else {
            cout << "Player " << this->name << " has no cards left" << endl;
            return NULL;
        }
    };

    void addCard(Card card) {
        this->cards.push(card);
    };

    void takeCard(Card card) {
        this->cardsTakenStack.push(card);
        this->cardsTakenCount++;
    };

    int stackSize() {
        return this->cards.size();
    };

    int cardsTaken() {
        return this->cardsTakenCount;
    };

    string getStats() {
        return "Player " + this->name + "win rate: " + to_string(this->turnsWon / this->turnsPlayed) + "draw rate: " +
               to_string(this->turnsDraw / this->turnsPlayed) + "cards taken: " + to_string(this->cardsTakenCount) +
               "cards left: " +
               to_string(this->cards.size()) + "";
    };

    int cardsLeft() {
        return this->cards.size() + this->cardsTakenStack.size();
    };

};
