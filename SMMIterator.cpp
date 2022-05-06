#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	current_node = map.head;
}

void SMMIterator::first(){
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	current_node = map.head;
}

void SMMIterator::next(){
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	current_node = current_node->next_node;
}

bool SMMIterator::valid() const{
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	if (current_node->next_node != nullptr)
		return true;

	return false;
}

TElem SMMIterator::getCurrent() const{
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	return TElem(current_node->node_information.first, current_node->node_information.second);
}


