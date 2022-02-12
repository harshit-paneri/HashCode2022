#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
vector<vector<string>> like;
vector<vector<string>> dislike;
int maxCust = 0;
unordered_set<string> finalIngri;
void removeEle(vector<vector<string>>, vector<int>, unordered_set<string>, int);
void subsetsUtil(unordered_set<string> total, int n, vector<vector<int>> &res, vector<int> &subset, int index)
{

    //res.push_back(subset);
    removeEle(dislike, subset, total, n);
    for (int i = index; i < n; i++)
    {

        // include the A[i] in subset.
        subset.push_back(i);

        // move onto the next element.
        subsetsUtil(total, n, res, subset, i + 1);

        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
    return;
}
void subsets(unordered_set<string> total, int n)
{
    vector<int> subset;
    vector<vector<int>> res;

    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(total, n, res, subset, index);

    return;
}

void simulator(unordered_set<string> total, int cust)
{
    int count = 0;
    int flag;
    for (int i = 0; i < cust; i++)
    {
        flag = 1;
        // like check
        for (int j = 0; j < like[i].size(); j++)
        {
            if (total.find(like[i][j]) == total.end())
            {
                flag = 0;
                break;
            }
        }
        // dislike check
        if (flag)
        {
            for (int j = 0; j < dislike[i].size(); j++)
            {
                if (total.find(dislike[i][j]) != total.end())
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            count++;
    }
    if (count > maxCust)
    {
        finalIngri = total;
        maxCust = count;
    }
}
void removeEle(vector<vector<string>> dislike, vector<int> idx, unordered_set<string> total, int cust)
{
    //{0,1}
    for (int i = 0; i < idx.size(); i++)
    {
        for (auto it : dislike[i])
        {
            total.erase(it);
        }
    }
    simulator(total, cust);
}

int main()
{
    long long cust;
    cin >> cust;
    unordered_set<string> total;
    /*
    1 : like :- a,b,c dislike :- d,e
    2 : like :- b,c,d dislike :- f
    {{d,e},{f}}
    total : a,b,c,f
    */
    for (int c = 0; c < cust; c++)
    {
        int l;
        cin >> l; // like input
        vector<string> temp;
        while (l--)
        {
            string s;
            cin >> s;
            temp.push_back(s);
            total.insert(s);
        }
        like.push_back(temp);
        vector<string> temp1;
        int d;
        cin >> d; // dislike input
        while (d--)
        {
            string s;
            cin >> s;
            temp1.push_back(s);
            total.insert(s);
        }
        dislike.push_back(temp1);
    }
    subsets(total,cust);
    cout << maxCust << endl;
    cout << finalIngri.size() << " ";
    for (auto it : finalIngri)
        cout << it << " ";

    return 0;
}
