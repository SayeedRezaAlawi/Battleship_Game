/*
 * COwngrid.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "COwnGrid.h"
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

COwnGrid::COwnGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;

}

int COwnGrid::getRows()
{
	return rows;
}

int COwnGrid::getColumns()
{
	return columns;
}

bool COwnGrid::placeShip(const CShip &ship)
{
	static std::map<int, int> map;
	map.insert(std::pair<int, int>(5, 1));
	map.insert(pair<int, int>(4, 2));
	map.insert(pair<int, int>(3, 3));
	map.insert(pair<int, int>(2, 4));
	set<CGridPosition> occupied[10];
	set<CGridPosition> block[10];
	std::set<CGridPosition> intersection;

	ships[shipnumbers] = new CShip
	{ ship.getBow(), ship.getStern() };
	for (int i = shipnumbers; i >= 0; i--)
	{
		occupied[i] = ships[i]->occupiedArea();
		block[i] = ships[i]->blockedArea();
	}

	for (int i = 0; i < shipnumbers; i++)
	{
		set_intersection(block[i].begin(), block[i].end(),
				occupied[shipnumbers].begin(), occupied[shipnumbers].end(),
				std::inserter(intersection, intersection.begin()));
	}

	if (map[ships[shipnumbers]->length()] > 0 && intersection.empty())
	{
		map[ships[shipnumbers]->length()] -= 1;
		shipnumbers++;
		return true;
	}
	else if (!intersection.empty())
	{
		return false;
	}

	return false;
}

const std::vector<CShip> COwnGrid::getShips()
{
	std::vector<CShip> query;
	for (int i = 0; i < shipnumbers; i++)
		query.push_back(*ships[i]);
	return query;
}

CShot::Impact COwnGrid::takeBlow(const CShot &shot)
{
	int intersize = 0;
	int shiplength = 0;
	shotAt.insert(shot.getTargetPosition());
	std::set<CGridPosition> shotat;
	shotat.insert(shot.getTargetPosition());
	std::set<CGridPosition> intersection;
	for (int i = 0; i < shipnumbers; i++)
	{
		set<CGridPosition> g = getShips().at(i).occupiedArea();
		set_intersection(g.begin(), g.end(), shotat.begin(), shotat.end(),
				std::inserter(intersection, intersection.begin()));
		intersize = intersection.size();
		shiplength = getShips().at(i).length();
		if (!intersection.empty() && intersize == (shiplength - 1))
		{
//				cout << "Final Hit" << endl;
			shotat.clear();
			intersection.clear();
			return CShot::HIT;
			break;
		}
		else if (!intersection.empty() && intersize == shiplength)
		{
//				cout << "SUCKEN" << endl;
			shotat.clear();
			intersection.clear();
			return CShot::SUNKEN;
			break;
		}
		else if (!intersection.empty())
		{
//				cout << "hit " << endl;
			shotat.clear();
			intersection.clear();
			return CShot::HIT;
			break;
		}
	}
//	cout << "none " << endl;
	shotat.clear();
	intersection.clear();
	return CShot::NONE;
}

const std::set<CGridPosition> COwnGrid::getShotAt()
{
	return shotAt;
}

