/*
 * CGridPosition.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CGRIDPOSITION_H
#define CGRIDPOSITION_H
#include <string>
#include <iostream>

/**
 * Creates a specific position of grid.
 *
 */
class CGridPosition
{
private:
	/**
	 * @param row Row index of GridPosition .
	 */
	char row;
	/**
	 * @param column column index of GridPosition .
	 */
	int column;

	/**
	 * @param position define a string as position.
	 */
	std::string position;
public:

	/**
	 * Constructor of CGridPosition.
	 * @param row input row index of a position.
	 * @param column input column index of a position.
	 */
	CGridPosition(char row = 'A', int column = 1);

	/**
	 * Constructor of CGridPosition.
	 * @param position input string index of a position.
	 */
	CGridPosition(std::string position);

	/**
	 * Checks if the position is valid.
	 */
	bool isValid() const;

	/**
	 * Returns the row index of a position.
	 */
	char getRow() const;

	/**
	 * Returns the column index of a position.
	 */
	int getColumn() const;

	/**
	 * String Overloading.
	 */
	operator std::string();

	/**
	 * Equalency overloading.
	 * @param other position of right hand side.
	 */
	bool operator==(const CGridPosition other) const;

	/**
	 * Less than overloading is used to compare if one position is less than other or not, whic
	 * can help to find occupied and block area in next phases.
	 * @param other position of right hand side.
	 */
	bool operator<(const CGridPosition other) const;

	/**
	 * ostream overloading as a friend function.
	 * @param lhs right hand side position.
	 * @param rhs right hand side position.
	 */
	friend std::ostream& operator<<(std::ostream &lhs, CGridPosition rhs);
};

std::ostream& operator<<(std::ostream &lhs, CGridPosition rhs);
#endif /* CGRIDPOSITION_H */
