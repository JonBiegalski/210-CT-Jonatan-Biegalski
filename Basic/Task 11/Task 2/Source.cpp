#include <iostream>

//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

class Node
{
public:
	int value; //This could really be any type
	Node* next;
	Node* prev;
	Node(int val) {
		std::cout << "Node constructor!" << std::endl;
		this->value = val;
		this->next = (Node*)0;
		this->prev = (Node*)0;
	}
	~Node() {
		std::cout << "Node destructor" << std::endl;
		std::cout << "I had the value " << this->value << std::endl;
	}
};
class List
{

public:
	Node* head;
	Node* tail;

	List() {
		std::cout << "List Constructor!" << std::endl;
		this->head = 0;
		this->tail = 0;
	}
	~List() {
		std::cout << "List destructor!" << std::endl;
		std::cout << "Todo: properly delete nodes..." << std::endl;
	}
	void insert(Node* n, Node* x) {
		//Not actually perfect: how do we prepend to an existing list?
		if (n != 0) {
			x->next = n->next;
			n->next = x;
			x->prev = n;
			if (x->next != 0)
				x->next->prev = x;
		}

		if (this->head == 0) {
			this->head = x;
			this->tail = x;
			x->prev = 0;
			x->next = 0;
		}
		else if (this->tail == n) {
			this->tail = x;
		}
	}
	void display() {
		Node* i = this->head;
		std::cout << "List: ";
		while (i != 0) {
		std::cout << i->value << ",";
			i = i->next;
		}
		std::cout << std::endl;
	}
	void delete_node(Node* x) {
		if (x == this->head)
		{
			this->head = x->next;
			x->next->prev = nullptr;
		}
		else
		{
			if (x == this->tail)
			{
				this->tail = x->prev;
				x->prev->next = nullptr;
			}
			else
			{
				x->prev->next = x->next;
				x->next->prev = x->prev;
			}
		}
		delete x;
	}
};

int main(int argc, char *argv[])
{
	char a;
	List* l = new List();
	l->insert(0, new Node(4));
	l->insert(l->head, new Node(6));
	l->insert(l->head, new Node(8));
	l->display();
	l->delete_node(l->head);
	l->display();
	delete l;
	std::cin >> a;
	return 0;
}