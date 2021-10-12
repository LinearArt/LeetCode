//
//  MyHashTable.hpp
//  LeetCode
//
//  Created by 何皓源 on 2021/10/10.
//

#ifndef HashTable
#define HashTable

#include "Common.hpp"

// 383
bool canConstruct(string ransom, string magazine) {
  unordered_map<char, int> record;
  for (auto & c : magazine) {
    ++ record[c];
  }
  for (auto & c : ransom) {
    -- record[c];
    if (record[c] < 0) {
      return false;
    }
  }
  return true;
}

// 242
bool isAnagram(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }
  return canConstruct(s, t);
}

// 49
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> group;
  vector<vector<string>> result;
  for (auto & s : strs) {
    string k = s;
    sort(k.begin(), k.end());
    group[k].emplace_back(s);
  }
  for (auto & k : group) {
    result.emplace_back(k.second);
  }
  return result;
}

// 438
vector<int> findAnagrams(string s, string p) {
  vector<int> result;
  if (s.length() >= p.length()) {
    vector<int> record(26, 0);
    vector<int> zero(26, 0);
    for (size_t i = 0; i < p.length(); ++ i) {
      ++ record[p[i] - 'a'];
      -- record[s[i] - 'a'];
    }
    if (record == zero) {
      result.emplace_back(0);
    }
    for (size_t i = p.length(); i < s.length(); ++ i) {
      -- record[s[i] - 'a'];
      ++ record[s[i - p.length()] - 'a'];
      if (record == zero) {
        result.emplace_back(i - p.length() + 1);
      }
    }
  }
  return result;
}

// 349
vector<int> interNum(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> result;
  unordered_set<int> num(nums1.begin(), nums1.end());
  for (int n : nums2) {
    if (num.find(n) != num.end()) {
      result.insert(n);
    }
  }
  return vector<int>(result.begin(), result.end());
}

// 350
vector<int> interArray(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> record;
  vector<int> result;
  for (int n : nums1) {
    ++ record[n];
  }
  for (int n : nums2) {
    if (record.find(n) != record.end()) {
      -- record[n];
      result.emplace_back(n);
    }
    if (record[n] == 0) {
      record.erase(n);
    }
  }
  return result;
}

// 202
bool isHappy(int n) {
  unordered_set<int> record;
  int sum = n;
  auto getNext = [&sum] (int num) -> void {
    sum = 0;
    while (num > 0) {
      sum += (num % 10) * (num % 10);
      num /= 10;
    }
  };
  while (sum != 1) {
    getNext(sum);
    if (record.find(sum) != record.end()) {
      return false;
    } else {
      record.insert(sum);
    }
  }
  return true;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                vector<int>& nums3, vector<int>& nums4) {
  return 0;
}

#endif /* HashTable */
