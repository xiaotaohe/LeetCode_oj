class Solution {
public:
	static int lengthOfLongestSubstring(string s) {
		int ch[256] = { 0 };
		int left = 0;
		int mlen = 0;
		int start = left;
		for (size_t i = 0; i<s.size(); i++)
		{
			if (ch[s[i]] == 0 || ch[s[i]]<left)
			{
				if (mlen < i - left + 1)
				{
					mlen = i - left + 1;
					start = left;
				}
			}
			else
			{
				left = ch[s[i]];
			}
			ch[s[i]] = i + 1;
			cout << ch[s[i]] << endl;
		}
		cout << s.substr(start, mlen) << endl;
		return mlen;
	}
};

int main()
{
	cout << Solution::lengthOfLongestSubstring("pwwkew") << endl;
}