//
// Created by Nikita Breslavsky on 24/03/2023.
//
#include "doctest.h"
#include <stdexcept>

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

TEST_CASE("Card init") {
    Card card(2, "Hearts");
    CHECK(card.getRank() == 2);
    CHECK(card.getSuit() == "Hearts");
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