//Practice Problem GFG: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0/?track=md-heap&batchId=144

#include <bits/stdc++.h>
using namespace std;
int findMedian(int ele, int &m, priority_queue<int> &max_heap, priority_queue<int, vector<int>, greater<int>> &min_heap){
       if(min_heap.size()>max_heap.size()){
           if(ele<m){
               max_heap.push(ele);
           }else{
               max_heap.push(min_heap.top());
              min_heap.pop();
               min_heap.push(ele);
             }
          m=(min_heap.top()+max_heap.top())/2;
       }
else if(min_heap.size()<max_heap.size()){
           if(ele<m){
               min_heap.push(max_heap.top());
               max_heap.pop();
              max_heap.push(ele);
           }else{
              min_heap.push(ele);
          }
     m=(min_heap.top()+max_heap.top())/2;
      }
//min_heap.size()<<"SIZE"<<max_heap.size()<<endl;
     else{
       if(ele<m){
              max_heap.push(ele);
              m=max_heap.top();
       }
            else{
             min_heap.push(ele);
             m=min_heap.top();
            }
        
      }
   
return m;
}
int main() {
	int n;
	cin>>n;
	int A[n],m=0;
	for(int i=0;i<n;i++)
	cin>>A[i];
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0;i<n;i++){
        m=findMedian(A[i],m, max_heap, min_heap);
        cout<<m<<endl;
    }
	return 0;
}
