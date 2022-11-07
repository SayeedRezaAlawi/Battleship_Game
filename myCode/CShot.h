/*
 * CShot.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CSHOT_H_
#define CSHOT_H_
#include "CGridPosition.h"

/**
 * Creates shots.
 *
 */
class CShot
{
private:
	/**
	 * @param targetPosition target position of a shot.
	 */
	CGridPosition targetPosition;
public:

	/**
	 * Constructor of CShot.
	 * @param targetPosition target position of a shot.
	 */
	CShot(CGridPosition targetPosition);

	/**
	 * Returns the targetPosition.
	 */
	CGridPosition getTargetPosition() const;

	/**
	 * Enumuration for impact of shot.
	 * @param NONE No impact.
	 * @param HIT hit the ship.
	 * @param SUNKEN final hit and sink the ship.
	 */
	enum Impact
	{
		NONE = 0, HIT = 1, SUNKEN = 2,
	};

};
#endif /* CSHOT_H_ */
