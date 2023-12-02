#include <iostream>
using namespace std;

int main()
{
    
    int rows = 8;
    
    int i, space, k = 0;
 
    for(i = 1; i <= rows; ++i)
    {
        
        for(space = 1; space <= rows - i; ++space)
        {
           cout << "  ";
        }
        
        while(k != 2 * i - 1)
        {
           cout << "* ";
           ++k;
        }
        
        k = 0;
        cout << endl;
    }
    return 0;
}
