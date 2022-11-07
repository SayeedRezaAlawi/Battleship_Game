/*
 * CShip.cpp
 *
 *      Author: Sayeed Reza Alawi
 */
#include <iostream>
using namespace std;
#include "CShip.h"

CShip::CShip(const CGridPosition &bow, const CGridPosition &stern)
{
	this->bow = bow;
	this->stern = stern;
}

bool CShip::isValid()
{
	if (bow.getRow() >= 'A' && bow.getRow() <= 'Z' && stern.getRow() >= 'A'
			&& stern.getRow() <= 'Z')
	{
		if (bow.getColumn() > 0 && stern.getColumn() > 0 && length() >= 2
				&& length() <= 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

CGridPosition CShip::getBow() const
{
	return bow;
}

CGridPosition CShip::getStern() const
{
	return stern;
}

int CShip::length() const
{
	int lenght = 0;

	if (bow.getRow() == stern.getRow())
	{
		for (int i = bow.getColumn(); i <= stern.getColumn(); i++)
		{
			lenght++;
		}
	}
	else if(bow.getColumn() == stern.getColumn())
	{
		for (char i = bow.getRow(); i <= stern.getRow(); i++)
		{
			lenght++;
		}
	}
	return lenght;
}

const std::set<CGridPosition> CShip::occupiedArea() const
{
	std::set<CGridPosition> s;
	if (bow.getRow() == stern.getRow())
	{
		for (int column = bow.getColumn(); column <= stern.getColumn();
				column++)
		{
			s.insert(CGridPosition(bow.getRow(), column));
		}
	}
	else
	{
		for (char row = bow.getRow(); row <= stern.getRow(); row++)
		{
			s.insert(CGridPosition(row, bow.getColumn()));
		}
	}

	return s;
}

const std::set<CGridPosition> CShip::blockedArea()
{
	std::set<CGridPosition> query;
	CGridPosition position;
	set<CGridPosition> g = occupiedArea();
	for (auto it = g.begin(); it != g.end(); it++)
	{
		position = *it;
		for (char row = position.getRow() - 1; row <= position.getRow() + 1;
				row++)
		{
			for (int column = position.getColumn() - 1;
					column <= position.getColumn() + 1; column++)
			{
				query.insert(CGridPosition(row, column));
			}
		}
	}
//					cout << "The elements in set are: ";
//						    for (auto it = query.begin(); it != query.end(); it++)
//						    {
//						        cout << *it << " ";
//						    }
//						    cout << endl;
	return query;
}

std::ostream& operator <<(std::ostream &lhs, CShip rhs)
{
	lhs << rhs.getBow();
	return lhs;
}
