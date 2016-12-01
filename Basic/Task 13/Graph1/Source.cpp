/*
PSEUDOCODE:

STRUCTURE Vertex:
INT Value
LIST[Vertex] edges
CONSTRUCTOR(INT val):
Value<-val
edges<-empty

STRUCTURE Graph:
List[Vertices] verts
CONSTRUCTOR:
verts<-empty

//INPUT: VERTEX vertex
PROCEDURE Add_Node(vertex)
verts.append(vert)
END PROCEDURE

//INPUT: Vertex A, Vertex B
PROCEDURE Add_Edge(A, B)
A.edges.append(B)
B.edges.append(A)
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Node {
	public:
	int value;
	list<Node*> adjacency;
	int distance;
	Node* parent;
	bool discovered;
	int weight;
	Node(int v) {
		value = v;
		adjacency;
		parent = NULL;
		distance = INT_MAX;
		discovered = false;
		weight = 0;
		cout << "created node of value "<<v<<"\n";
	}
};


class Graph {
public:
	vector<Node*> nodes;
	Graph() {
		nodes;
		cout << "created graph\n";
	}

	Node* Add_Node(Node* node)
	{
		this->nodes.push_back(node);
		cout << "Node value: " << node->value << endl;
		return node;
	}

	void Add_Edge(Node* A, Node* B)
	{
		if (does_edge_exist(A, B) == false)
		{
			A->adjacency.push_back(B);
			cout << A->value << " adjacent to " << B->value << endl;
			B->adjacency.push_back(A);
			//write_edges(A);
		}
		else
		{
			cout << "Edge already exists!\n";
		}
	}

	void write_edges(Node* A) {
		cout << "Edges of node " << A->value << ":\n";
		for (Node* i : A->adjacency)
		{
			cout << i->value << endl;
		}

	}
	void write_nodes()
	{
		cout << "Nodes:\n";
		for (int i = 0; i < nodes.size(); i++)
		{
			//cout << nodes[i].value << endl;
		}
	}

	bool does_edge_exist(Node* A, Node* B)
	{
		for (Node* i : A->adjacency)
		{
			if (i->value == B->value)
			{
				return true;
			}
		}
		return false;
	}
};

int main() {
	Graph graph;
	string a;
	//creating nodes
	Node A(0);
	Node B(1);
	Node C(2);
	Node D(3);
	Node E(4);
	Node F(5);
	Node G(6);
	//adding nodes to the graph
	graph.Add_Node(&A);
	graph.Add_Node(&B);
	graph.Add_Node(&C);
	graph.Add_Node(&D);
	graph.Add_Node(&E);
	graph.Add_Node(&F);
	graph.Add_Node(&G);
	//adding edges between nodes
	graph.Add_Edge(&A, &B);
	graph.Add_Edge(&A, &D);
	graph.Add_Edge(&B, &C);
	graph.Add_Edge(&C, &D);
	graph.Add_Edge(&A, &E);
	graph.Add_Edge(&D, &E);
	graph.Add_Edge(&B, &F);
	graph.Add_Edge(&F, &G);
	graph.Add_Edge(&C, &G);
	cin>>a;
	graph.write_nodes();
	graph.write_edges(&A);
	cin >> a;
}