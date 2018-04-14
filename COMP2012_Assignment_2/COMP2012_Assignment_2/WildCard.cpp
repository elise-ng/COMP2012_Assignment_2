/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#include "WildCard.h"
#include "Player.h"

WildCard::WildCard() : Card(Color::meta, POINT_WILDCARD) {
}

bool WildCard::operator^(const Card& t) const {
  return true;
}

void WildCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
  this->color = currentPlayer->chooseColor();
}

void WildCard::init() {
  this->color = Color::meta;
}

void WildCard::serialize(std::ostream &os) const {
  if (this->color == Color::meta) {
    os << "WC";
  } else {
    switch (this->color) {
      case Color::red:
        os << 'R';
        break;
      case Color::blue:
        os << 'B';
        break;
      case Color::green:
        os << 'G';
        break;
      case Color::yellow:
        os << 'Y';
        break;
      default:
        break;
    }
    os << 'w';
  }
}
