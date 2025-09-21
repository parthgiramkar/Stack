#include<iostream>
#include<vector>
using namespace std;


class what {
public:
    int trap(vector<int>& height) {

        int n = height.size() , ans=0 ;
        int left[n] ;           //storing leftgreater_side
        int right[n];          //storing rightgreater_side

            left[0] = 0;
            right[n-1] = 0;

        for(int i=1;i<height.size();i++) {

            if(left[i-1] > height[i-1]) {         //min(left[i-1] > height[i-1] ) -> left[i]
                left[i] = left[i-1];
            }
            else {
                left[i] = height[i-1];
            }

        }

        for(int i=height.size()-2;i>=0;i--) {
            if(right[i+1] > height[i+1]) {         //min(right[i-1] > height[i-1] ) ->right[i]
                right[i] = right[i+1];
            }
            else {
                right[i] = height[i+1];
            }
        }

        for(int i=0;i<n;i++)  {
            cout<<left[i];
        }
        for(int i=0;i<n;i++)  {
            cout<<right[i];
        }
        cout<<endl;

// the main logic of trapped water
    
        for(int i=0;i<height.size();i++) {

            if(left[i] > height[i] && right[i] > height[i]) {

                ans =ans + min(left[i] , right[i]) -  height[i];
            }       

        }
        return ans;

    }

};



int main() {

    int n;
    cout<<"Enter Size of vector - " ;
    cin>>n;

    vector<int> height(n) ;
    cout<<"Enter the elements - ";
    for(int i=0;i<n;i++) {
        cin>>height[i] ;
    }

    what y ;
    cout<<"Total Rainwater Trapped - "<<y.trap(height)<<"unit^2-_-" ;

}    


