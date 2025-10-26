#include<iostream>
#include<stack>


using namespace std;

void print(stack<int> stack) {

    while(!stack.empty()) {
        cout<<stack.top()<<" ";
        stack.pop();
    }

}



void insertatbottom(stack<int> &stack,int f) {
//base case
    if(stack.empty()) {
        stack.push(f);
        return;
    }

    int y=stack.top();
    stack.pop();

    insertatbottom(stack,f);

    stack.push(y);

}

void emptystack(stack<int> &stack) {

//base case
    if(stack.empty()) {
        return;
    }

    int f=stack.top();
    stack.pop();

    emptystack(stack);
    
    insertatbottom(stack,f);
}


int main() {

    stack<int> stack ;
    stack.push(1);             //bottom

    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    cout<<"given stack - ";
    print(stack);

    emptystack(stack);
    cout<<"Reversed stack -";
    
    print(stack);


} 


//time - O(n^2) as re-push()and re-pop() of stack happens thatwhy 
//space - O(n) same for all_over_stack