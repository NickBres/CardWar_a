/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main() {
  // Create two players with their names 
   Player p1("Capy");
   Player p2("Barak");

   Game game(p1,p2); 

   while (true){
        int i = 0;
        cout << "Enter command (1 - turn, 2 - print last turn, 3 - print log, 4 - print stats, 5 - print winner, 6 - finish the game) : " << endl;
        cin >> i;
        cout << "----------------------------------------------------------------------------------------" << endl;
        switch (i)
        {
        case 1:
            game.playTurn();
            game.printLastTurn();
            break;
        case 2:
            game.printLastTurn();
            break;
        case 3:
            game.printLog();
            break;
        case 4:
            game.printStats();
            break;
        case 5:
            game.printWiner();
            break;
        case 6:
            game.playAll();
            break;
        default:
            game.~Game();
            p1.~Player();
            p2.~Player();
            return 0;
        }
        cout << "----------------------------------------------------------------------------------------" << endl;
   }
   return 0;
};
   
