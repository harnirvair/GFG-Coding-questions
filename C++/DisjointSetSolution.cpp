#include <bits/stdc++.h> 
using namespace std; 
class DisjSet { 
public: 
	int *rank, *parent, n; 
	DisjSet(int n) 
	{ 
		rank = new int[n]; 
		parent = new int[n]; 
		this->n = n; 
		makeSet(); 
	} 

	void makeSet() 
	{ 
		for (int i = 0; i < n; i++) { 
			parent[i] = i; 
		} 
	} 

	
	int find(int x) 
	{ 
		if (parent[x] != x) { 

			parent[x] = find(parent[x]); 

		} 

		return parent[x]; 
	} 


	void Union(int x, int y) 
	{ 
		int xset = find(x); 
		int yset = find(y); 
		if (xset == yset) 
			return; 
		if (rank[xset] < rank[yset]) { 
			parent[xset] = yset; 
		} 
		else if (rank[xset] > rank[yset]) { 
			parent[yset] = xset; 
		} 
		else { 
			parent[yset] = xset; 
			rank[xset] = rank[xset] + 1; 
		}
	
	} 
}; 

int main() 
{ 
    int c, n;
    cin>>n>>c;
    DisjSet obj(n);
    for (int i=0;i<c;i++){
        int a,b;
        cin>>a>>b;
        obj.Union(a-1,b-1);
    }
	vector<int> str;
    for(int i=0;i<n;i++){
        int s;
        cin>>s, str.push_back(s);
    } 
    unordered_map <int, vector<int>> um;
    for(int i=0;i<n;i++){
        um[obj.parent[i]].push_back(i);
    }
    vector<int> ans;
    for(auto itr : um){
        int sum = 0;
        cout<<itr.first<<"->";
        int i=0;
        while(i<itr.second.size()){
            sum+=str[itr.second[i]];
            cout<<itr.second[i]<<" ";
            i++;
        }
        cout<<endl;
        ans.push_back(sum);
    }
    // for(auto itr : ans){
    //     cout<<itr<<" ";
    // }
	cout<<*max_element(ans.begin(), ans.end());
	return 0; 
} 
/*
 Sample Input:
9 6
1 2
2 3
7 8
5 6
7 9
4 5
25 34 23 45 16 51 29 38 47

*/
