class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) { // estrutura obrigatoria da classe no leetcode
    vector<int> ans;

    for (int k1 = 0; k1 <= k; ++k1) {
      const int k2 = k - k1;
      if (k1 > nums1.size() || k2 > nums2.size())
        continue;
      ans = max(ans, merge(maxArray(nums1, k1), maxArray(nums2, k2)));
    }

    return ans;
  }

 private:
  vector<int> maxArray(const vector<int>& nums, int k) {
    vector<int> res;
    int toPop = nums.size() - k;
    for (const int num : nums) {
      while (!res.empty() && res.back() < num && toPop-- > 0)
        res.pop_back();
      res.push_back(num);
    }
    return {res.begin(), res.begin() + k};
  }

  // falta uma função para fazer o merge dos vetores.
  
};