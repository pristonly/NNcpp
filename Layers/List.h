#pragma once
#include <cstddef>

#include "Layer.h"


class IMPORT_EXPORT List
{
	struct IMPORT_EXPORT Node
	{
		Node();
		Layer* m_current;
		Node* m_ptrNextNode;
		Node* m_ptrPrevNode;
	} * m_ptrBegin, * m_ptrEnd;
	size_t m_size;

public:
	List();
	Layer* AddNewElem();
	Layer* GetLayer(size_t index);
	size_t Size() { return m_size; }
	~List();
};