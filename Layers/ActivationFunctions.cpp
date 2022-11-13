#ifndef ILAYERS
#define ILAYERS
#endif
#include "ActivationFunctions.h"

#include <math.h>

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

double LogisticFunc(double value)
{
	return 1.0 / (1.0 + exp(-value));
}

double DerLogisticFunc(double value)
{
	return LogisticFunc(value) * (1 - LogisticFunc(value));
}