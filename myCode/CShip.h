/*
 * CShip.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CSHIP_H
#define CSHIP_H
#include "CGridPosition.h"
#include <set>

/**
 * Creates ship.
 *
 */
class CShip
{
private:

	/**
	 * @param bow the bow position of a ship.
	 */
	CGridPosition bow;

	/**
	 * @param stern the bow position of a ship.
	 */
	CGridPosition stern;
public:

	/**
	 * Constructor of CShip.
	 * @param bow bow position of a ship.
	 * @param stern stern position of a ship.
	 */
	CShip(const CGridPosition &bow, const CGridPosition &stern);

	/**
	 * Checks if a position for ship is valid or not.
	 */
	bool isValid();

	/**
	 * Returns bow position of a ship.
	 */
	CGridPosition getBow() const;

	/**
	 * Returns stern position of a ship.
	 */
	CGridPosition getStern() const;

	/**
	 * Returns length of a ship.
	 */
	int length() const;

	/**
	 * Returns occupied area by ship as a set container.
	 */
	const std::set<CGridPosition> occupiedArea() const;

	/**
	 * Returns blocking area by ship as a set container.
	 */
	const std::set<CGridPosition> blockedArea();

	/**
	 * ostream overloading as a friend function.
	 * @param lhs right hand side position.
	 * @param rhs right hand side position.
	 */
	friend std::ostream& operator<<(std::ostream &lhs, CGridPosition rhs);
};

std::ostream& operator<<(std::ostream &lhs, CGridPosition rhs);

#endif /* CSHIP_H */
