/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/

// Solution :
// Cycle detection in a directed graph using DFS :

void dfs(vector<int> adj[], bool vis[], int c, bool &flag, int par[], int o){
    if(!flag) return;
    vis[c]=1;
    par[c]=o;
    for(int i=0;i<adj[c].size();i++){
        if(!vis[adj[c][i]]) dfs(adj,vis,adj[c][i], flag, par, o);
        else if(par[adj[c][i]]==o && c!=o){
            flag=0;
            return;
        }
    }
    par[c]=-1;
}
    
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    for(int i=0;i<prerequisites.size();i++) (adj[prerequisites[i][0]]).push_back(prerequisites[i][1]);
    bool vis[numCourses];
    int par[numCourses];
    memset(vis,0,sizeof(vis));
    bool flag=1;
    for(int i=0;i<numCourses;i++){
        if(!vis[i]) dfs(adj,vis,i, flag, par, i);
    }
    return flag;
}
