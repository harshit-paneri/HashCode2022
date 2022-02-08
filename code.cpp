#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
vector<vector<string>> like;
vector<vector<string>> dislike;
int maxCust = 0;
unordered_set<string> finalIngri;
void simulator(unordered_set<string> total,int cust){
    int count = 0;    
    int flag;
    for(int i=0;i<cust;i++){
        flag = 1;
        //like check
        for(int j=0;j<like[i].size();j++){
            if(total.find(like[i][j]) == total.end()){
                flag = 0;
                break;
            }
        }
        //dislike check
        if(flag){
            for(int j=0;j<dislike[i].size();j++){
                if(total.find(dislike[i][j]) != total.end()){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) count++;
    }
    if(count > maxCust){
        finalIngri = total;
        maxCust = count;
    }  
}
void removeEle(vector<vector<string>> dislike,int i,unordered_set<string> total,int cust){
    for(auto it:dislike[i]){
        total.erase(it);
    }
    simulator(total,cust);
}


int main()
{   
    long long cust;
    cin >> cust;
    unordered_set<string> total;
    /*
    1 : like :- a,b,c dislike :- d,e
    2 : like :- b,c,d dislike :- f
    total : a,b,c,f
    */
    for (int c = 0; c < cust; c++)
    {
        int l;
        cin >> l;//like input
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
        cin >> d;//dislike input
        while (d--)
        {
            string s;
            cin >> s;
            temp1.push_back(s);
            total.insert(s);  
            
        }
        dislike.push_back(temp1);
    }
    for(int i=0;i<cust;i++){
        removeEle(dislike,i,total,cust);
    }  
    cout<<maxCust<<endl;
    cout<<finalIngri.size()<<" ";
    for(auto it:finalIngri) cout<<it<<" "; 

    

    return 0;
}