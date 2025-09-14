#include<iostream>
#include<stack>

using namespace std;

void sort(stack<int> &s , int f)  {

//base case
    if( (s.empty()) || (!s.empty() && s.top() < f ) ) {
        s.push(f);
        return ;
    }
    
    int y=s.top() ;
    s.pop();
    sort(s , f);

    s.push(y) ;
}

void emptystack(stack<int> &s) {

//base case
    if(s.empty()) {
        return;
    }

    int f=s.top();
    s.pop();

    emptystack(s);

    sort(s, f ) ;
    
}
 
void print(stack<int> s) {

    while(!s.empty() ) {
        cout<<s.top()<<" ";
        s.pop();
    }
}


int main() {

    stack<int> s ;
    s.push(25);             //bottom

    s.push(45);
    s.push(04);
    s.push(50);
    s.push(18);

    cout<<"given stack - ";
    print(s);

    emptystack(s);
    cout<<"Sorted Stack - ";
    print(s);

}



//time - O(n^2) and space - O(n)recursion stack