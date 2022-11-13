#pragma once
#if defined( ILAYERS )
#define IMPORT_EXPORT __declspec(dllexport)
#else
#define IMPORT_EXPORT __declspec(dllimport)
#endif

IMPORT_EXPORT double BinaryFunc(double value);
IMPORT_EXPORT double DerBinaryFunc(double value);
IMPORT_EXPORT double LogisticFunc(double value);
IMPORT_EXPORT double DerLogisticFunc(double value);