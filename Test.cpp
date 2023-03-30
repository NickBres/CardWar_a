//
// Created by Nikita Breslavsky on 24/03/2023.
//
#include "doctest.h"
#include <unistd.h>


#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;

TEST_CASE("Card init") {
    Card card(2, "Hearts");
    CHECK(card.getRank() == 2);
    CHECK(card.getSuit() == "Hearts");
    Card def; // default constructor
    CHECK(def.getRank() == 0);
    CHECK(def.getSuit() == "");
};

TEST_CASE("Card compare") {
    Card card1(2, "Hearts");
    Card card2(3, "Hearts");
    CHECK(card1.compare(card2) < 0);
    CHECK(card2.compare(card1) > 0);

    Card card3(2, "Diamonds");
    Card card4(14, "Diamonds");
    CHECK(card3.compare(card4) > 0);
    CHECK(card4.compare(card3) < 0);

    CHECK(card1.compare(card3) == 0);
};

TEST_CASE("Player init") {
    Player p1("Capybarak");
    CHECK(p1.getName() == "Capybarak");
    CHECK(p1.cardsLeft() == 0);
    Player p2; // default constructor
    CHECK(p2.getName() == "");
    CHECK(p2.cardsLeft() == 0);
};

TEST_CASE("Player main deck manipulations"){
    Player p("Capybarak");
    p.addCard(1); // add card to main deck=
    CHECK(p.cardsLeft() == 1);
    p.playCard();  // play card (get card from main deck)=
    CHECK(p.cardsLeft() == 0);
}

TEST_CASE("Player cards taken manipulations"){
    Player p("Capybarak");
    p.takeCard(1); // add card to cards taken
    CHECK(p.cardesTaken() == 1); 
    CHECK(p.cardsLeft() == 0); // cards taken are not in main deck
    p.playCard(); // nothing happens because there are no cards in main deck
    CHECK(p.cardesTaken() == 1); 
    CHECK(p.cardsLeft() == 0);
}

TEST_CASE("Player stats"){
    Player p("Capybarak");
    CHECK(p.getStats() == "Player Capybarak has not played any turns yet");
    p.addCard(1);
    p.playCard();
    CHECK(p.getStats() == "Player Capybarak has played 1 turns. Win rate: 0%. Draw rate: 0%. Draw count: 0. Cards won: 0. Cards left: 0.");
    p.win();
    CHECK(p.getStats() == "Player Capybarak has played 1 turns. Win rate: 100%. Draw rate: 0%. Draw count: 0. Cards won: 0. Cards left: 0.");
    p.addCard(1);
    p.playCard();
    p.draw();
    CHECK(p.getStats() == "Player Capybarak has played 2 turns. Win rate: 50%. Draw rate: 50%. Draw count: 1. Cards won: 0. Cards left: 0.");
    p.takeCard(1);
    CHECK(p.getStats() == "Player Capybarak has played 2 turns. Win rate: 50%. Draw rate: 50%. Draw count: 1. Cards won: 1. Cards left: 0.");
}

TEST_CASE("Gameplay"){
    Player p1("Capy");
    Player p2("Barak");
    Game game(p1,p2);
    CHECK(p1.cardsLeft() == 26);
    CHECK(p2.cardsLeft() == 26);
    CHECK(p1.getStats() == "Player Capy has not played any turns yet");
    CHECK(p2.getStats() == "Player Barak has not played any turns yet");
    game.playTurn(); // each player plays minimum 1 card (if draw plays more)
    CHECK((p1.cardsLeft() < 26 || p2.cardsLeft() < 26));
    game.playAll();
    CHECK((p1.cardsLeft() == 0 || p2.cardsLeft() == 0)); // check if all cards were played
}
