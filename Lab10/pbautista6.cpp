#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// bool dfs(int target, int current, vector<bool> reached){
// 	printf("Target:%d == Current:%d\n", target, current);
// 	for(int i = 0; i < V; i++){
// 		cout<<reached[i]<<" ";
// 	}
// 	cout<<endl;

// 	if(current == target){
// 		return true;
// 	}
// 	reached[current] = true;
// 	for(int i = 0; i < graph[current].size();i++){
// 		if(!reached[i]){
// 			if(dfs(target, i, reached)){
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// bool path(int target, int i){
// 	vector<bool> reached(V, false);
// 	return dfs(target, i, reached);
// }

// vector<vector<int>> sccPaths(){

// 	vector<vector<int>> paths;
// 	vector<bool> scc(V+1, false);
	
// 	for(int i = 0; i <= V; i++){
// 		if(!scc[i]){
// 			vector<int> sccPath;
// 			sccPath.push_back(i);
// 			for(int j = i + 1; j <= V; j++){
// 				if(!scc[j] && 
// 					path(i, j) && 
// 					path(j, i)){
// 					scc[j] = true;
// 					sccPath.push_back(j);
// 				}
// 			}
// 			paths.push_back(sccPath);
// 		}
// 	}
// 	return paths;
// }

// int V;
// int E;


// vector<vector<int>> graph(V);
// vector<vector<int>> adjacent;

// int id;
// int count;

// vector<int> ids(V, 0);
// vector<int> lowest(V, 0);
// vector<bool> inStack(V, false);
// stack<int> Stack;

// void printInput(){
// 	cout<<V<<endl;
// 	cout<<E<<endl;
// 	for(int i = 0; i < E; i++){
// 		cout<<"{"<<graph[i][0]<<","<< graph[i][1] <<"}"<<endl;
// 	}
// }

// void dfs(int current){
// 	Stack.push(current);
// 	inStack[current] = true;
// 	ids[current] = lowest[current] = id++;

// 	for(int i = 0; i < adjacent[current].size();i++){
// 		if(!ids[i]){
// 			dfs(i);
// 		}
// 		if(inStack[i]){
// 			lowest[current] = min(lowest[current], lowest[i]);
// 		}
// 	}

// 	if(ids[current] == lowest[current]){
// 		while(!Stack.empty()){
// 			int index = Stack.top();
// 			Stack.pop();
// 			inStack[index] = false;
// 			lowest[index] = ids[current];
// 			if(index == current){
// 				break;
// 			}
// 		}
// 		count++;
// 	}
// }

// void findSCC(){
// 	for(int i = 0; i < V; i++){
// 		if(!ids[i]){
// 			dfs(i);
// 		}
// 	}
// }

int V;
int E;
struct Graph{
	int V;
	vector<vector<int>> adjacentList;

    Graph(int V){
		this->V = V;
		adjacentList = vector<vector<int>>(V);
	}


	void addEdge(int u, int v){
		adjacentList[u].push_back(v);
	}

	void sccUtil(int current, vector<int> reached, vector<int> lowest, stack<int> Stack, vector<bool> inStack){
		int count = 0;
		reached[current] = lowest[current] = count++;
		Stack.push(current);
		inStack[current] = true;

		for(int i = 0; i < adjacentList[current].size(); i++){
			int destination = adjacentList[current][i];
	        if(!reached[destination]){
	            sccUtil(destination, reached, lowest, Stack, inStack);
	            lowest[current] = min(lowest[current], lowest[destination]);
        	}else if(inStack[destination]){
        		lowest[current] = min(lowest[current], reached[destination]);
        	}
		}

		int extracted = 0;
	    if (lowest[current] == reached[current]) {
	        while (Stack.top() != current) {
	            extracted = (int)Stack.top();
	            cout << extracted << " ";
	            inStack[extracted] = false;
	            Stack.pop();
	        }
	        extracted = (int)Stack.top();
	        cout << extracted << "\n";
	        inStack[extracted] = false;
	        Stack.pop();
	    }

	}

	void SCCPath(){
		vector<int> reached(V, 0);
		vector<int> lowest(V, 0);
		vector<bool> inStack(V, false);
		stack<int> Stack;

		for (int i = 0; i < V; i++)
	        if(!reached[i])
	            sccUtil(i, reached, lowest, Stack, inStack);
	}
};

int main(int argc, char const *argv[])
{
	cin>>V;
	cin>>E;

	Graph g(V);
	for(int i = 0; i < E; i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u, v);
	}

	g.SCCPath();

	return 0;
}