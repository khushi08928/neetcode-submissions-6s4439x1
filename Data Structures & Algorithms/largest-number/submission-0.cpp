class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums2;
        for (int num : nums) {
            nums2.push_back(to_string(num));
        }
        sort(nums2.begin(), nums2.end(), [](string &x, string &y) {
            return x + y > y + x;
        });

        if (nums2[0] == "0") return "0";
        string ans = "";
        for (string &s : nums2) {
            ans += s;
        }

        return ans;
    }
};