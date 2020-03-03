/*
Program: https://practice.geeksforgeeks.org/problems/minimum-platforms/0
Date: 03-03-2020
Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> dept,arr;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        arr.push_back(x);
	    }
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        dept.push_back(x);
	    }
	    sort(arr.begin(), arr.end());
	    sort(dept.begin(), dept.end());
	    int i=1, j=0;
	    int plat=1,res=0;
	    while(i<n && j<n){
	        if(arr[i]<=dept[j]){
	            plat++;
	            i++;
	            if(plat>res)
	            res=plat;
	        }else{
	            plat--;
	            j++;
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}