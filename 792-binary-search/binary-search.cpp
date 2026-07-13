class Solution {
public:
    int BinarySearch(vector<int>& a, int tar, int st, int end) {

        if (st <= end) {
            int mid = (st + end) / 2;

            if (tar == a[mid])
                return mid;
            else if (tar >= a[mid]) {
                // search in right part
                return BinarySearch(a, tar, mid + 1, end);
            } else {
                // search in left part
                return BinarySearch(a, tar, st, mid - 1);
            }
        }
        return -1;
    }
    int search(vector<int>& n, int tar) {
        return BinarySearch(n, tar, 0, n.size() - 1);
    }
};