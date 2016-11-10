#include <iostream>
#include <list>

using namespace std;

int main()
{
	int arr[] = {10, 20, 30, 40 ,50};

    list<int> l(arr, arr+5);
    list<int>::iterator iter;

    for (iter = l.begin(); iter != l.end(); iter++)
        printf("%d ", *iter);
    printf("\n");

    return 0;
}
