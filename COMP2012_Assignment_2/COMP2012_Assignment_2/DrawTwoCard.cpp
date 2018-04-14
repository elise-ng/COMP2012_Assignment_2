/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#include "DrawTwoCard.h"
#include "Player.h"

DrawTwoCard::DrawTwoCard(Color color) : SkipCard(color) {
}

bool DrawTwoCard::operator^(const Card &t) const {
  if (typeid(t) == typeid(DrawTwoCard)) {
    return true;
  } else {
    return this->Card::operator^(t);
  }
}

void DrawTwoCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
  currentPlayer->getNextPlayer()->drawCard(drawPile, discardPile, 2);
  this->SkipCard::castEffect(currentPlayer, drawPile, discardPile);
}

void DrawTwoCard::serialize(std::ostream &os) const {
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
  os << '+';
}
