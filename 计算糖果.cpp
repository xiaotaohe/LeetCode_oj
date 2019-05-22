#include<iostream>
using namespace std;

int main()
{
    double X,Y,Z,W;
    cin>>X>>Y>>Z>>W;
    if((int)((X+Z)/2)>=0 && (int)((Y+W)/2)>=0 && (int)((W-Y)/2)>=0)
        cout<<((X+Z)/2)<<" "<<((Y+W)/2)<<" "<<((W-Y)/2)<<endl;
    else
        cout<<"No"<<endl;
}