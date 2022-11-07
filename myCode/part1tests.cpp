/*
 * part1tests.cpp
 *
 *      Author: mnl
 */

#include <iostream>
using namespace std;
#include <set>
#include "part1tests.h"
#include "CBoard.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

/**
 */
void part1tests()
{
//     Test GridPosition constructor
	assertTrue(CGridPosition
	{ 'A', 1 }.isValid(), "A1 not considered valid");
	assertTrue(!CGridPosition
	{ 'A', -1 }.isValid(), "A-1 considered valid");
	assertTrue(!CGridPosition
	{ '@', 1 }.isValid(), "@1 considered valid");
	CGridPosition fromRowCol
	{ 'A', 1 };
	CGridPosition fromString
	{ "A1" };
	assertTrue(
			fromRowCol.getRow() == fromString.getRow()
					&& fromRowCol.getColumn() == fromString.getColumn(),
			"different constructors return different objects");

//     Test getters and cast to string
	CGridPosition pos1 = CGridPosition
	{ 'B', 13 };
	assertTrue(pos1.getRow() == 'B',
			"GridPosition::GridPosition doesn't set row properly.");
	assertTrue(pos1.getColumn() == 13,
			"GridPosition::GridPosition doesn't set column properly.");
	assertTrue((string) pos1 == "B13", "Conversion to string fails.");

//     Test comparison
	assertTrue(!(CGridPosition
	{ "A1" } < CGridPosition
	{ "A1" }), "Same positions considered different by '<'");
	assertTrue(CGridPosition
	{ "A1" } < CGridPosition
	{ "B1" }, "Position with bigger row not considered greater");
	assertTrue(CGridPosition
	{ "A1" } < CGridPosition
	{ "A2" }, "Position with bigger column not considered greater");
	assertTrue(CGridPosition
	{ "C21" } == CGridPosition
	{ "C21" }, "Equal positions not considered equal.");

//     Test Ship Constructor
	assertTrue(!CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "C3" } }.isValid(), "Can create non-aligned ship.");
	assertTrue(!CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "B2" } }.isValid(), "Can create ship of size 1.");
	assertTrue(!CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "B7" } }.isValid(), "Can create ship of size 6.");

	// Length
	assertTrue(CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "B4" } }.length() == 3, "Length is not 3");
	assertTrue(CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "E2" } }.length() == 4, "Length is not 4");

//	 Occupied area
	assertTrue(CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "B4" } }.occupiedArea() == set<CGridPosition>
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "C2" }, CGridPosition
	{ "D2" }, CGridPosition
	{ "E2" } }, "Occupied area not correct");

}

