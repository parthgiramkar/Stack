#include <vector>
#include <iostream>
using namespace std;
#include<algorithm>

class lambo {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int , int >> ans ;        //O(n)
        int cnt=0;
        for(int i=0;i<position.size();i++) {

            ans.push_back({position[i] , speed[i]}) ;

        }

        sort(ans.rbegin(),ans.rend()) ;          //O(nlogn)
        
        vector<double> res ;
        for(int i=0;i<position.size();i++) {
//based on time_gonna _take
            double val = (double)( target - ans[i].first) / (double) ans[i].second ;
            res.push_back(val) ;
        
        }

        double fleet = 0 ;
        for(double i=0;i<res.size();i++) {
            if(res[i] > fleet ) {
                cnt++;
                fleet = res[i] ;
            }
           

        }
        return cnt;

    }

};


int main() {


    vector<int> position = {0,2,4} ;
    vector<int> speed = {4,2,1} ; 

    int target = 100 ;

    lambo lo ;
    cout<<"number of car fleets that will arrive at the destination - " << lo.carFleet(target,position,speed) ;

}