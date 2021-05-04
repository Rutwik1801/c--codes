#include<iostream>
#include<math.h>
using namespace std;

// Return all possible subarrays of an array; 

// int main(){
// int arr[5]={1,2,3,4,5};
// for(int i=0;i<5;i++){
//     for(int j=i;j<5;j++){
//         for(int k=i;k<=j;k++){
//             cout<<arr[k];
//         }
//         cout<<endl;
//     }
// }
//     return 0;
// }


// To find sum of subarray which is maximum
// since the above method has a bad time complexity we use cumulative sum approach here;

// int main(){
//     int n=4;
// int arr[n]={-1,4,7,2};

// // we make an array with size 1 greater than initial array then initialize its first element to zero
// int currSum[n+1];
// currSum[0]=0;
// // this loop stores the cumulative sum of the elements in the array;
// for(int i=1;i<=n;i++){
//     currSum[i]=currSum[i-1]+arr[i-1];
// }

// int maxSum=INT16_MIN;

// for(int i=1;i<=n;i++){
//     int sum=0;
//     for(int j=0;j<=i;j++){
//         // this gives the sum of each permutation of the subarrays and compares it to get the maximum value;
//         sum=currSum[i]-currSum[j];
//         maxSum=max(maxSum,sum);
//     }
// }
// cout<<maxSum;
//     return 0;
// }

// a better approach is the kadane's algorithm
// it has O(n) complexity

int main(){
    int n=4;
    int arr[n]={-1,4,7,2};
    int maxSum=INT16_MIN;
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        // if the loop encounters a negative integer, it changes the value to zero;
        if(currSum<0){
            currSum=0;
        }
        maxSum=max(maxSum,currSum);
    }
    cout<<maxSum;
   return 0;
}
