#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;

int main()
{
    int from = 1;
    int to = 9999;

    srand(time(0));
    cout << from + (rand() % (to - from + 1));

    return 0;
}
