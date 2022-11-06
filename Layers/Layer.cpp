#include "Layer.h"

double& GetWeightBeetween(size_t numCurrentNeuron, size_t numNextLayerNeuron, Layer* currentLayer, Layer * nextLayer)
{
	return currentLayer->m_weights[numNextLayerNeuron + numCurrentNeuron * nextLayer->m_height];
}