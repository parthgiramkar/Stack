#include<iostream>
using namespace std;
#include <stack>

class solve {
public:

    int findMinimumCost(string str) {

        stack<char>st;

        if(str.size()%2 != 0) {         //ifsize odd then expression can't be balanced_only
            return -1;
        }

        for(int i=0;i<str.size();i++) {

            if(str[i] == '}') {
                     // pair has been spotted donot add it
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                }
                else {
                    st.push(str[i]);
                }
            
            }
            else {
                st.push(str[i]);
            }

        }
        // the char's left instack can be balanced performing this operation

        int a=0,b=0;     // for { and }
        while(!st.empty()) {
            if(st.top() == '}') {
                a++;
            }
            else {
                b++;
            }
            st.pop();

        }
        return (a+1)/2 + (b+1)/2 ;
    } 
      
    
};

int main() {

    string str = "{{{{";

    solve sot;
    
    int ans = sot.findMinimumCost(str);
    cout<<"Minimum cost to make str valid is - "<<ans ;
   
}


