/*
 * CConsolView.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CConsolView.h"
#include <iostream>
using namespace std;

CConsolView::CConsolView(CBoard *board)
{
	this->board = board;
}

void CConsolView::print()
{
	int ownRow = board->getOwnGrid().getRows();
	int ownColumn = board->getOwnGrid().getColumns();
	int opponentRow = board->getOpponentGrid().getRows();
	int opponentColumn = board->getOpponentGrid().getColumns();
	int noShipsOnBoard = board->getOwnGrid().getShips().size();
	////////////////////////////////////////////////////

	char opponentrow = 'A';
	char opponentFields[opponentrow][opponentColumn];
	char ownrow = 'A';
	char ownFields[ownrow][ownColumn];
	////////////////////////////////////////////////////////

	for (char row = 'A'; row <= 'J'; row++)
	{
		for (int column = 0; column < ownColumn; column++)
		{

			opponentFields[row][column] = '~';
		}
	}

///////////////////////////////////////////////////

	for (char row = 'A'; row <= 'J'; row++)
	{
		for (int column = 0; column < ownColumn; column++)
		{

			ownFields[row][column] = '~';
		}
	}
	///////////////////////////////////////////////////////////////
	CGridPosition shipposition;
	for (int i = 0; i < noShipsOnBoard; i++)
	{
		set<CGridPosition> occupied =
				board->getOwnGrid().getShips().at(i).occupiedArea();
		for (auto it = occupied.begin(); it != occupied.end(); it++)
		{
			shipposition = *it;
			ownFields[shipposition.getRow()][shipposition.getColumn() - 1] =
					'#';
		}
	}
	/////////////////////////////////////////////////////////////
	set<CGridPosition> shots = board->getOwnGrid().getShotAt();
	CGridPosition shot;
	CShot::Impact shot_state;
	for (auto it = shots.begin(); it != shots.end(); it++)
	{
		shot = *it;
		shot_state = board->getOwnGrid().takeBlow(CShot
		{ shot });
		if (shot_state == 0)
		{
			ownFields[shot.getRow()][shot.getColumn() - 1] = '^';
		}
		else if (shot_state == 1)
		{
			ownFields[shot.getRow()][shot.getColumn() - 1] = 'O';
		}
		else if (shot_state == 2)
		{
			ownFields[shot.getRow()][shot.getColumn() - 1] = 'O';
		}
		shots.erase(it);
	}

	///////////////////////////////////////////////////////////////
	for (int i = 3; i < 6; i++)
	{
		opponentFields['C'][i - 1] = '#';
	}

	/////////////////////////////////////////////////////////////
	std::map<CGridPosition, CShot::Impact> opponetshots =
			board->getOpponentGrid().getShotAt();
	CGridPosition opponentshot;

	CShot::Impact opponentshot_state;
	for (auto it = opponetshots.begin(); it != opponetshots.end(); it++)
	{
		opponentshot = it->first;
		opponentshot_state = it->second;
		if (opponentshot_state == 0)
		{
			opponentFields[opponentshot.getRow()][opponentshot.getColumn() - 1] =
					'^';
		}
		else if (opponentshot_state == 1)
		{
			opponentFields[opponentshot.getRow()][opponentshot.getColumn() - 1] =
					'O';
		}
		else if (opponentshot_state == 2)
		{
			opponentFields[opponentshot.getRow()][opponentshot.getColumn() - 1] =
					'O';
		}
	}

	////////////////////////////////////////////////////////////
	char charrow = 'A';
	int intcolumn = 1;
	cout << "   ";
	for (int i = 0; i < 2; i++)
	{
		for (int column = 0; column < ownColumn; column++)
		{
			cout << intcolumn << "  ";
			intcolumn++;
		}
		intcolumn = 1;
		cout << "   ";
	}
	cout << endl;
	for (char row = 'A'; row <= 'J'; row++)
	{
		cout << charrow << " ";

		for (int column = 0; column < ownColumn; column++)
		{
			cout << " ";
			cout << ownFields[row][column];
			cout << " ";
		}
		cout << "  ";
		cout << charrow << " ";
		for (int column = 0; column < opponentColumn; column++)
		{
			cout << " ";
			cout << opponentFields[row][column];
			cout << " ";
		}
		charrow++;
		cout << endl;
	}

	cout << endl;
	cout << endl;
	////////////////////////////////////////////////////////////////////////////
}
