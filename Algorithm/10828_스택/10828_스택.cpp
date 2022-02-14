#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    stack<int> _stack;
    string op;

    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == "push")
        {
            int num = 0;
            cin >> num;
            _stack.push(num);
        }
        if (op == "pop")
        {
            if (!_stack.empty())
            {
                cout << _stack.top() << endl;
                _stack.pop();
            }
            else
                cout << -1 << endl;
        }
        if (op == "size")
            cout << _stack.size() << endl;
        if (op == "empty")
        {
            if (_stack.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        if (op == "top")
        {
            if (_stack.empty())
                cout << -1 << endl;
            else
                cout << _stack.top() << endl;
        }
    }
}