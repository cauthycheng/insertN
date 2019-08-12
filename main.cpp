#include <iostream>
#include<string>
#include<map>
#include<algorithm>
using  namespace std;

bool func(string s1,string s2) {
    map<char,int> mymap;
    for(int i=0;i<s2.size();i++) {
        if(mymap.find(s2[i])==mymap.end()) {
            mymap[s2[i]]=1;
        }
        else {
            mymap[s2[i]]++;
        }
    }
    int len=s2.size();
    for(int i=0;i<=s1.size()-len;i++) {
        map<char,int> temp=mymap;
        bool flag=true;;
        for(int j=i;j<i+len;j++) {
            if(temp.find(s1[j])!=temp.end()) {
                temp[s1[j]]--;
            }
            else {
                flag=false;
                break;
            }
        }
        if(!flag) {
            continue;
        }
        flag=true;
        for(auto it=temp.begin();it!=temp.end();it++) {
            if(it->second!=0) {
                flag=false;
                break;
            }

        }
        if(flag)
           return true;
        else
            continue;
    }
    return false;
}

int main()
{


    string s1,s2;
    s2="bac";
    s1=s2;
    sort(s1.begin(),s1.end());
    int count=0;
    int index;
    bool flag=false;
    string res,res1;
    do
    {
        count++;
        if(s1==s2) {
            index=count;
        }
        if(count==s2.size()+index) {
            res=s1;
            flag=true;
        }

    }while(next_permutation(s1.begin(),s1.end()));
    if(flag) {
        cout<<res<<endl;
    }
    else {
        int len=count;
        count=0;
        do
        {
            count++;
            if(count==s2.size()+index-len) {
                cout<<s1<<endl;
                break;
            }

        }while(next_permutation(s1.begin(),s1.end()));
    }

//    if(func(s1,s2))
//        cout<<"success!";
//    else
//        cout<<"fail";
}
