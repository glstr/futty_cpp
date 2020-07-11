#include "howuse.h"

#include <stdlib.h>
#include <iostream>

#include "basic_use.h"
#include "boost_use.h"
#include "leetcode.h"
#include "pointer_use.h"


using namespace std;

template<class t>
void display_vector(std::vector<t> v) {
    for(auto e : v) {
        cout << e << endl;
    }
}

int main() {
    //snow::HowUser* h = new snow::HowUser;
    //snow::BoostUse* b = new snow::BoostUse;
    //snow::BasicUser* bu = new snow::BasicUser;
    ////b->show_minmax();
    //h->rapidJsonHelperUsage();
    ////bu->struct_usage(); 
    //delete h;
    //delete b;
    //delete bu;
    std::vector<int> nums{1, 2, 3, 4, 4, 5}; 
    Solution solution;

    //
    cout << "removeDuplicates:" << endl;
    int ret = solution.removeDuplicates(nums);
    cout << ret << endl;
    display_vector(nums);
    
    //
    std::vector<int> cases{-1,-100,3,99};
    cout << "rotate:" << endl;
    solution.rotate(cases, 2);
    display_vector(cases);

    //
    std::vector<int> c_cases{-1,-100,3,99};
    bool c_ret = solution.containsDuplicate(c_cases);
    cout << c_ret << endl; 


    cout << "plusOne:" << endl;
    std::vector<int> p_cases{1,2,3};
    std::vector<int> v = solution.plusOne(p_cases);
    display_vector(v);

    cout << "moveZeroes:" << endl;
    std::vector<int> m_cases{1,0,2,0,3};
    solution.moveZeroes(m_cases);
    display_vector(m_cases);

    cout << "twoSum:" << endl;
    std::vector<int> t_cases{1,0,2,0,3};
    v = solution.twoSum(t_cases, 5);
    display_vector(v);

    cout << "maxProfit:" << endl;
    std::vector<int> mp_cases{7,1,5,3,6,4};
    int max = solution.maxProfit(mp_cases);
    cout << "max:" << max << endl;;

    {
        cout << "intersect:" << endl;
        std::vector<int> nums1{1,2,2,1};
        std::vector<int> nums2{1,2,2,1};
        std::vector<int> res = solution.intersect(nums1, nums2);
        display_vector(res);
    }

    {
        cout << "reverseString" << endl;
        std::vector<char> s{'h','e','l','l','o'};
        solution.reverseString(s);
        display_vector(s);
    }

    {
        int num = -2147483648;
        int res = solution.reverse(num);
        cout << "res:" << res << endl;
    }

    {
        cout << "firstUniqChar" << endl;
        std::string s("loveleetcode");
        int res = solution.firstUniqChar(s);
        cout << "res:" << res << endl;
    }

    {
        cout << "isAnagram:" << endl;
        std::string s("anagram");
        std::string t("nagaram");
        auto res = solution.isAnagram(s, t);
        cout << "res:" << res << endl;
    }

    {
        cout << "isPalindrome" << endl;
        std::string s("A man, a plan, a canal: Panama");
        auto res = solution.isPalindrome(s);
        cout << "res:" << res << endl; 
    }

    {
        cout << "myAtoi" << endl;
        std::string s("20000000000000000000");
        auto res = solution.myAtoi(s);
        cout << "res:" << res << endl; 
    }

    {
        cout << "strStr" << endl;
        std::string haystack("");
        std::string needle("a");
        auto res = solution.strStr(haystack, needle);
        cout << "res:" << res << endl; 
    }

    {
        cout << "longestCommonPrefix" << endl;
        std::vector<std::string> strs{};
        auto res = solution.longestCommonPrefix(strs);
        cout << "res:" << res << endl; 
    }
    return 0;
}

