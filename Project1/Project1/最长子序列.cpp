#include<iostream>
#include<string>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> up;
        int maxStr = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int count = 0;
            cout <<"------------------"<< endl;
            char current = s[i];
            //重复了的话，就会进入下面的这个循环,将左侧的号码，一个一个往后移动，然后不断地删除，直到找到不重复的，顺便一提
            while (up.find(current) != up.end())
            {
                count++;
                cout << count<<endl;
                up.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i - left + 1);
            up.insert(s[i]);
        }
        return maxStr;
    }
};


int main()
{
    Solution s = Solution();
    cout<<(s.lengthOfLongestSubstring("abbc"));
}

