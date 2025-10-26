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

        int a=0,b=0;
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

    string str = '{{{}';

    solve sot;
    sot.findMinimumCost(str);

    
    cout << "Minimum reversals needed = " << ans << endl;

   
}
