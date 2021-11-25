#include"iostream"
#include<vector>
#include<map>
using namespace std;
/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


/// <summary>
/// 核心就是不用比较两次，只和后面的比较
/// </summary>
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					index.push_back(i);
					index.push_back(j);
					return index;
				}
			}
		}
		return index;
	}
};
/// <summary>
/// 用字典来村这个值就好了
/// </summary>
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> myMap;//建立hash表存放数组元素
		vector<int> result(2, -1);//存放结果
		for (int i = 0; i < nums.size(); i++)
		{
			myMap.insert(map<int, int>::value_type(nums[i], i));
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (myMap.count(target - nums[i]) > 0 && (myMap[target - nums[i]] != i))
				//判断是否找到目标元素且目标元素不能是本身
			{
				result[0] = i;
				result[1] = myMap[target - nums[i]];
				break;
			}
		}
		return result;
	};
};
