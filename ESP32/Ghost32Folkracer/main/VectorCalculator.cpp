/*
 * VectorCalculator.cpp
 *
 *  Created on: May 6, 2017
 *      Author: frode
 */

#include "VectorCalculator.h"

VectorCalculator::VectorCalculator() {
	// TODO Auto-generated constructor stub
}

Point VectorCalculator::FindPointFromAngleAndDistance(int angle, int distance) {
	float x = distance * cos((float)angle/180.0*M_PI);
	float y = distance * sin((float)angle/180.0*M_PI);

	Point p = {x: x, y: y};
	return p;
}

Point VectorCalculator::SubtractPoints(Point p1, Point p2) {
	Point
	v = {x: p1.x - p2.x, y: p1.y - p2.y};
	return v;
}

float max(float a, float b) {
	return (a > b ? a : b);
}

float VectorCalculator::GetAngleBetweenVectors(Point v1, Point v2) {
	float length_v1 = sqrt(v1.x * v1.x + v1.y * v1.y);
	float length_v2 = sqrt(v2.x * v2.x + v2.y * v2.y);

	float v1Dotv2 = v1.x * v2.x + v1.y * v2.y;

	float length_v1TimesLength_v2 = max(length_v1 * length_v2, 0.00001);

	return acos(v1Dotv2 / length_v1TimesLength_v2);
}
