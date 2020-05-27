/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.
*/

// Solution using DFS :
// Coloring alterate nodes withh 0/1

void cyc(vector<int> v[], bool vis[], int curr, bool &flag, int par, int col[], int c){
        // if(!flag) return;
        // cout<<curr<<",";
        col[curr]=c;
        vis[curr]=1;
        for(int i=0;i<v[curr].size();i++){
            if(!vis[v[curr][i]]){
                cyc(v,vis,v[curr][i],flag,curr, col ,1-c);
            }
            else if(col[v[curr][i]]==c){
                flag=0;
            }
        }
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> v[N+1];
        for(int i=0;i<dislikes.size();i++){
            v[dislikes[i][0]].push_back(dislikes[i][1]);
            v[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        bool vis[N+1];
        memset(vis,0,sizeof(vis));
        int col[N+1];
        memset(col,-1,sizeof(vis));
        
        bool flag=1;
        for(int i=1;i<=N;i++){
            if(!vis[i]) cyc(v,vis,i,flag,-1,col, 0);
        }
        return flag;
    }
