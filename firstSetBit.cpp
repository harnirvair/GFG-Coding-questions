//Program to find 1st set bit
// Eg. 12 (1100) Output: 3

unsigned int getFirstSetBit(int n){
 return log2((n^(n-1))+1);    
}
