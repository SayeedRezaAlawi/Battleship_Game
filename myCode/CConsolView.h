/*
 * CConsolView.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CCONSOLVIEW_H
#define CCONSOLVIEW_H

#include "CBoard.h"

/**
 * Creates console view for printing the board.
 *
 */
class CConsolView
{
private:
	/**
	 * @param board pointer to board.
	 */
	CBoard *board;
public:

	/**
	 * Constructor of CConsolView.
	 * @param board receives the pointer of CBoard.
	 */
	CConsolView(CBoard *board);

	/**
	 * Prints the board.
	 */
	void print();
};

#endif /* CCONSOLVIEW_H */
