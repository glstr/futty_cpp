#include "leetcode.h"

#include <algorithm>    // std::sort
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int Solution::removeDuplicates(std::vector<int>& nums) {
    int cur_index = 0;
    int cur_num = 0;
    int is_first = true; 
    for (auto num : nums) {
        if (is_first) {
            cur_num = num;
            is_first = false;
            cur_index++;
        } else {
            if (cur_num != num) {
                cur_num = num;
                nums[cur_index] = num;
                cur_index++;
            }
        }
    }

    nums.resize(cur_index);
    return cur_index;
}

void Solution::rotate(std::vector<int>& nums, int k) {
    int size = nums.size(); 
    int real_k = k % size;
    if (real_k == 0) {
        return;
    }

    k = real_k;
    nums.resize(size + k);
    int new_size = size + k;
    for (int i = new_size - 1; i >= k; --i) {
        nums[i] = nums[i - k];
    }

    for (int i = 0; i < k; i++) {
        nums[i] = nums[new_size - k  + i];
    }

    nums.resize(size);
    return;
}

bool Solution::containsDuplicate(std::vector<int>& nums) {
    std::map<int, int> num_times;
    for (auto num : nums) {
        auto it = num_times.find(num);
        if (it != num_times.end()) {
            num_times[num]++;
        } else {
            num_times[num] = 1;
        }
    }

    for (auto it : num_times) {
        if (it.second > 1) {
            return true;
        }
    }
    return false;
}

int Solution::singleNumber(std::vector<int>& nums) {
    int ret = 0;
    for (auto num : nums) {
        ret |= num; 
    }
    return ret;
}

std::vector<int> Solution::plusOne(std::vector<int>& digits) {
    std::vector<int> res;   
    size_t size = digits.size();
    res.reserve(size+1);
    int temp = 1;
    for(int i = digits.size() - 1; i >= 0; --i) {
        int ret = digits[i] + temp;
        temp = ret/10;
        res.push_back(ret % 10);
    }
    if (temp) {
        res.push_back(temp);
    }
    std::vector<int> resp;
    resp.reserve(res.size());
    for(int i = res.size() - 1; i >= 0; --i) {
        resp.push_back(res[i]); 
    }
    return resp;
}

void Solution::moveZeroes(std::vector<int>& nums) {
    int begin = 0;
    int end = 0;
    bool is_first = true;
    for (int i = 0; i < nums.size(); ++i) {
        if (is_first) {
            if (nums[i] == 0) {
                begin = i;
                end = i;
                is_first = false;
            }
        } else {
            if (nums[i] == 0) {
                end = i;
            } else {
                nums[begin] = nums[i];
                nums[i] = 0;
                begin = begin + 1;
                end = i;
            }
        } 
    }
}

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> v(2);
    for (int i = 0; i < nums.size(); ++i ) {
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                v[0] = i;
                v[1] = j;
                return v;
            }
        }
    }
    return v;
}

void Solution::rotate(std::vector< std::vector<int> >& matrix) {
    //b[i][j] = e[j][size - 1 - i]
    int column = matrix.size();
    int target = column / 2;
    for (int i = 0; i < target; ++i) {
        for(int j = i; j < column - 1 - i; ++j) {
            int temp = matrix[j][column - 1 - i];
            matrix[j][column - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;

            temp = matrix[column - 1 - i][column - 1 - j];
            matrix[column - 1 - i][column - 1 - j] = matrix[i][j];
            matrix[i][j] = temp;

            temp = matrix[column - 1 - j][i];
            matrix[column - 1 -j][i] = matrix[i][j]; 
            matrix[i][j] = temp;
        }
    }
}

int Solution::maxProfit(std::vector<int>& prices) {
    int size = prices.size();
    if (size <= 1) {
        return 0;
    }

    int max = 0;
    for (int i = 1; i< size; i++) {
        int profit = prices[i] - prices[i-1]; 
        if (profit > 0) {
            max += profit; 
        }
    }
    return max;
}

int Solution::maxProfitEx(std::vector<int>& prices) {
    int size = prices.size();
    std::vector< std::vector<int> > tmp_prices;
    tmp_prices.reserve(size);
    for (int i = 0; i < size; ++i) {
        std::vector<int> max_prices(size, -1);
        tmp_prices.push_back(max_prices);
    }
    return calMaxProfit(prices, tmp_prices, 0, size - 1);
}

int Solution::calMaxProfit(std::vector<int>& prices, 
        std::vector< std::vector<int> >& tmp_prices,
        int begin, 
        int end) {
    if (end - begin < 1) {
        return 0;
    }

    int temp_max = prices[end] - prices[begin];
    temp_max = std::max(0, prices[end] - prices[begin]);

    for (int i = begin; i < end; ++i) {
        int left_max = tmp_prices[begin][i];
        if (left_max == -1) {
            left_max = calMaxProfit(prices, tmp_prices, begin, i);
        }

        int right_max = tmp_prices[i + 1][end];
        if (right_max == -1) {
            right_max = calMaxProfit(prices, tmp_prices, i + 1, end);
        }

        temp_max = std::max(temp_max, left_max + right_max);
    }

    tmp_prices[begin][end] = temp_max;
    return temp_max;
}

std::vector<int> Solution::intersect(std::vector<int>& nums1, 
        std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end()); 
    std::sort(nums2.begin(), nums2.end()); 
    std::vector<int> result;
    result.reserve(std::max(nums1.size(), nums2.size()));
    int i = 0, j= 0;
    while(i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}

bool Solution::isValidSudoku(std::vector< vector<char> >& board) {
    return true;    
}

void Solution::reverseString(std::vector<char>& s) {
    int size = s.size();
    for (int i = 0; i < size / 2; ++i) {
        char temp = s[i];  
        s[i] = s[size - 1 -i];
        s[size - 1 -i] = temp;
    }
    return;
}

int Solution::reverse(int x) {
    long tmp = x;
    bool is_negative = false;
    if (x < 0) {
        tmp = -tmp;
        is_negative = true;
    }

    std::vector<int> v;
    while(tmp != 0) {
        int num = tmp % 10;
        tmp = tmp / 10;
        v.push_back(num);
    }

    long new_num = 0;
    for (auto num : v) {
        new_num = new_num * 10 + num;
    } 

    if (is_negative) {
        new_num = -new_num;
    }

    if (new_num < -long(pow(2, 31)) || new_num > long(pow(2, 31)) - 1) {
        return 0;
    }
    return int(new_num);
}

int Solution::firstUniqChar(std::string s) {
    std::map<char, int> char_map;
    for (int i = 0; i < s.size(); ++i) {
        if (char_map.find(s[i]) != char_map.end()) {
            char_map[s[i]] = -1;
        } else {
            char_map[s[i]] = i;
        } 
    }

    for (auto c : s) {
        if (char_map[c] != -1) {
            return char_map[c];
        }
    }
    return -1;
}

bool Solution::isAnagram(std::string s, std::string t) {
    std::map<int, int> s_map;
    std::map<int, int> t_map;
    for (auto c : s) {
        if (s_map.find(c) != s_map.end()) {
            s_map[c]++;
        } else {
            s_map[c] = 1;
        }
    }

    for (auto c : t) {
        if (t_map.find(c) != t_map.end()) {
            t_map[c]++;
        } else {
            t_map[c] = 1;
        }
    }

    if (s_map.size() != t_map.size()) {
        return false;
    }

    for (auto e : s_map) {
        if (t_map.find(e.first) == t_map.end()) {
            return false;
        }
        
        if (t_map[e.first] != e.second) {
            return false;
        }
    }
    return true;
}

bool Solution::isPalindrome(std::string s) {
    int left = 0;
    int right = s.size();
    while (left <= right) {
        while (left < right && !isalnum(s[left]))
            ++left;
        while (right > left && !isalnum(s[right])) 
            --right;

        if (left <= right) {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } else {
                ++left;
                --right;
            }
        } else {
            return false;
        }
    }
    return true;
}

int Solution::myAtoi(std::string str) {
    bool begin = true;
    long temp = 0;
    bool negative = false;
    for (auto c : str) {
        if (begin) {
            //+ - 0-9
            if ( c == '-' ) {
                negative = true;
                begin = false;
            } else if ( c == '+' ) {
                negative = false;
                begin = false;
            } else if (isdigit(c)) {
                negative = false;
                begin = false;
                temp = c - 48;
            } else if ( c == ' ' ) {
                continue;
            } 
            else {
                return temp;
            }
        } else {
            if (isdigit(c)) {
                temp = temp * 10 + c - 48;
            } else {
                break;
            }
        }

        if (temp > INT_MAX || temp < INT_MIN) {
            return negative ? INT_MIN : INT_MAX;
        }
    }

    return negative ? int(-temp) : int(temp); 
}


int Solution::strStr(std::string haystack, std::string needle) {
    int haystack_size = haystack.size();
    int needle_size = needle.size();
    if (needle_size <= 0) {
        return 0;
    }

    for (int i = 0; i < haystack_size; ++i) {
        if (needle_size > haystack_size - i) {
            return -1;
        }

        int j = i;
        int k = 0;
        while (k < needle_size) {
            if (needle[k] != haystack[j]) {
                break;
            } else {
                ++j;
                ++k;
            }
        }

        if (k == needle_size) {
            return i;
        }
    }
    return -1;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) {
    int min_size = 0;
    bool first = true;
    for (auto s : strs) {
        if (first) {
            min_size = s.size();
            first = false;
        } else {
            if (s.size() < min_size) {
                min_size = s.size();
            }
        }
    }

    std::string result("");
    for (int i = 0; i < min_size; ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j][i] != strs[j-1][i]) {
                return result;
            }
        }
        result += strs[0][i];
    }
    return result;
}

void Solution::deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
} 
