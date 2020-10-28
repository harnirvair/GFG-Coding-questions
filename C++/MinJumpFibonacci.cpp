#include<bits/stdc++.h>
#define maxv 1e5

using namespace std;

int CountMinJumps(int A[], int n){
    int fib[30];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<30;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    int dp [n+2];
    for(int i=0;i<=n+1;i++){
        dp[i]=maxv;
    }
    dp[0]=0;
     for(int i=1;i<n+2;i++){
        for(int j=1;j<30;j++){
            if((A[i-1]==1 || i==n+1) && i-fib[j]>=0){
                dp[i]=min(dp[i], 1+dp[i-fib[j]]);
            }
        }
    }
    if(dp[n+1]!=maxv)
    return dp[n+1];
    else
    return -1;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    cout<<CountMinJumps(A,n);
    
}
