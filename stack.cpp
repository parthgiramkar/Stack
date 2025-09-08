using namespace std;

#include<iostream>
#include<stack>

class C {
public:

    int top;
    int n;          //implementing_through_array
    
    int *ar;

    C (int size) {         //creating the constructor 
        n=size;
        top=-1;
        ar= new int[n];     //memory_on_heap_stored
    }

    void push(int ele) {

        if(n-top > 1) {          //when_topcrossed_the_size_thenoverflow
            top++;
            ar[top] =ele;
            
        }
        else {
            cout<<"stack overflowed"<<endl;        //stack is full_so_can't_bepushed
        }
    }

    void pop() {

        if(top>=0) {
            top-- ;
        }

        else {
            cout<<"stack underflowed "<<endl ;     //stack isempty_can't_pooped
        }

    }

    int peek() {
        if(top>=0) {
            return ar[top] ;
        }
        else {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty() {
        if(top<0) {
            return true ;
        }
        else {
            return false;
        }
    }
 
};

int main() {

/*creation_of_stack(FILO)
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(5);
    cout<<st.top();        // shows topmost element of stack
    
    cout<<st.empty();    // 0-not_empty
    cout<<st.size();          */

    C obj(2);
    obj.push(2);
    obj.push(4);
    obj.push(5);

    obj.pop();
    cout<<obj.peek()<<endl;;

    obj.pop();
    cout<<obj.peek()<<endl;
    
    if(obj.isempty()) {
        cout<<"stack_is empty burhh";
    }

}   


//time-O(1), space-O(n) for storage
//for top=0 , error occurs
