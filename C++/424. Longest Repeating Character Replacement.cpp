#include <bits/stdc++.h>

int characterReplacement(string s, int k) {
    bitset<27> m;
    for(char& c: s) m.set(c-'A');

    int res {0};
    for(char i {'A'}; i <= 'Z'; i++) {
        if(m.test(i-'A')) {
            int x {0}, start {0};
            for(int end {0}; end < s.size(); end++) {
                x += s[end] != i ? 1 : 0;
                while(x > k && start < end) x -= s[start++] != i ? 1 : 0;
                res = max(res, end-start+1);
            }
        }
    }

    return res;
}