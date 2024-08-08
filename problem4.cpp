#include <bits/stdc++.h>
using namespace std;

//Function to fill matrix of Justice's power
void JusticeMatrix(int Matrix[][99], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            do {
                cin >> Matrix[i][j];
                if (Matrix[i][j] <1 || Matrix[i][j] > 1000000000) {
                }
            } while (Matrix[i][j] < 1 || Matrix[i][j] > 1000000000);
        }
    }
}

//Function to fill matrix of Villian's power
void VilliansMatrix(int Matrix[][99], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            do {        
                cin >> Matrix[i][j];
                if (Matrix[i][j] < 1 || Matrix[i][j] > 1000000000) {
                }
            } while (Matrix[i][j] < 1 || Matrix[i][j] > 1000000000);
        }
    }
}

//Function to compare powers in the two matrices 
void Comparing (int Matrix1[][99], int Matrix2[][99], int r , int c)
{
    int VilliansCount=0;
    int JusticeCount=0;
    for (int i=0 ; i<r; i++){
        for (int j=0; j<c; j++){      
            if (Matrix1[i][j] > Matrix2[i][j])
                JusticeCount++;

            else if (Matrix1[i][j] < Matrix2[i][j])    
                VilliansCount++;

            else {
                JusticeCount++;
                VilliansCount++;
                }
        }
    }

    if (JusticeCount > VilliansCount)
        cout<< "Justice League";

    else if (JusticeCount < VilliansCount)   
        cout<< "Villains";

    else
        cout<< "Tie";    

}

int main(){

int rows , cols;

//Requesting number of rows and columns from user and check the range
do{
cin >> rows;}
while (rows<1 || rows>100);

do{
cin >> cols;}
while (cols<1 || cols>100);

int justice[rows][99];
int villians[rows][99];

//Calling function to fill Justice's power matrix
JusticeMatrix(justice , rows , cols);

//Calling function to fill Villian's power matrix
VilliansMatrix(villians , rows , cols);

//Calling function to compare the powers and print the winner
Comparing (justice, villians, rows , cols );

return 0;
}