// Program Name: Rotten Oranges
// Author: Harnirvair
//Source: GFG


#include <bits/stdc++.h>
using namespace std;

struct ele { 
int x,y;
};

bool checkdelim(ele temp){
    if(temp.x==-1 && temp.y==-1)
        return true;
    return false;
}
bool checkall(int A[][100], int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(A[i][j]==1)
            return true;
        }
    }
    return false;
}
bool checkValidPoints(int i,int j, int r, int c){
    if(i>=0 && j>=0 && i<r && j<c)
    return true;
    
  return false;
}
int checkforRottenOranges(int A[][100], int r, int c){
    ele temp;
    queue<ele> q;
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(A[i][j]==2){
                temp.x=i;
                temp.y=j;
                q.push(temp);
            }
        }
    }
    temp.x = -1; 
    temp.y = -1; 
    q.push(temp);
    while(!q.empty()){
        bool flag=false;
        while(!checkdelim(q.front())){
            temp=q.front();
            if(checkValidPoints(temp.x, temp.y+1, r, c) && A[temp.x][temp.y+1]==1){
                if(!flag)
                ans++, flag=true;
                A[temp.x][temp.y+1]=2;
                temp.y++;
                q.push(temp);
                temp.y--;
            }
             if(checkValidPoints(temp.x, temp.y-1, r, c) && A[temp.x][temp.y-1]==1){
                if(!flag)
                ans++, flag=true;
                A[temp.x][temp.y-1]=2;
                temp.y--;
                q.push(temp);
                temp.y++;
            }
             if(checkValidPoints(temp.x+1, temp.y, r, c) && A[temp.x+1][temp.y]==1){
                if(!flag)
                ans++, flag=true;
                A[temp.x+1][temp.y]=2;
                temp.x++;
                q.push(temp);
                temp.x--;
            }
             if(checkValidPoints(temp.x-1, temp.y, r, c) && A[temp.x-1][temp.y]==1){
                if(!flag)
                ans++, flag=true;
                A[temp.x-1][temp.y]=2;
                temp.x--;
                q.push(temp);
                temp.x++;
            }
            q.pop();
        }
        q.pop();
        if(!q.empty()){
            temp.x=-1;
            temp.y=-1;
            q.push(temp);
        }
        
    }
    return (checkall(A,r,c))? -1: ans;
}
int main() {
	int t;
	cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        int A[100][100];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>A[i][j];
            }
        }
       cout<<checkforRottenOranges(A,r,c)<<endl;
    }	
	return 0;
}