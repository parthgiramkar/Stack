#include<iostream>
#include<vector>

using namespace std;


vector<int> asteriods(vector<int> &v) {

    vector<int> ans ;

    for(int i=0;i<v.size();i++) {

        if( (!ans.empty()) && ( v[i]<0  && ans.back() > 0) ) {        // collison_occured
   

            while(!ans.empty() && ans.back()>0 && abs(v[i]) > abs(ans.back())) {       //first case 

                ans.pop_back();

            }
                        
            if(!ans.empty() && ans.back()>0 && abs(v[i]) == abs(ans.back()) ) {          //2nd case
                    ans.pop_back();
            } 

            else if (ans.empty() || ans.back() < 0 ) {

                ans.push_back(v[i]) ;
            }  

        }
        else {
            ans.push_back(v[i]) ;
        }
    }

    return ans; 
}

int main() {

    vector<int> v = {-2,-2,1,-2} ;

    vector<int> res = asteriods(v) ;
    cout<<"After asterioid collison :- " ;
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" " ;
    }

}

