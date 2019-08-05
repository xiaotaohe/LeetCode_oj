#include<map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m,m1;
        for(int i = 0;i<ransomNote.size();i++)
            m1[ransomNote[i]]++;
        for(int i = 0;i<magazine.size();i++)
            m[magazine[i]]++;
        for(int i = 0;i<ransomNote.size();i++)
        {
            if(m.count(ransomNote[i])<=0 ||(m.count(ransomNote[i])>0 &&  m1[ransomNote[i]]>m[ransomNote[i]]))
                return false;
                
        }
        return true;
    }
};