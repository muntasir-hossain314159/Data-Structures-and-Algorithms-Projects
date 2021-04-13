#pragma once
#include "ReelNode.hpp"
#include "Item.hpp"
#include <iostream>

template <typename T>
class Reel
{
private:
	int length;
	ReelNode<T>* currentPos;
	ReelNode<T>* head;

public:
	Reel() : length{ 0 }, currentPos{ nullptr }, head{ nullptr } {}
	ReelNode<T>* getReelNode();		//returns a pointer to the currentPos in the list
	void putItem(T item);
	T getItem(T item);

	template <typename K>			//returns Item in the list using the key provided by the user
	T getItem(K key);
	
	//the following methods have not been used in this program, and was not asked for in the program requirements
	int getLength();
	void resetList();
	T getNextItem();
	void deleteItem(T item);
	void makeEmpty();
	~Reel() { makeEmpty(); }

};

template <typename T>
ReelNode<T>* Reel<T>::getReelNode()
{
	if (currentPos == nullptr)		//if the currentPos is a null pointer, then set currentPos to the head of the list
	{
		currentPos = head;
	}

	return currentPos;
}

template <typename T>
void Reel<T>::putItem(T item)
{
	ReelNode<T>* temp = new ReelNode<T>;
	if (head == nullptr)
	{
		temp->data = item;
		temp->next = temp;
		head = temp;
	}
	else
	{
		currentPos = head;
		while (currentPos->next != head)
		{
			currentPos = currentPos->next;
		}
		currentPos->next = temp;
		temp->data = item;
		temp->next = head;
	}
	length++;
}

template <typename T>
T Reel<T>::getItem(T item)
{
	ReelNode<T>* temp = head;

	while (temp->next != head)
	{
		if (temp->data == item)
		{
			return temp->data;
		}
		temp = temp->next;
	}

	if (temp->data == item)
		return temp->data;

	throw "not found";
}

template <typename T>
template <typename K>
T Reel<T>::getItem(K key)
{
	return getItem(Item<K>(key));
}

template <typename T>
int Reel<T>::getLength()
{
	return length;
}

template <typename T>
void Reel<T>::resetList()
{
	currentPos = head;
}

template <typename T>
T Reel<T>::getNextItem()
{
	if (currentPos == nullptr)
		throw "Empty List";

	T item = currentPos->data;
	currentPos = currentPos->next;
	return item;
}


template <typename T>
void Reel<T>::deleteItem(T item)
{
	currentPos = head;
	while (currentPos->next != head)
	{
		currentPos = currentPos->next;
	}

	//Empty Case
	if (head == nullptr)
		return;

	//Deleting Head
	ReelNode* temp = nullptr;
	if (head->data == item)
	{
		temp = head->next;
		currentPos->next = temp;
		delete head;
		head = temp;
		length--;
		return;
	}

	//Deleting further in the list
	temp = head;
	while (temp->next != currentPos)
	{
		if (temp->next->data == item)
		{
			ReelNode<T>* temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			length--;
			return;
		}
		temp = temp->next;
	}

	//Deleting the last element in the list from where it loops to head
	if (currentPos->data == item)
	{
		temp->next = head;
		delete currentPos;
		length--;
		return;
	}

	throw "not found";
}

template <typename T>
void Reel<T>::makeEmpty()
{
	ReelNode<T>* temp = nullptr;

	currentPos = head;
	while (currentPos->next != head)
	{
		currentPos = currentPos->next;
	}
	currentPos->next = nullptr;

	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	length = 0;
}

template <typename T>
ostream& operator<<(ostream& os, Reel<T>& o)
{
	o.resetList();
	os << "Reel: [";
	for (int i = 0; i < o.getLength(); i++)
	{
		os << o.getNextItem();
		if (i < o.getLength() - 1) os << ", ";
	}
	os << "]" << endl;

	return os;
}







