#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
  {
    vector<int> ans;

    for (int k1 = 0; k1 <= k; ++k1)
    {
      const int k2 = k - k1;
      if (k1 > nums1.size() || k2 > nums2.size())
        continue;
      ans = max(ans, merge(maxArray(nums1, k1), maxArray(nums2, k2)));
    }

    return ans;
  }

private:
  vector<int> maxArray(const vector<int> &nums, int k)
  {
    vector<int> res;
    int toPop = nums.size() - k;
    for (const int num : nums)
    {
      while (!res.empty() && res.back() < num && toPop-- > 0)
        res.pop_back();
      res.push_back(num);
    }
    return {res.begin(), res.begin() + k};
  }

  vector<int> merge(const vector<int> &nums1, const vector<int> &nums2)
  {
    vector<int> res;
    auto s1 = nums1.cbegin();
    auto s2 = nums2.cbegin();
    while (s1 != nums1.cend() || s2 != nums2.cend())
      if (lexicographical_compare(s1, nums1.cend(), s2, nums2.cend()))
        res.push_back(*s2++);
      else
        res.push_back(*s1++);
    return res;
  }
};

// a função main não é necessária para juízes eletrônicos
// foi colocada aqui apenas para fim de testes manuais via terminal

int main()
{
  int m, n, k;
  cout << "Escreva o tamanho do vetor nums1: ";
  cin >> m;
  vector<int> nums1(m);
  cout << "Escreva os elementos do vetor nums1: ";
  for (int i = 0; i < m; ++i)
    cin >> nums1[i];

  cout << "Escreva o tamanho do vetor nums2: ";
  cin >> n;
  vector<int> nums2(n);
  cout << "Escreva os elementos do vetor nums2: ";
  for (int i = 0; i < n; ++i)
    cin >> nums2[i];

  cout << "Digite o valor de k: ";
  cin >> k;

  Solution sol;
  vector<int> result = sol.maxNumber(nums1, nums2, k);

  cout << "O maximum number é: ";
  for (int num : result)
    cout << num << " ";
  cout << endl;

  return 0;
}
