// Source : None
#include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for (int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}
int main() {
    // Write C++ code here
    cout<<"Length is "<<getLength("Wajahat Ahmed")<<endl;

    return 0;
}