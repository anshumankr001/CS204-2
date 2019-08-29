#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct tree 
{
    long long i;
    tree * left,* right,* parent;
};
long long prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if(c=='$')
    return 4;
    return -1; 
} 
long long isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    if(c=='^'||c=='$')
    return 2;
    return 0;
}

long long mapop(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
        case '$': return -2;
    }
    return 0;
}

vector<long long > postfix(string s)
{
    vector<long long > S;
    stack<long long> O;
    long long f=0,a;
    O.push('N');
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                S[S.size()-1]=S[S.size()-1]*10+s[i]-'0';
            }
            else 
            {
                S.push_back(s[i]-'0');
                f=1;
            }
        }

        else 
        {
            f=0;
            if(s[i]=='(')
                O.push('(');
            else if(s[i]==')')
            {
                while(O.top()!='N'&&O.top()!='(')
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                if(O.top()=='(')
                    O.pop();   
            }
            else if(isop(s[i])==1)
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                O.push(s[i]);
            }
            else if(isop(s[i])==2)
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push_back(mapop(c));
        }
    return S;
}

tree * newNode(ll v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

tree * etree(vector<ll > v)
{
    tree *t,*t1,*t2;
    stack<tree *> st;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]>=0)
        {
            t=newNode(v[i]);
            st.push(t);
        }
        else
        {
            t=newNode(v[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            if(1)
            {t->right=t1;
            t->left=t2;}
            st.push(t);
        }
    }
    return t;
}


void show(vector<ll > s)
{
    for(ll i=0;i<s.size();i++)
    {
        cout<<s[i]<<' ';
    }
}

void printInorder(struct tree* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout << node->i << " "; 
    printInorder(node->right); 
} 

ll eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    ll l_val = eval(root->left);  
    ll r_val = eval(root->right);  
    if (root->i==-1)  
        return l_val+r_val;  
    if (root->i==-2)  
        return l_val-r_val;  
    if (root->i==-3)  
        return l_val*r_val;  
    if(root->i==-4)
        return l_val/r_val;
    return pow(l_val,r_val);  
} 

int idno(char c)
{
    if(isupper(c))
        return c-'A';
    return c-'a';
}

long long value(string s)
{
    vector <ll > S;
    S=postfix(s);
    //cout<<1;
    //show(S);
    tree *p=etree(S);
    //  cout<<2;
    return eval(p);
}

void process(string s,map<string,ll> *M)
{
    string s1="";
    vector<ll> dl;
    ll u=1;
    dl.push_back(-1);
    for(ll i=0;i<s.length();i++)
    {
        if(u&&s[i]=='-')
        {
            s[i]='$';
            s.insert(i,"0");
        }
        if(isop(s[i])||s[i]=='(')
            u=1;
        else u=0;
        if(isop(s[i])||s[i]=='('||s[i]==')'||s[i]=='=')
        {
            dl.push_back(i);
        }
    }
    dl.push_back(s.length());
    // for(int i=0;i<dl.size();i++)
    //     cout<<dl[i]<<' ';
    // cout<<endl;
    string t,v="";
    //cout<<s.size();
    if(s[dl[1]]=='=')
    {
        v=s.substr(dl[0]+1,dl[1]-dl[0]-1);
        dl[0]=dl[1];
        dl.erase(dl.begin()+1);
    }
    for(ll i=0;i<dl.size()-1;i++) 
    {
        t=s.substr(dl[i]+1,dl[i+1]-dl[i]-1);
        if(!t.size())
            {
                s1+=s[dl[i+1]];
                continue;
            }
        if(isdigit(t[0]))
        {
            s1+=t;
        }
        else
        {
            auto itr=M->find(t);
            if(itr==M->end())
            {
                cout<<"CANT BE EVALUATED"<<endl;
                return;
            }
            else
            {
                s1+=to_string(itr->second);
            }
        }
        if(i+1<dl.size())
        {
            s1+=s[dl[i+1]];
        }
    }
    if(v.length())
    {
        auto itr=M->find(v);
        if(itr==M->end())
        {
            M->insert({v,value(s1)});
        }
        else itr->second=value(s1);
    }
    else
    {
        cout<<value(s1)<<endl;
    }
}

int main()
{   
    ll q;
    cin>>q;
    while(q--)
    {
        ll t;
        cin>>t;
        map<string,ll> M;
        while(t--)
        {
        ll u=1;
            string s;
            cin>>s;
    process(s,&M);
        }
    }
}