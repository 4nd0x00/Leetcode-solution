#include <bits/stdc++.h>

struct TrieNode {
    TrieNode* children[27] = {};
    int idx {-1};
};


/**
 * WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */


class WordFilter {
public:
    TrieNode* root;
    WordFilter(vector<string>& words) {
        root = new TrieNode;
        for(int i {0}; i < words.size(); i++) {
            words[i] += '{';
            string& new_w = words[i];
            for(int j {0}; j < new_w.size(); j++) {
                TrieNode *it = root;
                it->idx = i;
                for(int k = j; k < 2*new_w.size() - 1; k++) {
                    int idx = new_w[k % new_w.size()] - 97;
                    if(!it->children[idx]) it->children[idx] = new TrieNode;
                    it = it->children[idx];
                    it->idx = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        TrieNode* it = root;
        string&& to_search = suff + '{' + pref;
        for(char& c: to_search) {
            it = it->children[c - 97];
            if(!it) return -1;
        }
        return it->idx;
    }
};

