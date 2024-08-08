#include <bits/stdc++.h>
using namespace std;

//Function to fill array with the achieved heights
void FillArray(int arr[] , int size){
    for (int i=0; i< size; i++){
         do {
            cin >> arr[i];
        }
         while (arr[i] <1 || arr[i] > 1000000000); 
    }
}

int main(){

int n;

//Requesting number of achieved heights from user and check the range
do{
cin >> n;
}
while (n<1 || n>100000);

int heights[n];

//Calling function to fill the array with the entered heights
FillArray (heights , n);

//Function to sort the array in ascending order
sort (heights , heights + n);

//Printing the Maximum achieved height
cout  <<heights[n-1];
return 0;
}