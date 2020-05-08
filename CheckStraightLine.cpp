// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// Solution :

bool checkStraightLine(vector<vector<int>>& coordinates) {
    double a = (double(coordinates[1][1]-coordinates[0][1])/double(coordinates[1][0]-coordinates[0][0]) );
    for(int i=2;i<coordinates.size();i++) 
        if(double(double(coordinates[i][1]-coordinates[i-1][1])/double(coordinates[i][0]-coordinates[i-1][0])) != a) return 0;
    return 1;
}
