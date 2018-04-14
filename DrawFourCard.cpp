#include "DrawFourCard.h"
#include "Player.h"

DrawFourCard::DrawFourCard() : WildCard() {
}

DrawFourCard::~DrawFourCard() {
  this->WildCard::~WildCard();
}

bool DrawFourCard::operator^(const Card& t) const {
  return true;
}

void DrawFourCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
  this->WildCard::castEffect(currentPlayer, drawPile, discardPile);
  if (currentPlayer->getNextPlayer()->appealDrawFour()) {
    // Next player chose appeal
    bool hasAlternativeCard = false;
    for (int i = 0; i < currentPlayer->getSize(); i += 1) {
      const Card* ithCard = currentPlayer->getCard(i);
      if (typeid(ithCard) != typeid(DrawFourCard) && *(discardPile.getTopCard()) ^ *(ithCard)) {
        // i-th card playable
        hasAlternativeCard = true;
        break;
      }
    }
    if (hasAlternativeCard) {
      // current player guilty
      currentPlayer->drawCard(drawPile, discardPile, 4);
    } else {
      currentPlayer->getNextPlayer()->drawCard(drawPile, discardPile, 6);
    }
  } else {
    currentPlayer->getNextPlayer()->drawCard(drawPile, discardPile, 4);
  }
}

void DrawFourCard::init() {
  this->WildCard::init();
}

void DrawFourCard::serialize(std::ostream &os) const {
  if (this->color == Color::meta) {
    os << "+4";
  } else {
    os << '4';
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
  }
}
