/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_

#include "Card.h"
using namespace std;

class NumberCard : public Card {
public:
  NumberCard(int, Color);
  ~NumberCard();
  virtual bool operator^(const Card& t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
  virtual void serialize(ostream& os) const;
private:
  const int number;
};

#endif /* NUMBERCARD_H_ */
