//uses chebishev distance formula ie min distance= max(distance bw x coordinates and bw y coordinates of two points)
//going through all 8 direction possibilities wouldnt have been optimum
//the formula covers all the direction -->, <--, up doown and \ ,/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for(int i=1;i<points.size();i++){
            int dx=abs(points[i][0]-points[i-1][0]);
            int dy=abs(points[i][1]-points[i-1][1]);
            time+=max(dx,dy);
        }
        return time;    
        
    }
};

