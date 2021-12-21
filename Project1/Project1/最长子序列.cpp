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
            //�ظ��˵Ļ����ͻ������������ѭ��,�����ĺ��룬һ��һ�������ƶ���Ȼ�󲻶ϵ�ɾ����ֱ���ҵ����ظ��ģ�˳��һ��
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

