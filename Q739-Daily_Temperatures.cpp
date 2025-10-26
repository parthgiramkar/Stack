#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

class temp {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    
        stack<pair<int,int>> st;     //for_measuring dist from-next greatest element
        
        vector<int> ans(temperatures.size());

        for(int i=temperatures.size()-1;i>=0;i--) {    //we_need_tosee_from right only

            int cnt=0;

            while(!st.empty()) {

                if(temperatures[i] < st.top().first ) {
                    cnt= abs(i - st.top().second) ;
                    st.push({temperatures[i] , i});
                    ans[i] = cnt;

                    break;
                }
                else {
                    st.pop();
                }
            }

            if(st.empty()) {            //for only empty ones-'0'push
                st.push({temperatures[i] , i});
                ans[i] = cnt ;
            }
        }

        return ans;

    }

};


int main() {

    temp tau ;
    
    vector<int> temperatures = {73,74,75,71,69,72,76,73} ;

    vector<int> result = tau.dailyTemperatures(temperatures) ;

    cout<<"For each_day to wait for next warmer temperature - " ;
    
    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }

    
}