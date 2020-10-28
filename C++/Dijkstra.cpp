//Program to make Dijkstra algorithm
int minDistance(bool sptSet[], vector<int> dist, int V){
    int min_index;
    int min = INT_MAX;
    for(int v=0;v<V;v++){
        if(!sptSet[v] && dist[v]<=min)
        {
            min=dist[v];min_index=v;
        }
    }
    return min_index;
}
 vector<int> dijkstra(vector<vector<int>> g, int src, int V)
{
    bool sptSet [V] = {false};
    vector<int> dist;
    for(int i=0;i<V;i++)
        dist.push_back(INT_MAX);
    dist[src]=0;
    for(int count = 0;count<V;count++){
        int u = minDistance(sptSet, dist, V);
        sptSet[u]=true;
        for(int v=0;v<V;v++){
            if(!sptSet[v] && g[u][v] && dist[u]!=INT_MAX && dist[u]+g[u][v]<dist[v]){
                dist[v]=dist[u]+g[u][v];
            }
        }
    }
    return dist;
}
