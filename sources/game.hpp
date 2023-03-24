//
// Created by Nikita Breslavsky on 21/03/2023.
//

#ifndef CARDWAR_A_GAME_H
#define CARDWAR_A_GAME_H

class Game {
    Player p1;
    Player p2;
    Card []
    cards;
    String log;
public:
    Game(Player p1, Player p2);

    fillCards(); // fill the array of cards
    shuffle();  // shuffle all cards in array
    splitCards(); // split cards between two players
    playTurn(); // make one turn
    print_lastTurn();

    playAll(); // play the game until the end
    printWinner();

    printLog();

    printStats();


#endif //CARDWAR_A_GAME_H
