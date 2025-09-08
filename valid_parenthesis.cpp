#include<iostream>
#include<stack>

using namespace std;

class q {

    private:
    stack<char>st;

public:    
    bool valid(string temp) {

        for(int i=0;i<temp.size();i++) {

            if(temp[i] == '}' || temp[i] == ']' || temp[i] == ')' ) {

                if(!st.empty()) {
                    char ch = st.top();
                    if( (ch=='[' && temp[i]!=']') || (ch=='(' && temp[i]!=')') || (ch=='{' && temp[i]!='}') ) {
                        return false;
                    }
                    st.pop();
                }
                else {
                    return false;
                }
            }

            else {
                st.push(temp[i]);
            }
        }

        if(!st.empty()) {
            return false;
        }

        return true;

    }

};

int main() {

    q obj;
    string temp = "{";

    if(obj.valid(temp) == true) {
        cout<<"Valid";
    }
    else {
        cout<<"Invalid";
    }


}