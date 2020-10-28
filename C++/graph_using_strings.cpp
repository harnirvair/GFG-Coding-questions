#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	unordered_map<string, list<pair<string, int>>> Adj;
	vector<vector<string>> A;
	cin>>n;
	while(n--){
	    vector<string> x;
	    string s, str;
	    getline(cin, s);
	    istringstream f(s);
	    while(getline(f,str, ' ')){
	        x.push_back(str);
        }
        A.push_back(x);
	}
// 	for(int i=0;i<A.size();i++){
// 	    for(int j=0;j<A[i].size();j++){
// 	        cout<<A[i][j]<<" ";
// 	    }

// 	}
	for(int i=0;i<A.size();i++)
	{
	    string ele;
	    for(int j=0;j<A[i].size();j++){
	        if(j==0){
	            ele = A[i][j];
	        }
	        if(j>2){
	            Adj[ele].push_back({A[i][j], stoi(A[i][2])});
	            Adj[A[i][j]].push_back({ele, stoi(A[i][2])});
	        }
	    }
	    
	}
	for(auto value : Adj){
	    string vertex = value.first;
	    list< pair<string, int> > adjacentVertices = value.second;
	    cout<<value.first<<"->";
	    for(auto itr: adjacentVertices){
	        cout<<itr.first<<" ("<<itr.second<<") "; 
	    }	        cout<<endl;

	}
	
	return 0;
}

/**
Input: 
5
evergreen 1 2 super my
evergreen 1 3 classic
classic 2 3 my
my 2 5 super
*/
