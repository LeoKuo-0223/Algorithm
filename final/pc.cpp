#include <iostream>
#include<vector>
#include <limits.h>
#define INF 1000000000
using namespace std;
// long long INF=1000000000;

class Graph{
    public:
        int V;
        vector<vector<long long>> graph;
        vector<long long> dist;
        vector<bool> sptset;

        Graph(int numV){
            this->V=numV;
            dist.resize(numV);
            sptset.resize(numV);
            graph.resize(numV);
            for(int i=0;i<numV;i++){
                graph[i].resize(numV);
                dist[i]=INF;
                sptset[i]=false;
            }
        }
        int minDistance();
        void dijkstra(int src);

};


int Graph::minDistance(){
	long long min = INF;
    int min_index;
	for (int v = 0; v < V; v++){
        //not in set and find min value
		if (sptset[v] == false && dist[v] < min){
			min = dist[v];
            min_index = v;
        }
    }

	return min_index;
}


void Graph::dijkstra(int src){
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++){
		int u = minDistance();
		sptset[u] = true;
        //update distance
		for (int v = 0; v < V; v++){
            //not in finish set, can reach,not itself, and smaller dist is found
			if (!sptset[v] && graph[u][v]!=0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
            }
        }
	}

}


int main(){
    int n,m;
    int u,v;
    long long c;
    cin>>n>>m;
    Graph gh(n);
    for(int i=0;i<m;i++){
        cin>>u>>v>>c;
        gh.graph[u-1][v-1]=c;
        // gh.graph[v-1][u-1]=c;
    }
	gh.dijkstra(0);
    long long longest=-1;
    for(int i=0;i<n;i++){
        if(gh.dist[i]>longest){
            longest=gh.dist[i];
        }
    }
    cout<<longest;
	return 0;
}

