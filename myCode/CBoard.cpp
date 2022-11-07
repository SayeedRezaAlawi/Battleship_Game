/*
 * CBoard.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CBoard.h"

CBoard::CBoard(int rows, int columns)
{

}

int CBoard::getRows()
{
	return ownGrid.getRows();
}

int CBoard::getColumns()
{
	return ownGrid.getColumns();
}

COwnGrid& CBoard::getOwnGrid()
{
	return ownGrid;
}

COpponentGrid& CBoard::getOpponentGrid()
{
	return opponentGrid;
}
