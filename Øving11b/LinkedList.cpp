#include <memory>
#include <ostream>
#include <string>
#include "LinkedList.h"
using namespace std;

ostream& operator<<(std::ostream& os, const Node& node) {
	os << node.value << endl;
	return os;
}
Node* LinkedList::insert(Node* pos, const string& value) {	if (pos == begin()) {		head = make_unique<Node>(value, move(head));		return begin();	}	Node* traverser = begin();	while (traverser->next.get() != pos) {		traverser = traverser->next.get();	}	traverser->next = make_unique<Node>(value, move(traverser->next));	return traverser->next.get();}
Node* LinkedList::remove(Node* pos) {
	if (pos == begin()) {		head = move(pos->next);		//pos->~Node;		return begin();	}	auto traverser = begin();	while (traverser->getNext() != pos) {
		traverser = traverser->getNext();
	}	traverser->next = move(pos->next);	//pos->~Node;	return traverser->getNext();}
Node* LinkedList::find(const std::string& value) {
	auto traverser = begin();	while (traverser->getValue() != value && traverser != end()) {		traverser = traverser->getNext();	}	return traverser;
}
void LinkedList::remove(const std::string& value) {
	Node* location = find(value);
	if (location != end()) {
		remove(location);
	}
}
ostream& operator<<(ostream & os, const LinkedList& list) {
	auto traverser = list.begin();
	os << "[";
	while (traverser != list.end()) {
		os << *traverser << " ";
		traverser = traverser->getNext();
	}
	os << "]" << endl;
	return os;
}
