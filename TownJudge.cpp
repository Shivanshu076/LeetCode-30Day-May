/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
*/

//Solution :

int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> v(N);
        for(int i=0;i<trust.size();i++) v[trust[i][0]-1].push_back(trust[i][1]-1);
        int x=-1;
        for(int i=0;i<N;i++) if(!v[i].size()) x=i;
        if(x==-1) return -1;
        for(int i=0;i<N;i++){
            if(i==x) continue;
            if(find(v[i].begin(),v[i].end(),x)==v[i].end()) return -1;
        }
        return x+1;
    }
