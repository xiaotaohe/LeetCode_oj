#include<iostream>
#include<algorithm>
using namespace std;
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(),gifts.end());
        int count = 1;
        int num = gifts[0];
        for(int i = 1;i<gifts.size()-1;i++)
        {
            if(count>gifts.size()/2)
                break;
           if(gifts[i] == num)
               count++;
            else
            {
                num = gifts[i];
                count = 1;
            }
        }
        if(count>gifts.size()/2)
            return num;
        else
            return 0;
    }
};