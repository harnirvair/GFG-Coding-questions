//Question: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1/?track=sp-graph&batchId=152

vector <vector <int> > nearest(vector<vector<int>> &v, int N, int M) {

        vector<vector<int>> ans(N, vector<int> (M));
    queue <pair<int, int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j]==1){
                v[i][j]=0;
                q.push(make_pair(i,j));
            }else{
                v[i][j]=INT_MAX;
            }
        }
    }
    int x[]={0,0,1,-1};
    int y[]={1,-1, 0, 0};
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int newX = x[i]+ele.first;
            int newY = y[i]+ele.second;
            
            if(newX < 0 || newX >= N || newY < 0 || newY >=M  || v[newX][newY] == 0)
                    continue;
            
            if(v[newX][newY]>v[ele.first][ele.second]+1){
                v[newX][newY] = v[ele.first][ele.second]+1;
                q.push(make_pair(newX, newY));
            }
            
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans[i][j]=v[i][j];
        }
    }
    return ans;
}
