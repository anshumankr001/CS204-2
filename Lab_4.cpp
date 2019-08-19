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
    else
    return -1; 
} 
string infixToPostfix(string s) 
{ 
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    for(int i = 0; i < l; i++) 
    { 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        ns+=s[i]; 
        else if(s[i] == '(') 
          
        st.push('('); 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               ns += c; 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        }
        else{ 
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
  
    }  
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    }
  return ns;
} 
struct tree 
{ 
    int i; 
    tree* left, *right,*parent; 
}; 
  
// A utility function to check if 'c' 
// is an operator 
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
} 
  
// Utility function to do inorder traversal 
void printInorder(struct tree *node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->i << " "; 
  
    /* now recur on right child */
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
tree* constructTree(stack<int> s) 
{ 
    tree *t,*t1,*t2;
    //tree->parent=NULL;
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
/*class node  
{  
public:  
    string info;  
    node *left = NULL, *right = NULL;  
    node(string x)  
    {  
        info = x;  
    }  
};  */
  
// Utility function to return the integer value  
// of a given string  
int toInt(char s)  
{  
    int num = (int)s-48;  
      
    // Check if the integral value is  
    // negative or not 
    // If it is not negative, generate the number  
    // normally 
    /*if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
    // If it is negative, calculate the +ve number 
    // first ignoring the sign and invert the  
    // sign at the end 
    else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } */
      
    return num;  
}  
/*int eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return toInt(root->value);  
    int l_val = eval(root->left);  
    int r_val = eval(root->right);  
    if (root->value=='+')  
        return l_val+r_val;  
  
    if (root->value=='-')  
        return l_val-r_val;  
  
    if (root->value=='*')  
        return l_val*r_val;  
  
    return l_val/r_val;  
}*/
int eval(tree* root)  
{  
    // empty tree  
    if (!root)  
        return 0;  
  
    // leaf node i.e, an integer  
    if (!root->left && !root->right)  
        return root->i;  
  
    // Evaluate left subtree  
    int l_val = eval(root->left);  
  
    // Evaluate right subtree  
    int r_val = eval(root->right);  
  
    // Check which operator to apply  
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
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    return true;
    return false;
}

int mapo(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
    }
}  
stack<int> postfix(char *s)
{
    stack<int> S,O;
    int f=0,a;
    O.push('N');
    for(int i=0;i<strlen(s);i++)
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
                    S.push(mapo(c));
                }
                if(O.top()=='(')
                    O.pop();   
            }
            else if(isop(s[i]))
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapo(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push(mapo(c));
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
   char s[100000];
   cin>>s;
    stack <int> S,s1;
            S=postfix(s);
            while(!S.empty())
            {
                s1.push(S.top());
                S.pop();
            }
   // string s1 = infixToPostfix(s); 
    tree* r = constructTree(s1); 
    cout<<eval(r)<<endl;}}
    return 0; 
} 