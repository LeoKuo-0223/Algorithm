#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Graph {
    public:
	int V;
	vector<vector<int>> adj;
    vector<int> ansVec;
    vector<int> indegree;
    
	Graph(int V){
        this->V = V;
        adj.resize(V+1);
        indegree.resize(V+1);
        for(int i=0;i<V+1;i++){
            indegree[i]=0;
        }
    }
	void addEdge(int u, int v);
	void topologicalSort();
};


void Graph::addEdge(int u, int v){
	adj[u].push_back(v);//build graph reversely
}



void Graph::topologicalSort(){

    for(int i=1;i<V+1;i++){
        for(auto iter:adj[i]){
            indegree[iter]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1;i<V+1;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(q.empty()==false){
        int vertex=q.top();
        ansVec.push_back(vertex); 
        q.pop();
        for(auto iter :adj[vertex]){
            if(!--indegree[iter]){
                q.push(iter);
            }
        }
    }

    for(int i=0;i<ansVec.size();i++){ //print reversely
        cout<<ansVec[i]<<" ";
    }
    cout<<endl;
}

int main(){
	int n,m,u,v;

    while(cin>>n>>m){
        Graph gh(n);
        for(int i=0;i<m;i++){
            cin>>u>>v;
            gh.addEdge(u,v);
        }
        gh.topologicalSort();
    }
	return 0;
}
