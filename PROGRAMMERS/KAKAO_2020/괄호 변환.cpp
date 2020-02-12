#include <bits/stdc++.h>

using namespace std;

map<char, int> mp;

bool check1(string p) {
    mp.clear();
    for (const auto &c: p) {
        mp[c]++;
    }
    return mp['('] == mp[')'];
}

bool check2(string p) {
    stack<char> st;
    if(p[p.length()-1] == '(') return false;
    for (const auto &c: p) {
        if (c == '(') st.emplace(c);
        if (c == ')') {
            if (st.size()) st.pop();
            else return false;
        }
    }
    return true;
}

string solution(string p) {
    if(p.size()==0) return "";
    string answer="";
   
    for (int i = 1; i <= p.size(); i++) {
        string utemp;
        string u = p.substr(0, i);
        string v = p.substr(i, p.size() - i);
        if (check1(u) && check1(v)) {
            if (check2(u)) {
                answer += u;
                answer += solution(v);
            } else {
                answer += "(";
                answer += solution(v);
                answer += ")";
                utemp = u.substr(1, u.size() - 1);
                for(auto &k : utemp){
                    if(k == '(') k=')';
                    else k='(';
                }
                answer += utemp;
            }
        }
        
        if(answer.size()>=p.size()) return answer.substr(0,p.size());
    }
    return answer;
}
