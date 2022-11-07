/*
 * CShot.cpp
 *
 *      Author: Sayeed Reza Alawi
 */
#include "CShot.h"
CShot::CShot(CGridPosition targetPosition)
{
	this->targetPosition = targetPosition;
}

CGridPosition CShot::getTargetPosition() const
{
	return targetPosition;
}

