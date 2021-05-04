#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

// iterate through a vector normally
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
     cout<<endl;

    //  iterate using iterator operation in the library
    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
        // iterator it is a pointer
         cout<<*it<<" ";
    }
     cout<<endl;
     
    //  here element is not an iterator but the value of element inside the vector

    for(auto element:v1){
        cout<<element<<" ";
    }
     cout<<endl;
    return 0;
}