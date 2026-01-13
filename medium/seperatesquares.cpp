class Solution {
public:
    bool check(vector<vector<int>>& squares,double mid,double total){
        double botArea=0.00000;
        // this loop will divide the area to bottom or top acc to value of mid
        for(auto square:squares){
            double y=square[1];//we can reuse variable names
            double l=square[2];
            double bot_y=y;
            double top_y=y+l;
            if(mid>=top_y){//full square under mid
                botArea+=l*l;//add its area to bottom
            }else if(mid>bot_y){
                botArea+=l*(mid-y);
            };            
        }
        return (botArea>=total/2.00000);// "="coz we want the min y so run the search until we find that
    }
    double separateSquares(vector<vector<int>>& squares) {
        double high=INT_MAX;
        double low=0.00000;
        double total =0.00000;
        //to find high and low and the areas
        for(auto square:squares){
            //making the integer metrics of the square double(type conversion)
            double x=square[0];
            double y=square[1];
            double l=square[2];
            total+=l*l;
            low=min(low,y);
            //y+l is the max value in the y axis for a particular test case(we need to add side length)
            high=max(high,y+l);
        };
        double result=0.00000;
        //binary search which will shift mid up and down acc to check function
        //1e-5 is the limit because the answer can vary in that interval
        //i.e. any value bw high and low will be accepted if its in this interval 
        while(high-low>1e-5){
            double mid=low+(high-low)/2;
            result=mid;
            if(check(squares,mid,total)){
                high=mid;
            }else{
                low=mid;
            };
        };
        return result;        
    }
};