/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"

NumberCard::NumberCard(int number, Color color) : Card(color, number), number(number) {
}

NumberCard::~NumberCard() : ~Card() {
};

bool NumberCard::operator^(const Card& t) const {
  if (NumberCard & numT = dynamic_cast<NumberCard>(t) && numT->number == this->number) {
    return true;
  } else {
    return this->Card::operator^(t)
  }
}

void NumberCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
  // no action for number card
}

void NumberCard::serialize(std::ostream& os) {
  switch (this->color) {
    case Color::red:
      os << "B";
      break;
    case Color::blue:
      os << "B";
      break;
    case Color::green:
      os << "B";
      break;
    case Color::yellow:
      os << "B";
      break;
    default:
      break;
  }
  os << this->number;
}
