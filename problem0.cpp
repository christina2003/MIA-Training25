#include <bits/stdc++.h>
using namespace std;

int main(){

string name;
int count=0;

getline (cin,name);

//checking that the name's length doesn't exceed the allowed range
for (int i=0; name[i]!='\0'; i++){
    count++;
}


//printing the greeting
if (count<=100){
    cout << "Hello, " << name << "!"<<endl;
}

else 
    cout<< "Invalid Name.";
 return 0;
}