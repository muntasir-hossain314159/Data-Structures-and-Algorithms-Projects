#pragma once

template <typename T>
struct ReelNode
{
	T data;
	ReelNode<T>* next;
};

