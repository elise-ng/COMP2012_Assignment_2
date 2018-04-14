/*
 * DrawFourCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef DRAWFOURCARD_H_
#define DRAWFOURCARD_H_

#include "WildCard.h"

class DrawFourCard : public WildCard {
public:
  DrawFourCard();
  virtual bool operator^(const Card& t) const override;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;
  virtual void init() override;
protected:
  virtual void serialize(ostream& os) const override;
private:
};

#endif /* DRAWFOURCARD_H_ */
