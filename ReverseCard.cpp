/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "ReverseCard.h"
#include "Player.h"

ReverseCard::ReverseCard(Color color) : Card(color, POINT_REVERSECARD) {
}

ReverseCard::~ReverseCard() {
  this->Card::~Card();
}

bool ReverseCard::operator^(const Card &t) const {
  if (typeid(t) == typeid(ReverseCard)) {
    return true;
  } else {
    return this->Card::operator^(t);
  }
}

void ReverseCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
  Player* playerPtrArray[4] = { currentPlayer };
  int playerCount = 1;
  Player* playerPtr = currentPlayer->getNextPlayer();
  while (playerPtr != currentPlayer) {
    playerPtrArray[playerCount] = playerPtr;
    playerCount += 1;
    playerPtr = playerPtr->getNextPlayer();
  }
  for (int i = 0; i < playerCount; i += 1) {
    playerPtrArray[i]->nextPlayer = playerPtrArray[(i - 1) % playerCount];
  }
}

void ReverseCard::serialize(std::ostream &os) const {
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
  os << 'r';
}
