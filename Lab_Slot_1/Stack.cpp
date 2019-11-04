#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int s[100]{0};
int top=-1;
void push(int x) {
    if(top == 100) {
        cout << "Stack is full" << '\n';
        return;
    }
    s[++top] = x;
}

int pop() {
    if(top < 0) {
        cout << "Stack Empty\n";
        top = 0;
    }
    return s[top--];
}

int peek() {
    if(top < 0) {
        cout << "Stack Empty\n";
    }
    return s[top];
}

int length() {
    return top + 1;
}

int main() {
    int option = 1, x;
    while(option) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Length\n";
        cout << "0. Exit\n";
        cout << "Choose any option\n";
        cin >> option;
        
        switch(option) {
            case 0:
                break;
            case 1:
                cout << "Enter any integer\n";
                cin >> x;
                push(x);
                break;
            case 2:
                cout <<pop();
                break;
            case 3:
                cout <<peek();
                break;
            case 4:
                cout << length();
                break;
            default:
                cout << "Enter a valid option\n";
        }
        cout << '\n';
    }
    return 0;
}