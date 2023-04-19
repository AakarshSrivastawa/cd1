#include <bits/stdc++.h>
#define ll long long
using namespace std;

void display(stack<char>s){
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<"\t\t";
}
int main()
{
    map<pair<int,char>,pair<bool,int>> action;
    map<pair<int,char>,int> Goto;
    action[{0,'p'}]={true,3};
    action[{0,'q'}]={true,4};
    action[{0,'q'}]={true,-2};
    action[{1,'p'}]={true,-2};
    action[{1,'q'}]={true,-2};
    action[{1,'$'}]={true,-1};
    action[{2,'p'}]={true,3};
    action[{2,'q'}]={true,4};
    action[{2,'$'}]={true,-2};
    action[{3,'p'}]={true,3};
    action[{3,'q'}]={true,4};
    action[{3,'$'}]={true,-2};
    action[{4,'p'}]={false,3};
    action[{4,'q'}]={false,3};
    action[{4,'$'}]={false,3};
    action[{5,'$'}]={false,1};
    action[{5,'q'}]={true,-2};
    action[{5,'p'}]={true,-2};
    action[{6,'p'}]={false,2};
    action[{6,'q'}]={false,2};
    action[{6,'$'}]={false,2};
    Goto[{0,'Q'}]=2;
    Goto[{0,'P'}]=1;
    Goto[{2,'Q'}]=5;
    Goto[{3,'Q'}]=6;
    vector<string> prod(4);
    prod[1]="P=QQ";
    prod[2]="Q=pQ";
    prod[3]="Q=q";
    string s="pqq$";
    stack<char> st;
    st.push('0');
    int i=0;
    bool check=false;
    while(i<s.size()){
        int n=st.top()-'0';
        pair<bool,int> p=action[{n,s[i]}];
        if( p.second==-1){
            check=true;
            break;
        }
        else if(p.second==-2)break;
        if(p.first){
            st.push(s[i]);
            st.push(p.second+'0');
            ++i;
        }
        else{
            int r=p.second;
            // cout<<r<<endl;
            for(int i=0;i<2*(prod[r].size()-2);++i) st.pop();
            int num=st.top()-'0';
            st.push(prod[r][0]);
            st.push(Goto[{num,prod[r][0]}]+'0');
        }
        display(st);
        for(int j=0;j<=i;++j)cout<<s[j];
        cout<<endl;
    }
    if(check)cout<<"accepted\n";
    else cout<<"rejected\n";
    return 0;
}