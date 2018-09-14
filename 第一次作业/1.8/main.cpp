#include <iostream>
#include <string>
#include "Search.h"
using namespace std;
void int_searchtest()
{
    int a[]={2,6,8,3,4,9,7,5,1,0};
    cout<<search<int>(a, 3, 10)<<endl;
    cout<<search<int>(a, 10, 10)<<endl;
}
void string_searchtest()
{
    string a[]={"qwe","ewq","123","321","456"};
    cout<<search<string>(a, "456", 5)<<endl;
    cout<<search<string>(a, "sda", 5)<<endl;
}
int main()
{
    int_searchtest();
    string_searchtest();
    return 0;
}