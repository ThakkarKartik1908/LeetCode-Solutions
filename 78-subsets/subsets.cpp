class Solution {
public:
    void getallsubsets(vector<int>& n, vector<int>& ans, int i,
                       vector<vector<int>>& allsubsets) {
        if (i == n.size()) {
            allsubsets.push_back({ans});
            return;
        }
        // include
        ans.push_back(n[i]);
        getallsubsets(n, ans, i + 1, allsubsets);

        ans.pop_back();

        // exlude
        getallsubsets(n, ans, i + 1, allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(n, ans, 0, allsubsets);
        return allsubsets;
    }
};