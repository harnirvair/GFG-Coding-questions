class Solution {
public:
    int longestPalindromeSubseq(string s) 
        {
        int n = s.length();
        int A[n+1][n+1]; //matrix formation
 
        for(int i=0;i<=n;i++) // Matrix initialization
            {for(int j=0;j<=n;j++){
            A[i][j]=0;
            }  
        }
          for(int i=0;i<n;i++)  //Diagonal Entries as 1
            A[i][i]=1;
        
        for(int ii=2;ii<=n;ii++){
            for(int i=0;i<=n-ii;i++){
            int j=i+ii-1;
                if(s[i]==s[j])
                    A[i][j] =A[i+1][j-1]+2;
                else
                    A[i][j] = max(A[i][j-1], A[i+1][j]);
            }
        }
     
             return A[0][n-1];
    
    }
};
