#pragma once

#include "ActivationFunctions.h"
#include "List.h"

#include <random>
#include <chrono>

class IMPORT_EXPORT ILayer
{
public:
	virtual void AddNewLayer(uint64_t height,
		uint64_t width = 1U,
		LAYERSTYPES type = DFF,
		double (*funcActivation)(double) = BinaryFunc,
		double (*derFuncActivation)(double) = DerBinaryFunc) = 0;
	virtual void DeleteLayer(uint64_t number) = 0;
	virtual ~ILayer() = default;
};

class IMPORT_EXPORT Layers : ILayer
{
protected:
	List m_layers;
public:
	class Iterator;
	Layers();
	void AddNewLayer(
		uint64_t height, 
		uint64_t width = 1U, 
		LAYERSTYPES type = DFF, 
		double (*funcActivation)(double) = BinaryFunc,
		double (*derFuncActivation)(double) = DerBinaryFunc
	);
	double* InputLayer();
	double* OutputLayer();
	void InitWeights();
	void DeleteLayer(uint64_t number);
	virtual ~Layers();
};