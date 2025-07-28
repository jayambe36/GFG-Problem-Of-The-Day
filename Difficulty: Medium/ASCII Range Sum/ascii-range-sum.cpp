class Solution {
  public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> pos;
        int n = s.size();

        // Step 1: Record first and last occurrences
        for (int i = 0; i < n; ++i) {
            if (pos.find(s[i]) == pos.end()) {
                pos[s[i]] = {i, i};
            } else {
                pos[s[i]].second = i;
            }
        }

        vector<int> result;

        // Step 2: For each character with multiple occurrences, compute ASCII sum
        for (auto& p : pos) {
            int start = p.second.first;
            int end = p.second.second;

            if (end - start > 1) {
                int sum = 0;
                for (int i = start + 1; i < end; ++i) {
                    sum += (int)s[i];
                }
                if (sum > 0) result.push_back(sum);
            }
        }

        return result;
    }
};
