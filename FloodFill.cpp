/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
*/

// Solution using BFS :

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x= image[sr][sc];
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int a[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
        bool vis[image.size()][image[0].size()];
        for(int i=0;i<image.size();i++) for(int j=0;j<image[0].size();j++) vis[i][j]=0;
        
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            image[p.first][p.second]=newColor;
            vis[p.first][p.second]=1;
            for(int i=0;i<4;i++){
                int r= p.first+a[i][0];
                int c= p.second+a[i][1];
                if(r>=0 && r<image.size() && c>=0 && c<image[0].size() && !vis[r][c] && image[r][c]==x) q.push(make_pair(r,c));
            }
        }
        return image;
    }
