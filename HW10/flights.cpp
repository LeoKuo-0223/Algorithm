// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

class Graph{
	int V; 
	vector<vector<int>> adj;
	void DFS(int v, bool visited[]);

    public:
        Graph(int V){
            this->V = V;
            for(int i=0;i<V+1;i++){
                vector<int> tmp;
                adj.push_back(tmp);
            }
        }
        void addEdge(int v, int w, int dir);
        void isSCCs();
        Graph getTranspose();
};



Graph Graph::getTranspose(){
	Graph gT(V);
	for (int v = 1; v <= V; v++){
		for(auto it = adj[v].begin(); it != adj[v].end(); ++it){
			gT.adj[*it].push_back(v);
		}
	}
	return gT;
}

void Graph::addEdge(int v, int w, int dir){
	adj[v].push_back(w);
    if(dir==2){
        adj[w].push_back(v);
    }
}

void Graph::DFS(int v, bool visited[]){
	visited[v] = true;
	for(auto it = adj[v].begin(); it != adj[v].end(); ++it){
		if(!visited[*it]){
			DFS(*it, visited);
        }
    }
}


void Graph::isSCCs(){
	bool *visited = new bool[V+1];
    for(int i = 1; i < V+1; i++)
        visited[i] = false;


	DFS(1, visited);
    for(int i=1;i<V+1;i++){
        if(visited[i]==false) {
            cout<<0<<endl;
            return;
        }
    }



	Graph gT = getTranspose();
    for(int i = 1; i < V+1; i++)
        visited[i] = false;


	gT.DFS(1, visited);
    for(int i=1;i<V+1;i++){
        if(visited[i]==false) {
            cout<<0<<endl;
            return;
        }
    }
        
	cout<<1<<endl;
}

int main(){
	int numCity, numflights;
    int from, to, dir;
    while(true){
        cin>>numCity>>numflights;
        if(!numCity||!numflights) return 0;
        Graph gh(numCity);
        for(int i=0; i<numflights;i++){
            cin>>from>>to>>dir;
            gh.addEdge(from, to, dir);
        }
        gh.isSCCs();
    }

	

	return 0;
}
