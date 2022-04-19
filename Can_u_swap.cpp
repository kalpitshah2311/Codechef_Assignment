
/*
Given a string of length N, find if we can make the string sorted by performing at most one swap. A swap
involves taking any two characters presentin the string and interchanging their positions in the string.
A string is sorted if all letter 'a' appear before all letter 'b', all letter 'b' appear before all letter 'c' and so on.

Input
2
4
acbd
4
adbc

Output
YES
NO

*/
#include<bits/stdc++.h>
using namespace std;

int checkSorted(int n, char arr[]) 

{ 

    // Find counts and positions of  

    // elements that are out of order. 

    int first = 0, second = 0; 

    int count = 0; 

    for (int i = 1; i < n; i++) { 

        if (arr[i] < arr[i - 1]) { 

            count++; 

            if (first == 0) 

                first = i; 

            else

                second = i; 

        } 

    } 

  

    // If there are more than two elements 

    // are out of order. 

    if (count > 2) 

        return false; 

  

    // If all elements are sorted already 

    if (count == 0) 

        return true; 

  

    // Cases like {1, 5, 3, 4, 2} 

    // We swap 5 and 2. 

    if (count == 2) 

        swap(arr[first - 1], arr[second]); 

  

    // Cases like {1, 2, 4, 3, 5} 

    else if (count == 1) 

        swap(arr[first - 1], arr[first]); 

  

    // Now check if array becomes sorted 

    // for cases like {4, 1, 2, 3} 

    for (int i = 1; i < n; i++) 

        if (arr[i] < arr[i - 1]) 

            return false; 

  

    return true; 

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        if(checkSorted(n,arr))
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    }
}
