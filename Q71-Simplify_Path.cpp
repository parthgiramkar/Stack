#include<iostream>
#include<string>
#include<stack>

using namespace std ;

class solution {
public:

    string simplypath(string path) {

        stack<string> stp;
        int n=path.size() ;
        int i=0;               //char-willoverflow for large_i/p

        while(i<n) {

            while(i<n && path[i] == '/') {
                i++;
            }

            string ans="";
            while(i<n && path[i]!='/') {
                ans+=path[i];         //pushing_main_words
                i++;
            }

            if(ans==".."&& !stp.empty())  {
                stp.pop();
            }
            else if(ans!=".."&& ans!="."&& ans!="") {     //for_empty_cases_not_to_(notprint)
                stp.push(ans);       //push_other_valid_seperators
            }
            

            i++;

        }
        string res="";
        while(!stp.empty()) {
            res="/"+stp.top()+res;      //res_on_backtopush_new_elem_front
            stp.pop();
        }

        return res=="" ? "/" : res ;

    }
};



int main() {

    string path = "/.../a/../b/c/../d/./";
    solution p;
    string ans = p.simplypath(path) ;
    cout<<ans;

}
