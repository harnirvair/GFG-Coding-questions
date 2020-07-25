int posOfRightMostDiffBit(int m, int n)
{
  
   int ans = m^n;
   // -ans for 2's complement 
   return log2(ans & -ans) +1;
}
