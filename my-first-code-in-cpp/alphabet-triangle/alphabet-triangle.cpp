#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (int a = 0; a <= 25; a++)
    {
        cout << string(26 - a, ' ');
        for (int b = 0; b <= a; b++)
            cout << alpha[b];
        cout << "\n";
    }
    return 0;
}
