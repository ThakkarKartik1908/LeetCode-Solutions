class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // find solution for all and take which one need
        vector<int> ans2(nums2.size(), 0);
        vector<int> ans1(nums1.size(), 0);
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans2[i] = -1;
            } else {
                ans2[i] = s.top();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans1[i] = ans2[j];
                    break;
                }
            }
        }

        return ans1;
    }
};