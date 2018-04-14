/*
 * WildCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef WILDCARD_H_
#define WILDCARD_H_

#include "Card.h"

class WildCard : public Card {
public:
  WildCard();
  virtual ~WildCard() = default;
  virtual bool operator^(const Card& t) const override;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;
  virtual void init() override;
protected:
  virtual void serialize(ostream& os) const override;
private:
};

#endif /* WILDCARD_H_ */
