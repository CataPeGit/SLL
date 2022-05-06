#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/

	head = new struct node;
	head->node_information.first = -99999999;
	head->node_information.second = -99999999;
	head->next_node = nullptr;
}

void SortedMultiMap::add(TKey c, TValue v) {
	/*
		best complexity: O(1)
		worst complexity: O(n)
		total complexity: O(n)

		Best case complexity happens when we add the first node in the empty list.
		Worst case complexity happens when we append a node to a non-empty list.
	*/
	SMMIterator iterate = iterator();

	struct node* new_node = new struct node;
	new_node->node_information.first = c;
	new_node->node_information.second = v;

	while (iterate.valid()) {
		iterate.next();
	}
	new_node->next_node = iterate.current_node->next_node;
	iterate.current_node->next_node = new_node;

}

vector<TValue> SortedMultiMap::search(TKey c) const {
	/*
		best complexity: O(1)
		worst complexity: O(n)
		total complexity: O(n)

		Best case complexity happens when we search for the first node in the list.
		Worst case complexity happens when we search for the last node in the list.
	*/
	vector<TValue> result;
	SMMIterator iterate = iterator();
	while (iterate.valid()) {
		if (iterate.current_node->node_information.first == c)
			result.push_back(iterate.current_node->node_information.second);
		iterate.next();
	}

	if (iterate.current_node->node_information.first == c)
		result.push_back(iterate.current_node->node_information.second);
	return result;
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	/*
		best complexity: O(1)
		worst complexity: O(n)
		total complexity: O(n)

		Best case complexity happens when we remove the first node in the list.
		Worst case complexity happens when we remove the last node in the list.
	*/

	SMMIterator iterate = iterator();
	
	struct node* current_node_to_remove = iterate.current_node;
	struct node* previous_node = nullptr;

	while (current_node_to_remove != nullptr && current_node_to_remove->node_information != TElem(c,v)) {
		previous_node = current_node_to_remove;
		current_node_to_remove = current_node_to_remove->next_node;
	}

	if (current_node_to_remove != nullptr) {
		if (previous_node == nullptr) {
			iterate.first();
			iterate.current_node = nullptr;
		}
		else {
			previous_node->next_node = current_node_to_remove->next_node;
		}
		
		delete current_node_to_remove;
		return true;
	}
	else {
		return false;
	}
}


int SortedMultiMap::size() const {
	/*
		best complexity: O(1)
		worst complexity: O(n)
		total complexity: O(n)

		Best case complexity happens when the list is empty.
		Worst case complexity happens when the list is non-empty.
	*/
	SMMIterator iterate = iterator();
	int result = 0;
	while (iterate.valid()) {
		result++;
		iterate.next();
	}
	return result;
}

bool SortedMultiMap::isEmpty() const {
	/*
		best complexity: O(1)
		worst complexity: O(n)
		total complexity: O(n)

		Best case complexity happens when the list is empty.
		Worst case complexity happens when the list is non-empty.
	*/
	if (size() == 0)
		return true;
	return false;
}

SMMIterator SortedMultiMap::iterator() const {
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	/*
		best complexity: O(1)
		worst complexity: O(1)
		total complexity: O(1)
	*/
	delete head;
}
