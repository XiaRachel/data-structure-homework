#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    queue<int> que({1, 2, 3, 4, 5});
    stack<int> sta;
    int x;
    while (!que.empty())
    {
        x = que.front();
        que.pop();
        sta.push(x);
    }
    while (!sta.empty())
    {
        x = sta.top();
        sta.pop();
        que.push(x);
    }
}
