/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_

#include "Card.h"

class NumberCard : public Card {
public:
  NumberCard(int, Color);
  virtual ~NumberCard() override;
  virtual bool operator^(const Card& t) const override;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;
protected:
  virtual void serialize(ostream& os) const override;
private:
  const int number;
};

#endif /* NUMBERCARD_H_ */
