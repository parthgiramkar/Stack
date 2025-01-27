#include<iostream>
using namespace std;
#include<stack>

class stack {
    int size;
    int top;
    int *arr;
    
    //constructor
    stack(int size) {
        this->size = size;
        this->top = -1;
        arr = new int[];      //dynam array creation
    }
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout<<"the stack overflowed "<<endl;
        }
    }
    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout<<"the stack underflowed "<<endl;
        }
    }
    int peek() {
        if(top >= 0) {
            
            return arr[top];
        }
        else {
            cout<<"the stack is empty "<<endl;
        }
    }
    bool isempty() {
        if(top == -1) {
            return false;
        }
        else {
            return true;
        }
    }
    
};
int main() {
    stack st(5);
    st.push(10);
    st.push(49);
    st.push(44);
    cout<<"the top element is - "<<st.peek();
    
    /*
    //creation of stack(LIFO)
    stack < int >s;
    //push operations
    s.push(10);
    s.push(3);
    s.push(5);

    s.pop();    //pop operations
    cout<<"printing the top element - "<<s.top()<<endl;
    if(s.empty()) {
        cout<<"the stack is empty "<<endl;
    }
    else {
        cout<<"the stack is not empty "<<endl;
    }
    cout<<"the size of stack is - "<<s.size()<<endl;
    */
    
}
