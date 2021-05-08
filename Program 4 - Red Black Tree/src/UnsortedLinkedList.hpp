#ifndef UnorderedLinkedList_hpp
#define UnorderedLinkedList_hpp

#include <iostream>
#include <string>
#include "UnsortedLinkedListNode.hpp"

template <typename K>
class UnsortedLinkedList 
{
private:
	int length;
	ListNode<K>* currentPos;
	ListNode<K>* head;

public:

	UnsortedLinkedList() : currentPos{ nullptr }, head{ nullptr }, length{ 0 }{}
	~UnsortedLinkedList();
	void MakeEmpty();
	void PutItem(K item);
	K GetItem(K item);
	void DeleteItem(K item);
	void ResetList();
	K GetNextItem();
	int GetLength();
};


template <typename K>
void UnsortedLinkedList<K>::MakeEmpty() 
{
	ListNode<K>* temp = nullptr;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
	length = 0;
}

template <typename K>
void UnsortedLinkedList<K>::PutItem(K item) {
	ListNode<K>* temp = new ListNode<K>;
	temp->data = item;
	temp->next = head;
	head = temp;
	length++;
}

template <typename K>
K UnsortedLinkedList<K>::GetItem(K item) {
	ListNode<K>* temp = head;
	while (temp != nullptr) {
		if (temp->data == item) {
			return temp->data;
		}
		temp = temp->next;
	}
	throw "not found";
}

template <typename K>
void UnsortedLinkedList<K>::DeleteItem(K item) {
	// Empty case 
	if (head == nullptr)
		return;

	ListNode<K>* temp;
	// Deleting head
	if (head->data == item) {
		temp = head->next;
		delete head;
		head = temp;
		length--;
		return;
	}

	// Deleting further in the list
	temp = head;
	while (temp->next != nullptr) {
		if (temp->next->data == item) {
			ListNode<K>* temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			length--;
			return;
		}
		temp = temp->next;
	}
}

template <typename K>
void UnsortedLinkedList<K>::ResetList() {
	currentPos = head;
}

template <typename K>
K UnsortedLinkedList<K>::GetNextItem() {
	if (currentPos == nullptr)
		throw "Out of range";

	K data = currentPos->data;
	currentPos = currentPos->next;
	return data;
}

template<typename K>
int UnsortedLinkedList<K>::GetLength() {
	return length;
}

template <typename K>
UnsortedLinkedList<K>::~UnsortedLinkedList() {
	MakeEmpty();
}
#endif /* UnorderedLinkedList_hpp */
