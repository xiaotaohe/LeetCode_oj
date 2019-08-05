#include<map>
class Solution {
public:
    int romanToInt(string s) {
        
        int num = 0;
        map<char,int> m;
        m.insert(pair<char,int>('I',1));        
        m.insert(pair<char,int>('V',5));
        m.insert(pair<char,int>('X',10));
        m.insert(pair<char,int>('L',50));
        m.insert(pair<char,int>('C',100));
        m.insert(pair<char,int>('D',500));
        m.insert(pair<char,int>('M',1000));

        for(int i = 0;i<s.size();i++)
        {
            if(s[i] != 'I' && s[i] != 'X' && s[i] != 'C')
                num += m[s[i]];
            else if(s[i] == 'I' && i<s.size()-1 && (s[i+1] == 'V' || s[i+1] == 'X'))
                num -= m[s[i]];
            else if(s[i] == 'X' && i<s.size()-1 && (s[i+1] == 'L' || s[i+1] == 'C'))
                num -= m[s[i]];
            else if(s[i] == 'C' && i<s.size()-1 && (s[i+1] == 'D' || s[i+1] == 'M'))
                num -= m[s[i]];
            else
                num += m[s[i]];
        }
        return num;
    }
};