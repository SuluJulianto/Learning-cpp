#include <iostream>
using namespace std;
//Numbers on diagonal.
//to get nicer result, input size equal less than 4 :)
int diag(int num)
{
    int result = 0;
    for (int i = 1; i <= num; i++)
        result += i;
    return result;
}
int diag2(int num ,int size) {
    int result;
    result = size*size - diag(num) + 1;
    return result;
}
int main()
{
    int size;
    cin >> size;
    int *square = new int[size*size - 1];
    for (int i = 0; i < size; i++) //height
    {
        for (int j = 1; j <= size; j++) {//width
            if ((i + j) <= size) {
                square[size*i + (j - 1)] = diag(j + i - 1) + (i+1);
                cout << square[size*i + (j - 1)] << " ";
            }
            if ((i + j) > size) {
                square[size*i + (j - 1)] = diag2((2*size - 1 - (i+j)), size) - (size - i);
                cout << square[size*i + (j - 1)] << " ";
            }
        }
        cout << endl;
    }
return 0;}
