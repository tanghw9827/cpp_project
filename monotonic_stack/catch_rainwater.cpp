#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void catchRain(const vector<int> &height, int &result)
{
    stack<int> st;
    for (int i = 0; i < height.size(); i++)
    {
        if (st.empty() || height[i] <= height[st.top()])
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int mid = st.top();
                st.pop();
                if (!st.empty())
                {
                    int h = min(height[i], height[st.top()]) - height[mid];
                    int w = i - st.top() - 1;
                    result += h * w;
                }
            }
            st.push(i);
        }
    }
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = 0;
    catchRain(height, result);
    cout << result << endl;
    return 0;
}