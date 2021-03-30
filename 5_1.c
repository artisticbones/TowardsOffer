/**
 * Author@ Cheng Feitian
 * Date: 2021-3-30
 * Description: 替换空格
 * Input Format: 
 * Output Format: 
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 1024

char *replaceSpace(char *s)
{
    if (s == NULL)
    {
        return NULL;
    }

    int numberOfBlank = 0;
    int originalLength = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        originalLength++;
        if (s[i] == ' ')
        {
            numberOfBlank++;
        }
        i++;
    }
    // newLength 是把空格替换成“%20”之后的长度
    int newLength = originalLength + numberOfBlank * 2;
    char *t = (char *)malloc(newLength);
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;

    while (indexOfNew >= 0 && originalLength >= 0)
    {
        if (s[indexOfOriginal] == ' ')
        {
            t[indexOfNew--] = '0';
            t[indexOfNew--] = '2';
            t[indexOfNew--] = '%';
        }
        else
        {
            t[indexOfNew--] = s[indexOfOriginal];
        }
        indexOfOriginal--;
    }
    return t;
}

void test01()
{
    char s[] = "We are happy.";
    replaceSpace(s);
    printf("%s",replaceSpace(s));
}

int main(void)
{
    test01();
    return 0;
}
