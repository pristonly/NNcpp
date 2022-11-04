#pragma once
#pragma warning( disable : 4251 )
#include "ILayers.h"

class IMPORT_EXPORT FORWARD_DISTURB : public Layers
{
	void CalculateDFF(Layer*, Layer*);
public:
	void Run();
};

struct IMPORT_EXPORT batch {
	std::vector<double> m_input;
	std::vector<double> m_answer;
	size_t m_answerSize = 1; // Размер ответа в батче
	size_t m_inputSize = 2; // Размер входных данных в батче
};

class IMPORT_EXPORT DataSet
{
	std::vector<batch> m_batch;
	size_t m_batchSize = 0;
public:
	DataSet() = default;
	DataSet(std::istream& inputdata, std::istream& answerdata, size_t batchSize = 1);
	DataSet(const DataSet&) = delete;
	DataSet(DataSet&&) = delete;
	DataSet& operator=(const DataSet&) = delete;
	DataSet& operator=(DataSet&&) = delete;
	const batch& GetNextBatch() const;
	size_t GetBatchSize() const;
};

class IMPORT_EXPORT TEACHER : public FORWARD_DISTURB
{
	double m_teachingCoeff;
	double m_error = 9999.0;
	DataSet& m_teachingData;
public:
	TEACHER(DataSet& dataset) : m_teachingCoeff(0.05), m_teachingData(dataset) {}
	void StartTeaching();
private:
	void GetBatchError(const batch&);
	void UpdateWeights();
};