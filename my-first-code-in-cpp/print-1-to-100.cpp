#include <iostream>
using namespace std;

void print(int num)
{
    if(num<=100)
    {
       cout << num << " ";
       print(num+1);
    }
}

int main() {
    int num = 1;
    
    print(num);
    
    return 0;
}
