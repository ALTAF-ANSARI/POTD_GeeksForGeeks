class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        unordered_set<int> st;

        for (int right = 0; right < n; right++) {
            if (st.find(arr[right]) != st.end()) {
                return true;
            } else {
                st.insert(arr[right]);

                if (right - left >= k) {
                    st.erase(arr[left]);
                    left++;
                }
            }
        }

        return false;
    }
};
