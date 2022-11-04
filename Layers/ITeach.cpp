#ifndef ILAYERS
#define ILAYERS
#endif
#pragma warning( disable : 4251 )

#include "ITeach.h"

#include <string>
#include <vector>

typedef std::pair<std::vector<double>, std::vector<double>> RETCONVERTER;

RETCONVERTER ReadAndConvert(std::istream& input, std::istream& answer)
{
	std::string inputstr;
	std::vector<double> inputvec;
	std::string answerstr;
	std::vector<double> answervec;

	while (!std::getline(input, inputstr).eof())
	{
		inputvec.emplace_back(std::atof(inputstr.c_str()));
		inputstr.clear();
	}
	inputvec.emplace_back(std::atof(inputstr.c_str()));

	while (!std::getline(answer, answerstr).eof())
	{
		answervec.emplace_back(std::atof(answerstr.c_str()));
		answerstr.clear();
	}
	answervec.emplace_back(std::atof(answerstr.c_str()));

	return std::make_pair(inputvec, answervec);
}

void FORWARD_DISTURB::CalculateDFF(Layer* current, Layer* next)
{
	for (size_t i = 0; i < next->m_height; ++i)
	{
		for (size_t j = 0; j < current->m_height; ++j)
		{
			next->m_value[i] += (current->m_value[j] * current->m_weights[j * next->m_height + i]);
		}
		next->m_value[i] = next->m_funcActivation(next->m_value[i]);
	}
}

void FORWARD_DISTURB::Run()
{
	int64_t layers = static_cast<int64_t>(m_layers.Size());
	for (int64_t i = 0; i < layers - 1; ++i)
	{
		Layer* current = m_layers.GetLayer(static_cast<size_t>(i));
		Layer* next = m_layers.GetLayer(static_cast<size_t>(i + 1));
		if(next->m_type == DFF)
			CalculateDFF(current, next);
	}
}

DataSet::DataSet(std::istream& inputdata, std::istream& answerdata, size_t batchSize)
{
	//Необходимо дополнить количеством входных данных на батч и соответственно ответов
	auto temp(ReadAndConvert(inputdata, answerdata));
	m_batch.emplace_back();
	m_batch.back().m_input = std::move(temp.first);
	m_batch.back().m_answer = std::move(temp.second);
	m_batchSize = batchSize;
}

const batch& DataSet::GetNextBatch() const
{
	return m_batch.back();
}

size_t DataSet::GetBatchSize() const
{
	return m_batchSize;
}

void TEACHER::StartTeaching()
{
	for (size_t i = 0; i < 10000; ++i)
	{
		const batch& currentBatch = m_teachingData.GetNextBatch();
		GetBatchError(currentBatch);
	}
}

void TEACHER::GetBatchError(const batch& Batch)
{
	m_error = 0.0;
	auto batchSize = m_teachingData.GetBatchSize();

	std::vector<double> errors(batchSize, 0.0);

	auto lastLayer = m_layers.Size() - 1;
	auto inputSize = m_layers.GetLayer(0)->m_height;
	auto answerSize = m_layers.GetLayer(lastLayer)->m_height;
	
	errors.emplace_back(0.0);

	for (size_t numBatch = 0; numBatch < batchSize; ++numBatch)
	{
		for (size_t i = 0; i < inputSize; ++i)
		{
			m_layers.GetLayer(0)->m_value[i] = Batch.m_input[i + numBatch * inputSize];
		}
		Run();
		for (size_t i = 0; i < Batch.m_answerSize; ++i)
		{
			errors[numBatch] += pow((Batch.m_answer[i + numBatch * inputSize] - m_layers.GetLayer(lastLayer)->m_value[i]), 2);
		}
		errors[numBatch] *= 0.5;

		m_error += errors[numBatch];
	}
	 
	m_error /= batchSize;
}