//
// Created by Nikita Breslavsky on 24/03/2023.
//
#include "doctest.h"
#include <stdexcept>

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
    CHECK(p1.name == "Capybarak");
    CHECK(p1.turnsPlayed == 0);
    CHECK(p1.turnsWon == 0);
    CHECK(p1.turnsDraw == 0);
    CHECK(p1.cardsTakenCount == 0);
    CHECK(p1.cards.size() == 0);
    CHECK(p1.cardsTakenStack.size() == 0);
    Player p2; // default constructor
    CHECK(p2.name == "");
    CHECK(p2.turnsPlayed == 0);
    CHECK(p2.turnsWon == 0);
    CHECK(p2.turnsDraw == 0);
    CHECK(p2.cardsTakenCount == 0);
    CHECK(p2.cards.size() == 0);
    CHECK(p2.cardsTakenStack.size() == 0);
};

TEST_CASE("Player main deck manipulations"){
    Player p("Capybarak");
    Card card1(2, "Hearts");
    p.addCard(card1); // add card to main deck
    CHECK(p.cards.size() == 1);  // check if card was added
    CHECK(p.cardsLeft() == 1);
    card1 = p.playCard();  // play card (get card from main deck)
    CHECK(p.cards.size() == 0); // check if card was removed
    CHECK(p.cardsLeft() == 0);
    CHECK(card1.getRank() == 2); // check if card is the same
    CHECK(card1.getSuit() == "Hearts");
}

TEST_CASE("Player cards taken manipulations"){
    Player p("Capybarak");
    Card card1(2, "Hearts");
    p.takeCard(card1); // add card to cards taken
    CHECK(p.cardsTakenStack.size() == 1);  // check if card was added
    CHECK(p.cardesTaken() == 1);
    CHECK(p.cardsLeft() == 1);
    card1 = p.playCard();  // play card (get card from cards taken because main deck is empty)
    CHECK(p.cardsTakenStack.size() == 0); // check if card was removed
    CHECK(p.cardesTaken() == 1);
    CHECK(p.cardsLeft() == 0);
    CHECK(card1.getRank() == 2); // check if card is the same
    CHECK(card1.getSuit() == "Hearts");
}

TEST_CASE("Player stats"){
    Player p("Capybarak");
    CHECK(p.getStats() == "Player Capybarak has not played any turns yet");
    p.turnsPlayed++;
    CHECK(p.getStats() == "Player Capybarak has played 1 turns.Win rate: 0%. Draw rate: 0%. Cards taken: 0. Cards left: 0.");
    p.turnsWon++;
    CHECK(p.getStats() == "Player Capybarak has played 1 turns.Win rate: 100%. Draw rate: 0%. Cards taken: 0. Cards left: 0.");
    p.turnsPlayed++;
    p.turnsDraw++;
    CHECK(p.getStats() == "Player Capybarak has played 2 turns.Win rate: 50%. Draw rate: 50%. Cards taken: 0. Cards left: 0.");
    p.cardsTakenCount++;
    CHECK(p.getStats() == "Player Capybarak has played 2 turns.Win rate: 50%. Draw rate: 50%. Cards taken: 1. Cards left: 1.");
}

TEST_CASE("Gameplay"){
    Player p1("Capy");
    Player p2("Barak");
    Game game(p1,p2);
    CHECK(p1.cards.size() == 26);
    CHECK(p2.cards.size() == 26);
    CHECK(p1.getStats() == "Player Capy has not played any turns yet");
    CHECK(p2.getStats() == "Player Barak has not played any turns yet");
    game.playTurn(); // each player plays minimum 1 card (if draw plays more)
    CHECK(p1.cards.size() < 26); // check if cards were removed from main deck
    CHECK(p2.cards.size() < 26);
    CHECK((p1.cardsTakenStack.size() > 0 || p2.cardsTakenStack.size() > 0)); // check if cards were added to cards taken
    game.playAll();
    CHECK(p1.cards.size() == 0); // check if main deck is empty
    CHECK(p2.cards.size() == 0);
    CHECK((p1.cardsTakenStack.size() == 52 || p2.cardsTakenStack.size() == 52)); // check if cards were added to cards taken
}
