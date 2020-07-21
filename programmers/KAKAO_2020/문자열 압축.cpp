#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 999999999;
    if(s.size()==1) return 1;
    for (int i = 1; i <= static_cast<int>(s.size()) / 2; i++) {
        int idx = 0;
        int length = 0;

        while (idx + i <= s.size()) {
            string key = s.substr(idx, i);
            idx += i;
            int lenTmp = 1;
            while (s.substr(idx, i) == key) {
                lenTmp++;
                idx += i;
            }

            if (lenTmp == 1) {
                length += key.size();
            } else if (lenTmp > 1) {
                length += key.size();
                length += to_string(lenTmp).size();
            }
        }
        if (idx + i > s.size()) length += s.substr(idx, i).size();

        answer = min(length, answer);
    }

    return answer;
}
