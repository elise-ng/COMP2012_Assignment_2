/*
 * SkipCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef SKIPCARD_H_
#define SKIPCARD_H_

#import "Card.h"

class SkipCard : public Card {
public:
  SkipCard(Color);
  virtual ~SkipCard() override;
  virtual bool operator^(const Card& t) const override;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;
protected:
  virtual void serialize(ostream& os) const override;
private:
};

#endif /* SKIPCARD_H_ */
