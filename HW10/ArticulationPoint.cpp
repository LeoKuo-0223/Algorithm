#include<iostream>
#include<vector>
#include<algorithm>
#define INF 200001
using namespace std;

struct Output{
    int index;
    int importance;
};

class Graph{
 public:
    int *discover;
    int *visited;
    int *low;
    Output *result;
    int numV;
    vector<int> *adj;
    Graph(int V){
        numV=V;
        adj=new vector<int>[V];
        discover = new int[V];
        visited = new int[V];
        low = new int[V];
        result = new Output[V];
    }
    void DFS(int visited[], int start, int &time, int parent);
    void findAP(int numV, int numBomb);
    void addEdge(int v, int w);
};

void Graph::DFS(int visited[], int start, int &time, int parent){
    visited[start]=true;
    int childs=0;
    discover[start] =low[start]= ++time;
     
    for(auto it:adj[start]){
        if(visited[it]==false){
            childs++;
            DFS(visited, it, time, start);
            low[start]=min(low[start], low[it]);

        }else if(it!=parent){
            low[start] = min(low[start], discover[it]);
            continue;
        }

        //if no connect to any ancester  and not root
        if (low[it] >= discover[start] && (parent !=-1|| childs>1)) {
            result[start].importance++;
        }

    }

}




int cmp(const Output a, const Output b){
    if(a.importance==b.importance){
        return a.index<b.index;
    }else{
        return a.importance>b.importance;
    }
}

void Graph::findAP(int numV, int numBomb){
    int time=0;
    for(int i=0;i<numV;i++){
        visited[i]=false;
        discover[i]=0;
        low[i]=INF;
        result[i].index=i;
        result[i].importance=1;
    }

    for(int i=0;i<numV;i++){
        if(visited[i]==false){
            DFS(visited,0,time, -1);
        }
    }

    sort(result, result+numV, cmp);
    int remainBomb=numBomb;
    for (int u = 0; u <remainBomb; u++){
        cout<<result[u].index<<" "<<result[u].importance<<endl;
    }
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
    adj[w].push_back(v);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int numV, numBomb;
    int from, to, dir;
    cin>>numV>>numBomb;
    Graph gh(numV);
    while(true){
        cin>>from>>to;
        if(from==-1 && to==-1) break;
        gh.addEdge(from,to);
    }
    gh.findAP(numV, numBomb);
	

	return 0;
}