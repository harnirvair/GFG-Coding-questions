 //Eg. apple app appe
 // Output: app
 
 public String longestCommonPrefix(String[] str) {
           
              int n = str.length;
        if(n==0 || str == null)
            return "";
        String pre = str[0];
		    for(int j=1;j<n;j++){
		        while(str[j].indexOf(pre)!=0)
		        pre = pre.substring(0, pre.length()-1);
		    }
		    if(pre.length() ==0)
		    return "";
		    else
		    return pre;
    
    }
