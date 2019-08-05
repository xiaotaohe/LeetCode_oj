/*class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        for(int i = 0;i<haystack.size();i++)
        {
            int index = 0;
            for(int j = i;j<haystack.size();j++)
            {
                if(index<needle.size() && haystack[j] == needle[index])
                    index++;
                else
                    break;
            }
            if(index == needle.size())
                return i;
        }
        return -1;
    }
};*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int pos = haystack.find(needle);
        return pos;
    }
};