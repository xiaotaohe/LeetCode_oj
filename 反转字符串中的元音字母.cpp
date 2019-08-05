class Solution {
public:
    //˫ָ�뷨
    string reverseVowels(string s) {
        string yuan = "aeiouAEIOU";
        int left = 0,right = s.size()-1;
        while(left<right)
        {
            while(left<right && yuan.find(s[left]) == -1)
                left++;
            while(left<right && yuan.find(s[right]) == -1)
                right--;
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};