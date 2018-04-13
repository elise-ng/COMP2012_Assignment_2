/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"

NumberCard::NumberCard(int number, Color color) : Card(color, number), number(number) {
}

NumberCard::~NumberCard() {
  this->Card::~Card();
};

bool NumberCard::operator^(const Card& t) const {
  if (typeid(t) == typeid(NumberCard)) {
    const NumberCard& numT = dynamic_cast<const NumberCard&>(t);
    return numT.number == this->number || this->Card::operator^(t);
  } else {
    return this->Card::operator^(t);
  }
}

void NumberCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
  // no action for number card
}

void NumberCard::serialize(std::ostream& os) const {
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
  os << this->number;
}
