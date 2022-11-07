/*
 * part3tests.cpp
 *
 *      Author: Reza
 */
#include <iostream>
using namespace std;
#include "CBoard.h"
#include "CConsolView.h"
#include "part3tests.h"

void assertTruePart3(bool condition, string failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

void part3tests()
{
	CBoard board{ 10, 10 };
	CConsolView consol{ &board };
// Shot results before placing any ship on the board.

	assertTruePart3(!board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "F1" } }) == CShot::NONE, "The shot is not missed");

	assertTruePart3(board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "I2" } }) == CShot::HIT, "The shot is not HIT");

	assertTruePart3(board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "I3" } }) == CShot::HIT, "The shot is not HIT");

	assertTruePart3(board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "I4" } }) == CShot::SUNKEN, "The shot is not SUNKEM");

// print ships on Own board.

	board.getOwnGrid().placeShip(CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "B4" } });
	board.getOwnGrid().placeShip(CShip
	{ CGridPosition
	{ "D4" }, CGridPosition
	{ "G4" } });
	board.getOwnGrid().placeShip(CShip
	{ CGridPosition
	{ "F6" }, CGridPosition
	{ "F9" } });
	consol.print();

// print shots on own board.
	board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "B3" } });
	board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "B4" } });
	board.getOwnGrid().takeBlow(CShot
	{ CGridPosition
	{ "B5" } });
	consol.print();

// Sunken Ships Detection

	board.getOpponentGrid().shotresult(CShot
	{ CGridPosition
	{ "G4" } }, CShot::NONE);
	board.getOpponentGrid().shotresult(CShot
	{ CGridPosition
	{ "C2" } }, CShot::NONE);
	board.getOpponentGrid().shotresult(CShot
	{ CGridPosition
	{ "G5" } }, CShot::HIT);
	board.getOpponentGrid().shotresult(CShot
	{ CGridPosition
	{ "I5" } }, CShot::NONE);
	board.getOpponentGrid().shotresult(CShot
	{ CGridPosition
	{ "F5" } }, CShot::NONE);
	board.getOpponentGrid().shotresult(CShot
	{ CGridPosition
	{ "G6" } }, CShot::SUNKEN);

// Print Shots on opponent board
	consol.print();
}

