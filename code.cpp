#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class ingri{
    public:
    string name;
    int likeCnt, dislikeCnt;
    ingri(string val){
        name = val;
        likeCnt = 0;
        dislikeCnt = 0;
    }
};


int main()
{   
    long long cust;
    cin >> cust;
    unordered_set<string> like;
    unordered_set<string> dislike;
    unordered_set<ingri*> total;
    for (int c = 0; c < cust; c++)
    {
        int l;
        cin >> l;
        while (l--)
        {
            string s;
            cin >> s;
            ingri* temp = new ingri(s);
            like.insert(s);
            auto itr = total.find(temp);
            if(itr == total.end()){
                total.insert(temp);
                temp->likeCnt = temp->likeCnt + 1;
            }else{
                (*itr)->likeCnt = (*itr)->likeCnt + 1;                
            }
        }
        int d;
        cin >> d;
        while (d--)
        {
            string s;
            cin >> s;
            ingri* temp = new ingri(s);
            dislike.insert(s);
            auto itr = total.find(temp);
            if(itr == total.end()){
                total.insert(temp);
                temp->dislikeCnt = temp->dislikeCnt + 1;
            }else{
                (*itr)->dislikeCnt = (*itr)->dislikeCnt + 1;                
            }
        }
    }
    for(auto itr=total.begin(); itr != total.end();itr++){
        cout<<(*itr)->name<<","<<(*itr)->likeCnt<<","<<(*itr)->dislikeCnt<<endl;
    }
    

    return 0;
}