#include <bits/stdc++.h> 
using namespace std;

void solverecur(stack<int>&inputStack, int cnt , int N) {

//base_case
   if(cnt==N/2) {
      inputStack.pop();
      return;
   }

   int x=inputStack.top();
   inputStack.pop();
   
//recurrence reln
   solverecur(inputStack , cnt+1 ,N);

   inputStack.push(x);

}

void deleteMiddle(stack<int>&inputStack, int N) {
	
   // Write your code here
      int cnt=0;

      solverecur(inputStack , cnt ,N);
      while(!inputStack.empty() ) {
            cout<<inputStack.top()<<" ";
            inputStack.pop();
      }
}

int main() {

    stack<int> inputStack ;
    inputStack.push(5);
    inputStack.push(6);
    inputStack.push(7);
    inputStack.push(8);

    int N = inputStack.size();

    deleteMiddle( inputStack , N);

}


//for even :- deleting_the_lower_middle_element