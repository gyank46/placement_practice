#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include <limits.h>
#include<queue>


using namespace std;


struct{

    short s[5];
    union
    {
        float y;
        long z;
    } u;

}t;


int main()
{
    cout<<sizeof(t)<<endl;
}