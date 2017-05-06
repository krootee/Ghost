/*
 * VectorCalculator.h
 *
 *  Created on: May 6, 2017
 *      Author: frode
 */

#ifndef MAIN_VECTORCALCULATOR_H_
#define MAIN_VECTORCALCULATOR_H_

#include <cmath>

typedef struct
{
	float x;
	float y;
} Point;

class VectorCalculator {
public:
	VectorCalculator();
	Point FindPointFromAngleAndDistance(int, int);
	Point SubtractPoints(Point, Point);
	float GetAngleBetweenVectors(Point, Point);
};

#endif /* MAIN_VECTORCALCULATOR_H_ */
