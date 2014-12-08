#include<iostream>
#include<cstdio>
#include <cstdlib>
using namespace std;

int compareInts(const void* a, const void* b)
{
  // Ascending Order
  return *(const int *)a > *(const int *)b;
  //Descending *(const int *)a < *(const int *)b;
}

int main(void)
{
    int items[] = { 4, 3, 1, 2 };
    qsort(items, sizeof(items) / sizeof(items[0]), sizeof(items[0]), compareInts);
    int i;
    for( i=0;i<4;i++)
        printf("%d\n",items[i]);
    return 0;
}
