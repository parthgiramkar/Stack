#include<iostream>
#include<vector>

using namespace std ;

class sol {
public :

    string removekdigits(vector<int> &v , int k) {

//base case
        if(v.size()<=k) {
            return "0";
        }

        string ans="";
        for(int i=0;i<v.size();i++) {

            while(ans.size()>0 && ans.back()>(v[i]+'0') && k!=0 ) {

                ans.pop_back();
                k-- ;
            }

            ans.push_back(v[i]+'0') ;
        } 

//still k remains then
        while(k!=0) {
            ans.pop_back();
            k--;
        }

//leading_Zeros
        while(ans.size()>1 && ans[0] == '0' ) {       //in case only '0' left(size=1),then not_be_removed(itsnotleadingzero)
            ans.erase(ans.begin()) ;
        }

        return ans.empty() ?"0" : ans ;

    }

};

int main() {

    vector<int> v = {1,4,3,2,2,1,9} ;
    int k = 3;

    sol obj ;
    string res = obj.removekdigits(v,k) ;

    cout<<"after removing k digits - "<<res ;

}