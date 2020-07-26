//Remove duplicates from a string

#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s){
    int n=s.length();
    int alpha [256] ={0};
    int i=0, j=0;
    string ans="";
    while(n){
        if(alpha[s[i]]==0){
            alpha[s[i]]=1;
            ans.push_back(s[i]);
        }
        i++;
        n--;
    }
    return ans;
}


int main() {
	int t;
	cin>>t;
	string x;
	getline(cin, x);
	while(t--){
	    string s;
	    getline(cin, s);
	    //cout<<s<<endl;
	    string ans =removeDuplicates(s);
	    cout<<ans<<endl;
	}
	return 0;
}
