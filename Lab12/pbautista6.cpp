#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int V;
int E;

struct Edge{
	int source, destination, weight;
	// Edge(int source, int destination, int weight){
	// 	this->source = source;
	// 	this->destination = destination;
	// 	this->weight = weight;
	// }
};

struct Graph{
	int V, E;
	Edge* edge;

	Graph(int V, int E){
		this->V = V;
		this->E = E;
		this->edge = new Edge[E];
	}
};

bool BellmanFordAlgo(Graph* graph, int source){
	int distance[V];
	for(int i = 0; i < V; i++){
		distance[i] = INT_MAX;
	}
	distance[source] = 0;

	for(int i = 1; i < V; i++){
		for(int j = 0; j < E; j++){
			int v = graph->edge[j].source;
			int w = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
			if(distance[v] != INT_MAX && distance[v] + weight < distance[w]){
				distance[w] = distance[v] + weight;
			}
		}
	}

	for(int i = 0; i < E; i++){
		int v = graph->edge[i].source;
		int w = graph->edge[i].destination;
		int weight = graph->edge[i].weight;
		if(distance[v] != INT_MAX && distance[v] + weight < distance[w]){
			cout<<"detected"<<endl;
			return false;
		}
	}

	return true;

}


int main(int argc, char const *argv[])
{
	cin>>V;
	cin>>E;

	Graph* graph = new Graph(V,E);
	int source;
	int destination;
	int weight;
	cout<<V<<" "<<E<<endl;
	for(int i = 0; i < E; i++){
		cin>>source;
		cin>>destination;
		cin>>weight;
		graph->edge[source].source = source;
		graph->edge[source].destination = destination;
		graph->edge[source].weight = weight;
		cout<<graph->edge[source].source<<","<<graph->edge[source].destination<<","<<graph->edge[source].weight<<endl;
	}

	cout<<BellmanFordAlgo(graph, 0)<<endl;



	return 0;
}