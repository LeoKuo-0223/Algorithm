#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

class Graph{
	int V; 
	vector<vector<int>> adj;
	void DFS(int v);

    public:
        vector<bool> visited;
        Graph(int V){
            this->V = V;
            visited.resize(V+1);
            for(int i=0;i<V+1;i++){
                vector<int> tmp;
                adj.push_back(tmp);
                visited[i]=false;
            }
        }
        void addEdge(int v, int w);
        void DFSutil(int school);
};





void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFS(int v){
	visited[v] = true;
	for(auto it = adj[v].begin(); it != adj[v].end(); ++it){
		if(!visited[*it]){
			DFS(*it);
        }
    }
}


void Graph::DFSutil(int school){
	DFS(school);
}

int main(){
	int numCity, numR, numbarrier;
    int school, home;
    int z;
    int from, to;

    cin>>numCity>>numR>>numbarrier;
    cin>>school>>home;
    Graph gh(numCity);
    for(int i=0; i<numR;i++){
        cin>>from>>to;
        gh.addEdge(from, to);
    }
    for(int i=0;i<numbarrier;i++){
        cin>>z;
        gh.visited[z]=true;
    }
    gh.DFSutil(school);
    if(gh.visited[home]==true){
        cout<<"SAFE";
    }else{
        cout<<"UNSAFE";
    }
	

	return 0;
}
