/*
Author: Harnirvair
Question: https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1
Date: 02-03-2020
*/

bool areKAnagrams(string str1, string str2, int k)
  {
    int h[26]={0};int c=0;
    if(str1.length()!=str2.length())
    return false;
    for(int i=0;i<str1.length();i++){
        h[str1[i]-'a']++;
    }
    for(int i=0;i<str2.length();i++){
        if(h[str2[i]-'a']==0)
        c++;
        else
        h[str2[i]-'a']--;
    }
    if(c<=k)
    return true;
    return false;
   }