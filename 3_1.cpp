/**
 * Author@ Cheng Feitian
 * Date: 2021-3-23
 * Description: 数组中重复的数字
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 1024;

bool duplicate(int numbers[], int length, int *duplication)
{
    bool status;
    int temp[length] = {0};
    if (numbers == nullptr || length <= 0)
    {
        status = false;
    }
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < 0 || numbers[i] > length - 1)
        {
            status = false;
        }
    }

    for (int i = 0; i < length; i++)
    {
        if (temp[numbers[i]] == 0)
        {
            temp[numbers[i]] = numbers[i];
        }
        else
        {
            *duplication = numbers[i];
        }
    }
    return status;
}

int main()
{
    int numbers[] = {1,3,2,0,2,5,3};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int duplication = -1;
    if (duplicate(numbers,length,&duplication))
    {
        cout << duplication << endl;
    }
    else
    {
        cout << duplication << endl;
    }
    
    return 0;
}
