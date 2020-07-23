//Program to detect cycle in an undirected graph using parent variable

bool isCyclicUtil(vector<int> g[], int v, bool visited[], int parent, int V){
    visited[v] = true;
    for(auto i=g[v].begin();i!=g[v].end(); i++){
        if(!visited[*i]){
            if(isCyclicUtil(g, *i, visited, v, V))
            return true;
        }else if(*i!=parent){
            return true;
        }
    }
    return false;
    
}
bool isCyclic(vector<int> g[], int V)
{
    bool visited [V] = {false};
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(isCyclicUtil (g, i, visited, -1, V)){
                return true;
            }
        }
    }
    return false;
}
