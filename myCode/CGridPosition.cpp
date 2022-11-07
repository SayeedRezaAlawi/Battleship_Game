/*
 * CGridPosition.cpp
 *
 *      Author: Sayeed Reza Alawi
 */
#include "CGridPosition.h"
#include <string.h>
using namespace std;

CGridPosition::CGridPosition(char row, int column)
{
	this->row = row;
	this->column = column;
}

CGridPosition::CGridPosition(std::string position)
{
	int n = position.length();
	char char_array[n + 1];
	strcpy(char_array, position.c_str());
	row = char_array[0];
	column = char_array[1] - 48;
}

bool CGridPosition::isValid() const
{
	if (row >= 'A' && row <= 'Z')
	{
		if (column > 0)
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

char CGridPosition::getRow() const
{
	return row;
}

int CGridPosition::getColumn() const
{
	return column;
}

CGridPosition::operator std::string()
{
	string col = to_string(column);
	std::string position = row + col;
	return position;
}

bool CGridPosition::operator ==(const CGridPosition other) const
{
	return this->row == other.row && this->column == other.column;
}

bool CGridPosition::operator <(const CGridPosition other) const
{
	if (this->row < other.row)
	{
		return true;
	}

	else if (this->row > other.row)
	{
		return false;
	}

	else
	{
		return this->column < other.column;
	}

}

std::ostream& operator <<(std::ostream &lhs, CGridPosition rhs)
{
	lhs
			<< rhs.operator std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>();
	return lhs;
}
