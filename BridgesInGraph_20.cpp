#include<bits/stdc++.h>
using namespace std;

vector<int> arr[100];
int disc[100], low[100], vis[100];
int timer=0;
void dfs(int node, int par){
	vis[node]=1;
	disc[node]=low[node]=timer;
	timer++;
	for(int child : arr[node]){
		if(child == par)
		continue;
		if(vis[child]==1){
			low[node]=min(low[node], disc[child]);
		}else {
			dfs(child, node);
			if(low[child]>disc[node]){
				cout<<node<<" "<<child<<endl;
			}
			low[node]=min(low[node], low[child]);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y, arr[x].push_back(y), arr[y].push_back(x);
	}
	dfs(1, -1);
	return 0;
}
