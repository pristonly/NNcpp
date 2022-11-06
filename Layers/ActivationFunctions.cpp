#ifndef ILAYERS
#define ILAYERS
#endif
#include "ActivationFunctions.h"

double BinaryFunc(double value)
{
	if (value >= 0.5)
		return 1.0;
	else
		return 0.0;
}

double DerBinaryFunc(double value)
{
	return 1.0;
}