#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>k>>n;
	    int i=0, num;
	    priority_queue<int, vector<int>, greater<int>> pq; 
	    while(i<n){
	        cin>>num;
	        if(pq.size()<k){
	            pq.push(num);
	            if(pq.size()==k){
	                cout<<pq.top()<<" ";
	            }else
	            cout<<-1<<" ";
	        }else if(pq.size()==k && pq.top()<num){
	            pq.pop();
	            pq.push(num);
	            cout<<pq.top()<<" ";
	        }else if(pq.size()==k && pq.top()>=num){
	            cout<<pq.top()<<" ";
	        }
	        i++;
	    }
	    cout<<endl;
	}
	return 0;
}
