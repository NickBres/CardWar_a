//
// Created by Nikita Breslavsky on 23/03/2023.
//
#import <iostream>
#include "card.hpp"
#include "player.hpp"

class Game {
    Card deck[];
    Player players[];
    String lastTurn;
    String mainLog;
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
        fillCards();
        shuffle();
        splitCards();
    };

    void fillCards() {
        String name = "Hearts";
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j < 15; j++) {
                deck[i * 13 + j - 2] = Card(j, name);
            }
            if (i == 0) {
                name = "Spades";
            } else if (i == 1) {
                name = "Diamonds";
            } else {
                name = "Clubs";
            }
        }
    };

    void shuffle() {
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            Card temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
            temp = NULL;
        }
    };

    void splitCards() {
        for (int i = 0; i < 52; i++) {
            players[i % 2].addCards(deck[i]);
            deck[i] = NULL;
        }
    };

    void playTurn() {
        int i = 0;
        String log = "";
        players[0].turnsPlayed++;
        cards[i++] = players[0].playCard();
        log += players[0].name + " plays " + cards[i - 1].toString() + " | ";
        players[1].turnsPlayed++;
        cards[i++] = players[1].playCard();
        log += players[1].name + " plays " + cards[i - 1].toString() + " > ";
        int result = cards[i - 2].compare(cards[i - 1]);
        while (!result and i < 52) {
            log += "Draw! \n";
            players[0].turnsDraw++;
            players[1].turnsDraw++;
            players[0].turnsPlayed++;
            cards[i++] = players[0].playCard();
            cards[i++] = players[1].playCard();
            players[1].turnsPlayed++;
            cards[i++] = players[0].playCard();
            cards[i++] = players[1].playCard();
            result = cards[i - 2].compare(cards[i - 1]);
        }
        if (result > 0) { // player 1 wins
            log += players[0].name + " wins the turn! \n";
            players[0].turnsWon++;
            players[1].turnsLost++;
            for (int j = 0; j < i; j++) { // take all cards
                players[0].takeCard(cards[j]);
                cards[j] = NULL;
            }
        } else if (result < 0) { // player 2 wins
            log += players[1].name + " wins the turn! \n";
            players[1].turnsWon++;
            players[0].turnsLost++;
            for (int j = 0; j < i; j++) { // take all cards
                players[1].takeCard(cards[j]);
                cards[j] = NULL;
            }
        } else { // draw
            cout << "Draw" << endl;
            winner = 3;
        }
        lastTurn = log;
        mainLog += log;
        checkWin();
    }

    void printLastTurn() {
        cout << lastTurn << endl;
    }

    void printLog() {
        cout << mainLog << endl;
    }

    void checkWin() {
        if (winner == 3) {
            log += "Draw! \n";
        } else if (players[0].cardsLeft() == 0) {
            winner = 1;
            log += players[1].name + " wins the game! \n";
        } else if (players[1].cardsLeft() == 0) {
            winner = 0;
            log += players[0].name + " wins the game! \n";
        }
    }

    void printWiner() {
        if (winner > 0 and winner < 3) {
            cout << players[winner].name << " wins the game!" << endl;
        } else if (winner == 3) {
            cout << "Draw!" << endl;
        } else {
            cout << "No winner yet" << endl;
        }
    }

    void printStats() {
        cout << players[0].getStats() << endl;
        cout << players[1].getStats() << endl;
    }

    void playAll() {
        while (winner == -1) {
            playTurn();
        }
    }

};
