#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int pcur = 0;
        int slength = s.length();
        int plength = p.length();
        int i=0;
        for (i;i<slength;i++){
            if (pcur == plength -1) return false;
            if (s[i]!=p[pcur]&&p[pcur]!='.'){
                if (pcur<plength-1&&p[pcur+1]!='*'&&p[pcur+1]!='.') return false;
                else if (pcur==plength-1) return false;
                else if (p[pcur+1]=='*') pcur+=2;
                else pcur+=1;
            }
            else{
                if (pcur<plength-1){
                    if (p[pcur+1] != '*'){
                        pcur+=1;
                    }
                }
            }
        }
        if(i!=slength-1&&pcur==plength-1) return false;
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("ab","a*");
}