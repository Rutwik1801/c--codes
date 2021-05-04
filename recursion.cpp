#include<iostream>
using namespace std;


// sum till a particular number
int Sum(int end){
    if(end==0){
        return 0;
    }
   int prevSum=Sum(end-1);
   return end + prevSum;
    }


// power of a number
 int Power(int n,int p){
     if(p==0){
       return 1;
     }
     int prevPower=Power(n,p-1);
     return n*prevPower;
 }   

// factorial of a number
 int Fact(int n){
     if(n==0){
         return 1;
     }
  int prevFact=Fact(n-1);
  return n*prevFact;
 }

// fibonacci sequence of a number
 int Fibonacci(int n){
     if(n==0){
         return n;
     } 
     if(n==1){
         return n;
     }
     return Fibonacci(n-1)+Fibonacci(n-2);
 }


// check if an array is sorted or not

bool ArrayCheck(int arr[],int n){
     if(n==1){
         return true;
     }
    bool prevArray=ArrayCheck(arr+1,n-1);
    return ((arr[0]<arr[1]) && prevArray); 
}

// reverse a string using recursion

void ReverseIt(string s){
    if(s.length()==0){
        return;
    }
    // substr gives everything starting from index 1 in this case
    string rev=s.substr(1);
    ReverseIt(rev);
    cout<<s[0];
}

// replace pi with 3.14 in a string

void ReplacePi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        ReplacePi(s.substr(2));
    } else{
        cout<<s[0];
        ReplacePi(s.substr(1));
    }
}

int main(){
    int a,b;
    int arr[]={1,4,3,4};
    cout<<ArrayCheck(arr,4);
   cout<<Sum(3);
   cout<<Fact(3);
    cout<<Power(3,4);
    cout<<Fibonacci(7);
    ReverseIt("binod");
    ReplacePi("rfrfrfrpiedepi");
    return 0;
}