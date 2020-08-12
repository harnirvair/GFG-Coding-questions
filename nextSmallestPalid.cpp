#include <iostream>
using namespace std;

bool AreAll9s(int A[], int n){
    for(int i=0;i<n;i++)
    if(A[i]!=9)
    return false;
    return true;
}
void generateNextPalindromeUtil(int A[], int n){
int mid=n/2;
int i=mid-1;
bool leftsmaller=false;
int j=(n%2)?mid+1:mid;
while(i>=0 && A[i]==A[j])
{
    i--;j++;
}
if(i<0 || A[i]<A[j])
leftsmaller=true;
    
while(i>=0){
    A[j]=A[i];
    j++,i--;
}

if(leftsmaller){
    int carry=1;
    i=mid-1;
    if(n%2){
        A[mid]+=carry;
        carry=A[mid]/10;
        A[mid]=A[mid]%10;
        j=mid+1;
    }else
    j=mid;
    while(i>=0){
        A[i]+=carry;
        carry=A[i]/10;
        A[i]%=10;
        A[j++]=A[i--];
    }
}
for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
}
}


void generateNextPalindrome(int A[], int n){
    
    if(AreAll9s(A, n)){
        cout<<1<<" ";
        for(int i=1;i<n;i++){
            cout<<0<<" ";
        }
        cout<<1;
   }else{
       generateNextPalindromeUtil(A, n);
   }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        generateNextPalindrome(A,n);
        cout<<endl;
    }
	return 0;
}
