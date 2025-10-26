#include<iostream>
#include<stack>
using namespace std;

#include<vector>

class nextt {
public:  

    vector<int> nextSmallerEle(vector<int> arr) {

    //iterate for every i+1 , so it would be O(n^2)
        
// using the stack - 

        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1) ;
        
        
        for(int i=arr.size()-1;i>=0;i--) {
            
            while(arr[i] <= st.top()) {         //at max can delete n times -O(n )
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(arr[i]);
            
        }
        return ans; 
    }

};        
        
int main() {

    vector<int> arr = {4, 8, 5, 2, 25} ;
    nextt js;
    
    vector<int> result = js.nextSmallerEle(arr) ;
    for(int i=0;i< result.size();i++)  {
        cout<<result[i]<<" ";
    }

}

//space - O(n)  and time -O(2n)


/*
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int>mpp ; 

        vector<int > ans(nums1.size());
        stack<int> st;
        

        for(int i=nums2.size()-1;i>=0;i--) {

            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            if(st.empty()) {
                mpp[nums2[i]] = -1;
                // ans[i] = -1;
                st.push(nums2[i]);
            }

            else {
                mpp[nums2[i]] = st.top();
                // ans[i] = st.top();
                st.push(nums2[i]);

            }
        }

        for(int i=0;i<nums1.size();i++) {
                
            ans[i] = mpp[nums1[i]] ;
            
        }

        return ans;

    }

*/