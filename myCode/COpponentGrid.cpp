/*
 * COpponentGrid.cpp
 *
 *      Author: Sayeed Reza Alawi
 */
#include "COpponentGrid.h"
#include <iostream>
using namespace std;

COpponentGrid::COpponentGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

int COpponentGrid::getRows()
{
	return rows;
}

int COpponentGrid::getColumns()
{
	return columns;
}

void COpponentGrid::shotresult(const CShot &shot, CShot::Impact impact)
{
	static int noSunkenShip = 0;
	char row;
	int column;
	std::set<CGridPosition> positions;
	std::vector<CGridPosition> sunkenshipposition;
	positions.insert(shot.getTargetPosition());
	std::vector<CGridPosition> hits;
	shots.insert(
	{ shot.getTargetPosition(), impact });

	auto it = shots.begin();
	// Iterate through the map
	while (it != shots.end())
	{
		// Check if value of this entry matches with given value
		if (it->second == CShot::HIT || it->second == CShot::SUNKEN)
		{
			// Push the key in given map
			hits.push_back(it->first);
		}
		// Go to next entry in map
		it++;
	}
	if (impact == CShot::SUNKEN)
	{
		CGridPosition position = shot.getTargetPosition();
		for (unsigned i = 0; i < hits.size(); i++)
		{

			if (position.getRow() == hits.at(i).getRow())
			{

				sunkenshipposition.push_back(CGridPosition
				{ position.getRow(), hits.at(i).getColumn() });
				row = position.getRow();

			}
			else if (position.getColumn() == hits.at(i).getColumn())
			{
				sunkenshipposition.push_back(CGridPosition
				{ hits.at(i).getRow(), position.getColumn() });
				column = position.getColumn();
			}
		}

		sunkenShips[noSunkenShip] = new CShip
		{ sunkenshipposition.front(), sunkenshipposition.back() };
		cout << "Sunken chip elements are: ";
		for (auto it = sunkenshipposition.begin();
				it != sunkenshipposition.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

}

const std::map<CGridPosition, CShot::Impact>& COpponentGrid::getShotAt()
{
	return shots;
}

