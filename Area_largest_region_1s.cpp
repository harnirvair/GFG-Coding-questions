Question Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?track=sp-graph&batchId=152 

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends


/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/
int isSafe(int A[][SIZE], int row, int col, bool visited[][SIZE], int ROW, int COL) 
{ 
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (A[row][col] && !visited[row][col]); 
} 
void DFS(int A[][SIZE], int row, int col, bool visited[][SIZE], int &count, int N, int M){
    static int rowN[] = {1,1,1,-1,-1,-1,0,0};
    static int colN[] = {1,-1, 0,1,-1,0,1,-1};
    visited[row][col] = true;
    for(int i=0;i<8;i++){
        int Xr = row+rowN[i];
        int Yr = col+colN[i];
        if(isSafe(A,  Xr, Yr,visited, N, M)){
            count++;
            DFS(A, Xr, Yr,visited, count, N, M);
        }
    }
}
int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    bool visited [N][SIZE];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=0;
        }
    }
    int result=INT_MIN;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j] && !visited[i][j]){
                int c=1;
                DFS(A, i, j, visited, c, N, M);
                result=max(c,result);
            }
        }    
    }
    return result;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends
