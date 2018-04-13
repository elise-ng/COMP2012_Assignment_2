/*
 * DrawTwoCard.h
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#ifndef DRAWTWOCARD_H_
#define DRAWTWOCARD_H_

#include "SkipCard.h"

class DrawTwoCard : public SkipCard {
public:
  DrawTwoCard(Color);
  virtual ~DrawTwoCard() override;
  virtual bool operator^(const Card& t) const override;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;
protected:
  virtual void serialize(ostream& os) const override;
private:
};

#endif /* DRAWTWOCARD_H_ */
