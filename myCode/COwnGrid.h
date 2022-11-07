/*
 * COwngrid.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef COWNGRID_H
#define COWNGRID_H
#include "CShip.h"
#include <vector>
#include <stdlib.h>
#include "CShot.h"

/**
 * Creates Own grid.
 *
 */
class COwnGrid
{
private:
	/**
	 * @param rows number of rows of grid.
	 */
	int rows;

	/**
	 * @param columns number of columns of grid.
	 */
	int columns;

	/**
	 * @param shipnumbers current number of ships on the board.
	 */
	int shipnumbers = 0;
	/**
	 * @param ships numbers of pointer to show ships on own grid.
	 */
	CShip *ships[10];

	/**
	 * A set container which keeps shot grid positions.
	 * @param shotAt shot position on the grid.
	 */
	std::set<CGridPosition> shotAt;
public:

	/**
	 * Constructor of COwnGrid.
	 * @param rows number of grid rows.
	 * @param columns number of grid columns.
	 */
	COwnGrid(int rows = 10, int columns = 10);

	/**
	 * return the number of rows
	 */
	int getRows();

	/**
	 * return the number of columns
	 */
	int getColumns();

	/**
	 * Method to place a ship of the grid.
	 * @param ship type of ship.
	 */
	bool placeShip(const CShip &ship);

	/**
	 * A vector container which keeps ships information.
	 * @param CShip container type.
	 */
	const std::vector<CShip> getShips();

	/**
	 * Returns impact of a shot.
	 * @param shot shot on the own board.
	 */
	CShot::Impact takeBlow(const CShot &shot);

	/**
	 * Returns a set container which keeps shots informations.
	 * @param CGridPosition container type.
	 */
	const std::set<CGridPosition> getShotAt();
};

#endif /* COWNGRID_H */
