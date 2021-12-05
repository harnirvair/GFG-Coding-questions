#include<iostream>
using namespace std;
int prefix_sum(int a[],int n, int prefixSum[])
{
    prefixSum[0] = a[0];
    for(int i=1;i<n;i++)
    {
        prefixSum[i] = prefixSum[i-1]+a[i];
    }
}

int main()
{
    int a[] ={10,20,30,40,50};
    int n = sizeof(a)/sizeof(a[0]);
    int prefixSum[n]={0};
    prefix_sum(a,n,prefixSum);

    for(int i=0;i<n;i++)
    {
        cout<<prefixSum[i]<<" ";
    }
    cout<<endl;

}