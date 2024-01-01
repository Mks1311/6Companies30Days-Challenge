string encode(string src)
{     
  //Your code here 
  string res;
  int i=0;
  while(i<src.size()){
      res+=src[i];
      int j=i+1,cnt=1;
      while(j<src.size() && src[i]==src[j]) {
          j++;
          cnt++;
      }
      res+=to_string(cnt);
      i=j;
  }
  return res;
}   