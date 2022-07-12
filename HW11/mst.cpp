#include <iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

class Edge{
	public:
	int cost,u,v;
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

void DisjointSets::Union(int x, int y){ //optimalization with rank
	x = find(x), y = find(y);
	if (rnk[x] > rnk[y]){
		parent[y] = x;
	}else{
		parent[x] = y;
	}

	if (rnk[x] == rnk[y])
		rnk[y]++;
}

int DisjointSets::find(int u){//path compression
	if (u != parent[u])
		parent[u] = find(parent[u]);
	return parent[u]; //if u belong to the set of itself
}

int cmp(const Edge &a, const Edge &b){
	return a.cost<b.cost;
}

int compare(const string &a,const string &b){
    int count=0;
    for(int i=0;i<7;i++){
        if(a[i]!=b[i]){
            count++;
        }
    }
    return count;
}


int main(){
    int num;
    cin>>num;
	Edge e;
	vector<Edge> edgeVec(num*(num-1)/2);
	vector<string> points;
    string st;
    for(int i=0;i<num;i++){
        cin>>st;
       points.push_back(st);
    }
	for (int i = 0, idx = 0; i < num; ++i){
      for (int j = i + 1; j < num; ++j){
		edgeVec[idx].cost=compare(points[i], points[j]);
		edgeVec[idx].u=i; //
		edgeVec[idx].v=j;
		idx++;
	  }
	}
	//kruskal
	sort(edgeVec.begin(), edgeVec.end(),cmp);
	DisjointSets ds(num);
	int cost=0;
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
    cin>>st;
    cout<<"The highest possible quality is 1/"<<cost<<".";
	return 0;
}
