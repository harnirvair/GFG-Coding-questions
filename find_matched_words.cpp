/*
Program: https://practice.geeksforgeeks.org/problems/match-specific-pattern/1/?track=placement100-cpp&batchId=185
Date: 03-03-2020
*/

vector<string> findMatchedWords(vector<string> dict,
                      string pattern)
{
 
     vector<string> a;
    // cout<<pattern.size();
     if(dict.size()==0 || pattern.size()==0)
      return a;
      for(int i=0;i<dict.size();i++){
          //cout<<i<<endl;
          int k = pattern.size();
          if(dict[i].size()==pattern.size()){
              map <char, char> m;int flag=0;
              for(int j=0;j<k;j++){
                  if(m.find(pattern[j])==m.end()){
                      m[pattern[j]]=dict[i][j];
                  }else{
                      if(m[pattern[j]]!=dict[i][j]){
                          flag++;
                          break;
                      }
                  }
              }
              if(flag==0)
              a.push_back(dict[i]);
          }
      }
      return a;
}