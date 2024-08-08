#include <bits/stdc++.h>
using namespace std;

//Function to fill array with values of energy
void FillArray(int arr[] , int size){
    int i;
    for (int i=0; i< size; i++){
        cin>> arr[i];
    }
}

//Function to search for specific value
int FindTarget(int arr[], int size, int target){
    for (int k=0; k<size; k++ ){
        if (arr[k]==target)
            return k;
    }
    return -1;
}

int main(){
int n;

//Requesting size of array from user and check the allowed range
do{
cin>> n;
}
while (n>100000);

int array[n];

//Calling function to fill the array with values entered by user
FillArray (array , n);

int target;

//Requesting a specific value to search for it in the array
cin>> target;

//Calling function to search for the specific value
int FoundIndex = FindTarget (array , n , target);

//printing the index of specific value if found in the array
if (FoundIndex!=-1)
    cout  << FoundIndex;

else
     cout << FoundIndex;   
    return 0;
}