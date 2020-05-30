/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
*/

// Solution using custom class and sorting :

class tt{
    public:
        int x,y;
        double d;
    };
    static bool mc(tt a, tt b){
        return a.d <= b.d;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>> ans;
        vector<tt> v;
        for(int i=0;i<p.size();i++){
            tt t;
            t.x= p[i][0];
            t.y= p[i][1];
            t.d= (double)sqrt((double)((double)p[i][0]*(double)p[i][0] + (double)p[i][1]*(double)p[i][1]));
            v.push_back(t);
        }
        sort(v.begin(),v.end(),mc);
        for(int i=0;i<k;i++){
            vector<int> j;
            j.push_back(v[i].x); j.push_back(v[i].y);
            ans.push_back(j);
        }
        return ans;
    }
