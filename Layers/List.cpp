#ifndef ILAYERS
#define ILAYERS
#endif
#include "List.h"

List::Node::Node() : 
	m_current(nullptr),
	m_ptrNextNode(nullptr),
	m_ptrPrevNode(nullptr)
{

}

List::~List()
{
	if (m_ptrBegin)
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			delete m_ptrBegin->m_current;
			m_ptrBegin = m_ptrBegin->m_ptrNextNode;
		}
	}
	m_ptrBegin = m_ptrEnd = nullptr;
	m_size = 0;
}

List::List() : 
	m_ptrBegin(nullptr),
	m_ptrEnd(nullptr),
	m_size(0)
{

}

Layer* List::AddNewElem()
{
	Layer* temp = new Layer;
	Node* tempNode = new Node;
	++m_size;

	if (m_ptrEnd)
	{
		m_ptrEnd->m_ptrNextNode = tempNode;
		tempNode->m_ptrPrevNode = m_ptrEnd;
		tempNode->m_current = temp;
		tempNode->m_ptrNextNode = nullptr;
		m_ptrEnd = tempNode;
	}
	else
	{
		m_ptrBegin = m_ptrEnd = tempNode;
		tempNode->m_ptrPrevNode = m_ptrEnd;
		tempNode->m_current = temp;
		tempNode->m_ptrNextNode = nullptr;
	}
	return temp;
}

Layer* List::GetLayer(size_t index)
{
	Node* current = nullptr;
	for (size_t i = 0; i <= index; ++i)
	{
		if (current != nullptr)
			current = current->m_ptrNextNode;
		else
			current = m_ptrBegin;
	}
	return current ? current->m_current : nullptr;
}

