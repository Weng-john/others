#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int left=0, add=0;
        for(int ind=0;ind<s.size();ind++){
            if(s[ind]=='('){
                left++;
                continue;
            }
            if((ind+1)<s.size() && s[ind+1]==')'){
                if(left>0)
                    left--;
                else
                    add++;
                ind++;
                continue;
            }
            if(left>0){
                add++;
                left--;
            }
            else
                add += 2;
        }
        add += (left*2);
        return add;
    }
};