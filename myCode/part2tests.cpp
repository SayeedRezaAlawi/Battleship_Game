/*
 * part2tests.cpp
 *
 *      Author: mnl
 */

#include <iostream>
using namespace std;
#include <set>
#include "part2tests.h"
#include "CBoard.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTruePart2(bool condition, string failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

/**
 */

void part2tests()
{
	// Ship Arrangement rules
	COwnGrid owngrid{10,10};

	assertTruePart2((owngrid.placeShip(CShip
	{ CGridPosition
	{ "H1" }, CGridPosition
	{ "H9" } })), "There is no such ship");
	assertTruePart2((owngrid.placeShip(CShip
	{ CGridPosition
	{ "A1" }, CGridPosition
	{ "C1" } })), "The ship cannot be place on the edge");
	assertTruePart2((owngrid.placeShip(CShip
	{ CGridPosition
	{ "B2" }, CGridPosition
	{ "B4" } })), "Two Ship are in touch");
	assertTruePart2(owngrid.placeShip(CShip
	{ CGridPosition
	{ "J2" }, CGridPosition
	{ "J5" } }), "horizontal ship replacement is failed");
	assertTruePart2(owngrid.placeShip(CShip
	{ CGridPosition
	{ "G9" }, CGridPosition
	{ "J9" } }), "vertical ship replacement is failed");

}

