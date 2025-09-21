#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
        
        int left=0 , right = height.size()-1 ,ans = 0;
        
        while(left!=right) {

            int width = right-left ;
            ans = max( (long long)ans , min(height[left],height[right])*width*1ll) ;     //constraint - 1e4*1e5

            if(height[left] < height[right] ) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }

};

int main()  {

    Solution ok ;
    int n;
    cout<<"Enter the size of vector - ";
    cin>>n;

    vector<int> height(n) ;
    cout<<"\nEnter elements - ";
    
    for(int i=0;i<n;i++) {
        cin>>height[i];
    }

    cout<<"Maximum Area - " <<ok.maxArea(height)<<"unit^2 -_-" ;

}




