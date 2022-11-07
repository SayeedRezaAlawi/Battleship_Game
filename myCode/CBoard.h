/*
 * CBoard.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CBOARD_H
#define CBOARD_H
#include "COwnGrid.h"
#include "COpponentGrid.h"

/**
 * Creates a Battleship Game Board/
 *
 */
class CBoard
{
private:
	/**
	 * @param ownGrid OwnGrid in order to access own grid positions.
	 */
	COwnGrid ownGrid;
	/**
	 * @param opponentGrid OpponentGrid in order to access Opponent grid positions.
	 */
	COpponentGrid opponentGrid;
public:
	/**
	 * Constructor of CBoard.
	 * @param rows number of board rows.
	 * @param columns number of board columns.
	 */
	CBoard(int rows, int columns);
	/**
	 * return the number of rows
	 */
	int getRows();

	/**
	 * return the number of columns
	 */
	int getColumns();

	/**
	 * return the own grid.
	 */
	COwnGrid& getOwnGrid();

	/**
	 * return the opponent grid.
	 */
	COpponentGrid& getOpponentGrid();
};
#endif /* CBOARD_H */
