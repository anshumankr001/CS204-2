#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if (c=='$')
        return 4;
    return -1; 
} 
struct tree 
{ 
    int i; 
    tree* left, *right,*parent; 
}; 
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
} 
void printInorder(struct tree *node) 
{ 
    if (node == NULL) 
        return; 
      printInorder(node->left); 
      cout << node->i << " "; 
    printInorder(node->right); 
} 
tree * newNode(int v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}
tree* constructTree(stack<ll> s) 
{ 
    tree *t,*t1,*t2;
        stack<tree *> st;
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=newNode(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=newNode(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
            s.pop();
        }
    }
    return t;
}
ll eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    int l_val = eval(root->left);  
    int r_val = eval(root->right);  
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

bool isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='$')
    return true;
    return false;
}

ll mapop(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '$': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
    }
}  
stack<long long > postfix(string s)
{
    stack<long long > S,O;
    long long f=0,a;
    O.push('N');
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                a=S.top();
                S.pop();
                S.push(a*10+s[i]-'0');
            }
            else 
            {
                S.push(s[i]-'0');
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
                    S.push(mapop(c));
                }
                if(O.top()=='(')
                    O.pop();   
            }
            else if(isop(s[i])&&s[i]!='^'&&s[i]!='$')
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapop(c));
                }
                O.push(s[i]);
            }
            else if(s[i]=='^'||s[i]=='$')
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapop(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push(mapop(c));
        }
    return S;
}

int main() 
{ 
  ll t;
  cin>>t;
  while(t--)
  {
    ll no;
    cin>>no;
    while(no--)
    {
        ll u=1;
   string s;
   cin>>s;
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
        }
    stack <ll> S,s1;
            S=postfix(s);
            while(!S.empty())
            {
                s1.push(S.top());
                S.pop();
            }
                tree* r = constructTree(s1); 
    cout<<eval(r)<<endl;}}
    return 0; 
} 
