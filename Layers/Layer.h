#pragma once
#include <stdint.h>

#if defined( ILAYERS )
#define IMPORT_EXPORT __declspec(dllexport)
#else
#define IMPORT_EXPORT __declspec(dllimport)
#endif

enum IMPORT_EXPORT LAYERSTYPES
{
	DFF,
	CONVOLUTION
};

struct IMPORT_EXPORT Layer
{
	uint64_t m_height;
	uint64_t m_width;
	size_t m_weightsSize;
	double* m_weights;
	double* m_value;
	double (*m_funcActivation)(double);
	double (*m_DerfuncActivation)(double);
	LAYERSTYPES m_type;
};

IMPORT_EXPORT double& GetWeightBeetween(size_t numCurrentNeuron, size_t numNextLayerNeuron, Layer* currentLayer, Layer* nextLayer);