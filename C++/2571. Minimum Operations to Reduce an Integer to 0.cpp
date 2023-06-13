#include <bits/stdc++.h>

// BFS solution 

int minOperations(int n) {
    queue<int> q {{n}};
    bool finished = false;
    int op = -1;

    while(!q.empty() && !finished) {
        int k = q.size();
        while(k--) {
            int curr = q.front();
            q.pop();
            if(curr == 0) { finished = true; break; }
            else if(curr & 1) { 
                q.push(curr-1);
                q.push(curr+1); 
            }
            
            else {
                // m is the largest power of 2 that divides curr
                int m = curr&-curr;
                q.push(curr-m);
                q.push(curr+m);
            }
        }

        op++;
    }

    return op;
}
