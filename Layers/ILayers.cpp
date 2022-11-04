#ifndef ILAYERS
#define ILAYERS
#endif

#include "ILayers.h"

#include <cstring>


Layers::Layers()
{
	auto t = std::time(0);
	srand(t);
}

void Layers::AddNewLayer(uint64_t height,
	uint64_t width,
	LAYERSTYPES type,
	double (*funcActivation)(double))
{
	auto lastElem = m_layers.AddNewElem();
	lastElem->m_funcActivation = funcActivation;
	lastElem->m_height = height;
	lastElem->m_width = width;
	lastElem->m_value = new double[height * width];
	std::memset(lastElem->m_value, 0.0, sizeof(double) * height * width);
	lastElem->m_weights = nullptr;
	lastElem->m_type = type;
	lastElem->m_weightsSize = 0;
}

void Layers::DeleteLayer(uint64_t number)
{

}

void Layers::InitWeights()
{
	for (int i = 0; i < static_cast<int>(m_layers.Size() - 1); ++i)
	{
		Layer* current = m_layers.GetLayer(static_cast<size_t>(i));
		Layer* next = m_layers.GetLayer(static_cast<size_t>(i + 1));
		if (current->m_type == DFF)
		{
			uint64_t WeightsCount = current->m_height * next->m_height;
			delete[] current->m_weights;
			current->m_weightsSize = WeightsCount;
			current->m_weights = new double[WeightsCount];
			for (size_t j = 0; j < WeightsCount; ++j)
				current->m_weights[j] = static_cast<double>(rand() % 100) / 100;
		}
	}
}

double* Layers::InputLayer()
{
	return m_layers.GetLayer(0)->m_value;
}

double* Layers::OutputLayer()
{
	return m_layers.GetLayer(m_layers.Size())->m_value;
}

Layers::~Layers()
{

}