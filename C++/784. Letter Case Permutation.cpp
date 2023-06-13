#include <bits/stdc++.h>


vector<string> letterCasePermutation(string s) {
    // Need indices array to keep track of all letter
    vector<int> indices;
    for(int i=0; i < s.size(); i++) {
        // if s_i is digit then skip
        if(s.at(i) >= 48 && s.at(i) <= 57)
            continue;
        indices.push_back(i);
    }

    vector<string> res;
    int n = indices.size();
    int range = (1 << n);

    // Enumerate all subset of indices array
    for(int i=0; i < range; i++) {
        string tmp(s.begin(), s.end());
        for(int j=0; j < n; j++) {
            if(i & (1 << j)) {
                tmp[indices[j]] ^= 32;
            }
        }
        res.push_back(tmp);
    }

    return res;
}
