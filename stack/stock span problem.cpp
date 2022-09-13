class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        stack<pair<int, int>> s;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().first <= price[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
            s.push({price[i], i});
        }
        for (int i = 0; i < n; i++)
        {
            v[i] = i - v[i];
        }
        return v;
    }
};