class Solution {
public:
    void getallsubsets(vector<int>& n, vector<int>& ans, int i,
                       vector<vector<int>>& allsubsets) {
        if (i == n.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(n[i]);
        getallsubsets(n, ans, i + 1, allsubsets);

        ans.pop_back();

        // duplicate
        int idx = i + 1;
        while (idx < n.size() && n[idx] == n[idx - 1]) idx++;

        // exlude
        getallsubsets(n, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& n) {
        sort(n.begin(), n.end());

        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(n, ans, 0, allsubsets);

        return allsubsets;
    }
};