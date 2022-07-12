#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Edge{
	public:
	int u,v;
	unsigned long long cost;
};
class DisjointSets{
	public: 
		int *parent, *rnk;
		int n;
		DisjointSets(int n){
			this->n = n;
			parent = new int[n+1];
			rnk = new int[n+1];
			for (int i = 0; i <= n; i++){
				rnk[i] = 0;
				parent[i] = i;
			}
		}

		int find(int u);
		void Union(int x, int y);
};

void DisjointSets::Union(int x, int y){
	x = find(x), y = find(y);
	if (rnk[x] > rnk[y]){
		parent[y] = x;
	}else{
		parent[x] = y;
	}

	if (rnk[x] == rnk[y])
		rnk[y]++;
}

int DisjointSets::find(int u){
	if (u != parent[u])
		parent[u] = find(parent[u]);
	return parent[u];
}

int cmp(const Edge &a, const Edge &b){
	return a.cost>b.cost;
}



int main(){
    int numV,numE;
    cin>>numV>>numE;
    int u,v;
	unsigned long long c;
	Edge e;
	vector<Edge> edgeVec(numE);
    for(int i=0;i<numE;i++){
        cin>>e.u>>e.v>>e.cost;
        edgeVec[i]=e;
    }

	sort(edgeVec.begin(), edgeVec.end(),cmp);
	DisjointSets ds(numV);
	unsigned long long cost=0;
	for (auto it=edgeVec.begin(); it!=edgeVec.end(); it++){
		int u = (*it).u;
		int v = (*it).v;
		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u != set_v){
			cost += (*it).cost;
			ds.Union(set_u, set_v);
		}
	}
    cout<<cost;
	return 0;
}
