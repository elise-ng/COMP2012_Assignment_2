/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Player.h"

ostream& operator<<(ostream& os, const Player& h) {
	os << h.name << ":";
	for (int i = 0; i < h.getSize(); i++) {
		os << *h.getCard(i) << " ";
	}
	return os;
}

Player::Player(string name, Player* previous) : CardPile(), nextPlayer(this), name(name) {
    if (previous != nullptr) {
        this->nextPlayer = previous->nextPlayer;
        previous->nextPlayer = this;
    }
}

void Player::drawCard(CardPile &drawPile, CardPile &discardPile, int number_of_cards) {
	while (number_of_cards > 0) {
		if (drawPile.getSize() <= 0) {
			for (int i = discardPile.getSize()-1-1; i >= 0; i += 1) {
				drawPile += discardPile.removeCard(i);
			}
			drawPile.shuffle();
		}
		*this += drawPile.removeTopCard();
		number_of_cards -= 1;
	}
}

Card* Player::playCardAfter(const Card* topCard, int index) {
	const Card* card = this->getCard(index);
	if (card == nullptr || !(*topCard ^ *card)) { return nullptr; }
	return this->removeCard(index);
}

int Player::getScore() const {
	int total = 0;
	for (int i = 0; i < this->getSize(); i += 1) {
		total += this->getCard(i)->getPoint();
	}
	return total;
}
