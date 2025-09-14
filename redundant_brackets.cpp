// redundant means useless brackets 

#include<iostream>
using namespace std;

#include<stack>

bool redundantbrackets(string &s) {

//using stack
    stack<int> sto;
    for(int i=0;i<s.size();i++) {          //opening brackets_or operators only push
        
        if(s[i] == '(' || s[i] == '+' ||  s[i] == '-' || s[i] == '*' || s[i] == '/' ) {
            sto.push(s[i]) ;
        }

        else {
            if(s[i] == ')') {
                
                bool isreduntant = true;
                while(sto.top() != '(') {
                    int to = sto.top();
//findoperators inside ()    
                    if(to == '+' ||  to == '-' || to == '*' || to == '/' ) {
                        isreduntant = false ;
                    }
                    sto.pop() ;
                    
                   
                } 
                if(isreduntant == true) {
                        return true ;
                }

                sto.pop();
            }
           

        }

    }
    return false;

}


int main() {

    string s;
    
    cout<<"Enter string - " ;
    getline(cin,s);

    if(redundantbrackets(s) == true)  {
        cout<<"The brackets are Reduntant " ;
    }
    else {
        cout<<"The brackets are not Reduntant " ;
    }
    

}