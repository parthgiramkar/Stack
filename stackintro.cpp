#include<iostream>
using namespace std;
#include<stack>

class Stack {
    int size;
    int top;          
    int *arr;
public:    
    //constructor
    Stack(int size) {
        this->size = size;
        this->top = -1;           //-1 represent empty stack
        arr = new int[size];      //dynam array creation
    }
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout<<"the stack overflowed -_-"<<endl;
        }
    }
    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout<<"the stack underflowed -_-"<<endl;
        }
    }
    int peek() {
        if(top >= 0) {
            
            return arr[top];
        }
        else {
            return -1 ;
        }
    }
    bool isempty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    
};
int main() {
    Stack st(2);
    st.push(10);
    st.push(49);
    st.push(44);
    cout<<"the top element is - "<<st.peek()<<endl; 
    
    st.pop();
    cout <<"the top element is - "<< st.peek() << endl;

    st.pop();
    cout <<"the top element is - "<< st.peek() << endl;

    
    st.pop();

    
    if(st.isempty()) {
        cout << "Stack is Empty " << endl;
    }
    else{
        cout << "Stack is not Empty " << endl;
    }


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
