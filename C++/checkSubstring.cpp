#include <bits/stdc++.h> 
using namespace std; 
  
int checkSubstring(string s1, string s2)
    {int N=s1.length();
    int M=s2.length();int c=0;
    for(int i=0;i<N;i++)
        {int j;
        for( j=0;j<M;j++)
            {
            if(s1[i+j]!=s2[j])
                {break;
                }   
            }
             if(j==M)
            c++;
        }
    return c;
    }
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        getline(cin, s);
        v.push_back(s);
    }
    int goodc=0, averagec=0, bestc=0;
    for(int i=0;i<n;i++){
        if(checkSubstring(v[i],"good")>0){
            goodc++;
        }
        if(checkSubstring(v[i],"average")>0){
            averagec++;
        }
        if(checkSubstring(v[i],"best")>0){
            bestc++;
        }
    }
    int max_ele=max(goodc, max(averagec, bestc));
    cout<<bestc;
    if(max_ele ==goodc)
    cout<<"good"<<endl;
    else if(max_ele==averagec)
        cout<<"average"<<endl;
    else if(max_ele==bestc)
         cout<<"best"<<endl;
    else
        cout<<"good"<<endl;
}
