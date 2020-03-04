/*
Date: 03-03-2020
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Question: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0/?track=md-arrays&batchId=144
*/


#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    vector<int> v;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        v.push_back(x);
	    }
	   int i=0,a=0,b=0;
	   while(i<n-1){
	       while(i<n-1 && v[i+1]<=v[i])
	       i++;
	       if(i==n-1)
	       break;
	       a=i++;
	       while(i<n && v[i]>=v[i-1])
	       i++;
	       b=i-1;
	       cout<<"("<<a<<" "<<b<<")"<<" ";
	       
	   }
	   if(a==0 && b==0)
	   cout<<"No Profit";
	   cout<<endl;
	}
	return 0;
}