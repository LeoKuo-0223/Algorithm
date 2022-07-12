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
                for(int j=0;j<numV;j++){
                    if(i==j) graph[i][j]=0;
                    else graph[i][j]=INF;
                }
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
		int u = minDistance(); //first u is always scr!!
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
    int n,E,u,v,c;
    cin>>n;
    cin>>E; //num of Edge
    Graph gh(n);
    for(int i=0;i<E;i++){
        cin>>u>>v>>c;
        gh.graph[u][v]=c;
        
    }
	gh.dijkstra(0);

    for(int i=0;i<n;i++){
        cout<<i<<" "<<gh.dist[i]<<endl;
    }

	return 0;
}

