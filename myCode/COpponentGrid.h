/*
 * COpponentGrid.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef COPPONENTGRID_H
#define COPPONENTGRID_H
#include "CShip.h"
#include "CShot.h"
#include <map>
#include <vector>

/**
 * Creates opponent grid.
 *
 */
class COpponentGrid
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
	 * @param shots a map container which keeps shot position and its impact.
	 */
	std::map<CGridPosition, CShot::Impact> shots;
	/**
	 * @param sunkenShips numbers of pointer to show sunken ships.
	 */
	CShip *sunkenShips[10];
public:

	/**
	 * Constructor of COpponentGrid.
	 * @param rows number of grid rows.
	 * @param columns number of grid columns.
	 */
	COpponentGrid(int rows = 10, int columns = 10);

	/**
	 * return the number of rows
	 */
	int getRows();

	/**
	 * return the number of columns
	 */
	int getColumns();

	/**
	 * Keeps the result of shots on the opponent grid.
	 * @param shot shot
	 * @param Impact impact of shot
	 */
	void shotresult(const CShot &shot, CShot::Impact impact);

	/**
	 * A map contains shots and impacts
	 * @param shot shot
	 * @param Impact impact of shot
	 */
	const std::map<CGridPosition, CShot::Impact>& getShotAt();
};

#endif /* COPPONENTGRID_H */
