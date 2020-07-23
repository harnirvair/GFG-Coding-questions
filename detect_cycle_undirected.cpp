//Program to detect cycle in an undirected graph using parent variable

bool isCyclicUtil(int V, bool recStack[], bool visited[], int v, vector<int> adj[]){
    if(visited[v]==false){
        visited[v]=true;
        recStack[v]=true;
        for(auto i = adj[v].begin(); i!=adj[v].end(); i++){
            if(!visited[*i] && isCyclicUtil(V, recStack, visited, *i, adj))
            return true;
            else if(recStack[*i])
            return true;
        }
    }
    recStack[v]=false;
    return false;
}
bool isCyclic( vector<int> adj[], int V)
{
    bool recStack[V] = {false};
    bool visited[V] = {false};
    for(int i=0;i<V;i++){
        if(isCyclicUtil(V, recStack, visited, i, adj)){
            return true;
        }
    }
    return false;
    // Your code here
}
