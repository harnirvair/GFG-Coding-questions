#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int binarySearch(int arr[], int l, int h, int x){
    int mid;
    while(l<=h){
        mid=l+(h-1)/2;
        cout<<"Mid: "<<mid<<endl;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]<x)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
int main(){
int A[1000];
clock_t start_t,end_t,total_t;
start_t=clock();
srand(time(0));
for(int i=0;i<1000;i++){
    A[i]=rand()%1000+1;
}
int n = sizeof(A)/sizeof(A[0]);
sort(A,A+n);
for(int j=0;j<n;j++)
{
    cout<<A[j]<<" ";
}
cout<<endl;
//cout<<n<<endl;
int ele;

cout<<"Enter Element to search : ";
cin>>ele;
int index = binarySearch(A,0,n-1,ele);
end_t=clock();
total_t=(double)(end_t-start_t)/(CLOCKS_PER_SEC/1000);
cout<<"Time taken : "<<total_t<<"ms"<<endl;
if(index==-1){
    cout<<"Element not found"<<endl;
    }
else{
    cout<<"Element found at position: "<<index<<endl;
}
return 0;
}
