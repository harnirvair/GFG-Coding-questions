//Question Link: https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0/?track=md-string&batchId=144

#incude <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s1, s2;
	    cin>>s1>>s2;
	    string left = s1;

        left = left + left[0];
        left.erase(0,1);
        left = left + left[0];
        left.erase(0,1);

        string right = s1;
	    right = right[right.length()-1] + right;
	    right.erase(right.length()-1, 1);
	    
	    right = right[right.length()-1] + right;
	    right.erase(right.length()-1, 1);
	    
	    
	    if(s2 == left || s2 == right)
	        cout<<1<<endl;
	    else
	    cout<<0<<endl;
	    
	}
	return 0;
}
