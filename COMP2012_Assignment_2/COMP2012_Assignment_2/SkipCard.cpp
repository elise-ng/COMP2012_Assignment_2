/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "SkipCard.h"
#include "Player.h"

SkipCard::SkipCard(Color color) : Card(color, POINT_SKIPCARD) {
}

bool SkipCard::operator^(const Card &t) const {
  if (typeid(t) == typeid(SkipCard)) {
    return true;
  } else {
    return this->Card::operator^(t);
  }
}

void SkipCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
  currentPlayer = currentPlayer->getNextPlayer();
}

void SkipCard::serialize(std::ostream &os) const {
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
  os << 's';
}
