/*
Problem: https://practice.geeksforgeeks.org/problems/trapping-rain-water/1
Date: 03-03-2020
*/

int trappingWater(int arr[], int n){

    vector <int> left,right;
    int curr_max=arr[0];
    left.push_back(curr_max);
    for(int i=1;i<n;i++){
        curr_max=max(curr_max,arr[i]);
        left.push_back(curr_max);
    }
    curr_max=arr[n-1];
        right.push_back(curr_max);
    for(int i=n-2;i>=0;i--){
        curr_max=max(curr_max,arr[i]);
        right.push_back(curr_max);
    
    }
    reverse(right.begin(), right.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=min(left[i],right[i])-arr[i];
    }
    
    return sum;
    // Your code here
    
}