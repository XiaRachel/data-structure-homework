#include <iostream>
#include "Sort.h"

using namespace std;
void int_test()
{
    int a[]={5,3,4,7,6,3,6,1,0,2};
    for(int i = 0; i < 10; i++) cout<<a[i]<<" ";
    cout<<endl;
    sort<int>(a, 10);
    for(int i = 0; i < 10; i++) cout<<a[i]<<" ";
    cout<<endl;
}
void float_test()
{
    float a[]={1.2,5.6,4.1,3.5,9.4,13.3,96.1,42.3,45.3,32.1};
    for(int i = 0; i < 10; i++) cout<<a[i]<<" ";
    cout<<endl;
    sort<float>(a, 10);
    for(int i = 0; i < 10; i++) cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int_test();
    float_test();
    return 0;
}