int partitionString(string s) {
    int partition = 0;
    int freq[26] = {0};
    int i = 0;

    while(i < s.size()) {
        int j = i;
        while(j < s.size() && freq[s.at(j)-'a'] == 0) {
            freq[s.at(j)-'a']++;
            j++;
        }

        memset(freq, 0, 26*sizeof(int));
        i = max(i+1, j);
        partition++;
    }

    return partition;
}
