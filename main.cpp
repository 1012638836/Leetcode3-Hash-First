#include<iostream>
#include<vector>
#include<String>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int len = s.length();
		int maxlen = 0, start = 0;
		int table[256];
		for (int i = 0; i < 256; i++) { table[i] = -1; }
		for (int i = 0; i < len; i++)
		{
			if (table[s[i]] != -1)
			{
				while (start <= table[s[i]]) { table[s[start++]] = -1; }
			}
			if (i - start + 1 > maxlen) { maxlen = i - start + 1; }
			table[s[i]] = i;
		}
		return maxlen;
	}
};
int main()
{
	Solution a;
	string s = "c";
	int result = a.lengthOfLongestSubstring(s);
	cout << result << endl;
	getchar();
	return 0;
}