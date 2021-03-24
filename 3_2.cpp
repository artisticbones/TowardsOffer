/**
 * Author@ Cheng Feitian
 * Date: 2021-3-23
 * Description: 不修改数组找出重复的数字
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 1024;
//不使用O(n)的辅助空间的解法
/**
 * @brief Get the Duplication object
 * 借助二分查找的思路，根据题意得知如果没有重复数字，那么只会有n个数字，所以在某个区间内必定至少多了一个数字，
 * 所以划分区域看区域的个数是否大于n，在依次缩小区域查
 * @param numbers: 传入的数组
 * @param length: 数组长度
 * @return int 
 */
int getDuplication(const int * numbers,int length){
    if (numbers == nullptr || length <= 0)
    {
        return -1;
    }
    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers,length,start,middle);
        if (end == start)
        {
            if (count > 1)
            {
                return start;
            }
            else
            {
                break;
            }
        }
        if (count > (middle - start + 1))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}

int countRange(const int * numbers,int length,int start,int end){
    if(numbers == nullptr)
        return 0;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] >= start && numbers[i] <= end)
        {
            count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}
