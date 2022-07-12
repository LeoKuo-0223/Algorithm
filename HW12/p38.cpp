#include <iostream>
#include<vector>
#include <limits.h>
#define INF 1001
using namespace std;


class Graph{
    public:
        int V;
        vector<vector<int>> graph;
        vector<int> dist;
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
	int min = INF;
    int min_index;
	for (int v = 0; v < V; v++){
        //not in set and find min value
		if (sptset[v] == false && dist[v] <= min){
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
    int n,input;
    cin>>n;
    Graph gh(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(i==j){
                gh.graph[i][j]=0;
            }else{
                cin>>input;
                gh.graph[i][j]=gh.graph[j][i]=input;
            }
        }
    }
	gh.dijkstra(0);
    int longest=-1;
    for(int i=0;i<n;i++){
        if(gh.dist[i]>longest){
            longest=gh.dist[i];
        }
    }
    cout<<longest;
	return 0;
}

