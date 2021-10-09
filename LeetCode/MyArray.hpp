//
//  MyArray.hpp
//  LeetCode
//
//  Created by 何皓源 on 2021/10/10.
//

#ifndef MyArray
#define MyArray

#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::swap;
using std::unordered_map;

// 704
int search(vector<int>& nums, int target) {
  int left = 0;
  int right = int(nums.size());
  int middle;
  int num;
  while (left < right) {
    middle = (left + right) / 2;
    num = nums[middle];
    if (num == target) {
      return middle;
    }
    if (num > target) {
      right = middle;
    }
    else {
      left = middle + 1;
    }
  }
  return -1;
}

// 35
int searchInsert(vector<int>& nums, int target) {
  int left = 0;
  int right = int(nums.size());
  if (target > nums.back()) {
    return right;
  }
  if (target < nums.front()) {
    return 0;
  }
  int middle;
  int num;
  while (left < right) {
    middle = (left + right) / 2;
    num = nums[middle];
    if (num == target) {
      return middle;
    }
    if (num > target) {
      right = middle;
    }
    else {
      left = middle + 1;
    }
  }
  return right;
}

// 34
vector<int> searchRange(vector<int>& nums, int target) {
  int left = 0;
  int right = int(nums.size());
  int middle;
  int num;
  while (left < right) {
    middle = (left + right) / 2;
    num = nums[middle];
    if (num == target) {
      int first = middle;
      int last = middle;
      while (first > left && nums[first - 1] == target) {
        -- first;
      }
      while (last < right - 1 && nums[last + 1] == target) {
        ++ last;
      }
      return {first, last};
    }
    if (num > target) {
      right = middle;
    }
    else {
      left = middle + 1;
    }
  }
  return {-1, -1};
}

// 69
int mySqrt(int x) {
  if (x < 2) {
    return x;
  }
  uint left = 0;
  uint right = x;
  uint middle;
  while (left < right) {
    middle = left + (right - left) / 2;
    if (x / middle < middle) {
      if (x / (middle - 1) < middle - 1) {
        right = middle;
      }
      else {
        return (middle - 1);
      }
    }
    else {
      if (x / (middle + 1) >= middle + 1) {
        left = middle + 1;
      }
      else {
        return middle;
      }
    }
  }
  return left;
}

// 367
bool isPerfectSquare(int num) {
  if (num < 2) {
    return true;
  }
  uint left = 2;
  uint right = num;
  uint middle;
  while (left <= right) {
    middle = left + (right - left) / 2;
    if (num / middle == middle && num % middle == 0) {
      return true;
    }
    else if (num / middle < middle) {
      right = middle - 1;
    }
    else {
      left = middle + 1;
    }
  }
  return false;
}

// 27
int removeElement(vector<int>& nums, int val) {
  // int s = 0;
  // for (int f = 0; f < nums.size(); ++ f) {
  //     if (nums[f] != val) {
  //         nums[s++] = nums[f];
  //     }
  // }
  // return s;
  int h = 0;
  int t = int(nums.size()) - 1;
  while (h <= t) {
    if (nums[h] == val) {
      nums[h] = nums[t--];
    }
    else {
      ++ h;
    }
  }
  return h;
}

// 26
int removeDuplicates(vector<int>& nums) {
  int n = int(nums.size());
  if (n == 0) {
    return 0;
  }
  int s = 1;
  for (int f = 1; f < n; ++ f) {
    if (nums[f] != nums[f-1]) {
      nums[s++] = nums[f];
    }
  }
  return s;
}

// 283
void moveZeroes(vector<int>& nums) {
  int s = 0;
  int n = int(nums.size());
  int f = 0;
  for (; f < n; ++ f) {
    if (nums[f]) {
      // nums[s++] = nums[f];
      swap(nums[f], nums[s++]);
    }
  }
  // for (f = s; f < n; ++ f) {
  //     nums[f] = 0;
  // }
}

// 844
bool backspaceCompare(string s, string t) {
  int ps = int(s.length()) - 1;
  int pt = int(t.length()) - 1;
  int ks = 0;
  int kt = 0;
  while (ps >= 0 || pt >= 0) {
    while (ps >= 0) {
      if (s[ps] == '#') {
        ++ ks;
        -- ps;
      }
      else if (ks > 0) {
        -- ks;
        -- ps;
      }
      else {
        break;
      }
    }
    while (pt >= 0) {
      if (t[pt] == '#') {
        ++ kt;
        -- pt;
      }
      else if (kt > 0) {
        -- kt;
        -- pt;
      }
      else {
        break;
      }
    }
    if (ps >= 0 && pt >= 0) {
      if (s[ps] != t[pt]) {
        return false;
      }
    }
    else if (ps >= 0 || pt >= 0) {
      return false;
    }
    -- ps;
    -- pt;
  }
  return true;
}

// 977
vector<int> sortedSquares(vector<int>& nums) {
  vector<int> result(nums.size(), 0);
  int i = 0;
  int j = int(nums.size()) - 1;
  int k = j;
  while (i <= j) {
    if (nums[i] * nums[i] > nums[j] * nums[j]) {
      result[k--] = nums[i] * nums[i];
      ++ i;
    }
    else {
      result[k--] = nums[j] * nums[j];
      -- j;
    }
  }
  return result;
}

// 209
int minSubArrayLen(int target, vector<int>& nums) {
  int result = 100001;
  int sum = 0;
  int l = 0;
  for (int r = 0; r < nums.size(); ++ r) {
    sum += nums[r];
    while (sum >= target) {
      if (r - l + 1 < result) {
        result = r - l + 1;
      }
      sum -= nums[l++];
    }
  }
  return result < 100001 ? result : 0;
}

// 904
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> bucket;
    int result = 0;
    int l = 0;
    for (int r = 0; r < fruits.size(); ++ r) {
        ++ bucket[fruits[r]];
        while (bucket.size() > 2) {
            -- bucket[fruits[l]];
            if (bucket[fruits[l]] == 0) {
                bucket.erase(fruits[l]);
            }
            ++ l;
        }
        if (r - l + 1 > result) {
            result = r - l + 1;
        }
    }
    return result;
}

// 76
bool isContained(unordered_map<char, int>& s, unordered_map<char, int>& t) {
  for (const auto & k : t) {
    if (s[k.first] < k.second) {
      return false;
    }
  }
  return true;
}

string minWindow(string s, string t) {
  unordered_map<char, int> t_map;
  unordered_map<char, int> s_map;
  int l = 0;
  int r = 0;
  int len = 100001;
  int pos = 0;
  for (int i = 0; i < t.length(); ++ i) {
    ++ t_map[t[i]];
  }
  for (; r < s.length(); ++ r) {
    if (t_map.find(s[r]) != t_map.end()) {
      ++ s_map[s[r]];
    }
    while (isContained(s_map, t_map) && l <= r) {
      if (r - l + 1 < len) {
        len = r - l + 1;
        pos = l;
      }
      if (t_map.find(s[l]) != t_map.end()) {
        -- s_map[s[l]];
      }
      ++ l;
    }
  }
  return len < 100001 ? string(s, pos, len) : "";
}

// 54
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return {};
  }
  vector<int> result;
  result.reserve(matrix.size() * matrix[0].size());
  int left = 0;
  int right = int(matrix[0].size());
  int top = 0;
  int bottom = int(matrix.size());
  while (left < right && top < bottom) {
    for (int i = left; i < right; ++ i) {
      result.push_back(matrix[top][i]);
    }
    ++ top;
    for (int i = top; i < bottom; ++ i) {
      result.push_back(matrix[i][right-1]);
    }
    -- right;
    if (left < right && top < bottom) { // 长方形最后会剩1行或者1列，不需要左和上
      for (int i = right - 1; i >= left; -- i) {
        result.push_back(matrix[bottom-1][i]);
      }
      -- bottom;
      for (int i = bottom - 1; i >= top; -- i) {
        result.push_back(matrix[i][left]);
      }
      ++ left;
    }
    
  }
  return result;
}

// 59
vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> result(n, vector<int>(n));
  int left = 0;
  int right = n;
  int top = 0;
  int bottom = n;
  int idx = 1;
  while (left < right && top < bottom) {
    for (int i = left; i < right; ++ i) {
      result[top][i] = idx;
      ++ idx;
    }
    ++ top;
    for (int i = top; i < bottom; ++ i) {
      result[i][right-1] = idx;
      ++ idx;
    }
    -- right;
    if (left < right && top < bottom) { // 长方形最后会剩1行或者1列，不需要左和上
      for (int i = right - 1; i >= left; -- i) {
        result[bottom-1][i] = idx;
        ++ idx;
      }
      -- bottom;
      for (int i = bottom - 1; i >= top; -- i) {
        result[i][left] = idx;
        ++ idx;
      }
      ++ left;
    }
  }
  return result;
}

#endif /* MyArray */
