
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string reverse = "";
        string word = "";
        cin >> word;
        if (word != '\n')
        {
            for (int x = 0; x < word.length(); x++)
            {
                reverse += word[x];
            }
            reverse += ' ';
        }
        else{
            cout << reverse << endl;
        } 
    }
    return 0;
}