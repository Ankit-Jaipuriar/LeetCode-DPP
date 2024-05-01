class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
       // bool flag=false;
        int count=0;
        if(word.size()==1 || word[0]==ch){
            return word;
        }
        for(int i=0;i<word.size();i++){
            if(word[i]!=ch){
                count++;
            }
        }
        if(count==word.size()){
            return word;
        }
            while(true){
                i++;
                if(word[i]==ch){
                    break;
                }
            }
        string res=word.substr(0,i+1);
        string rem =word.substr(i+1);
        string pre = "";
        for(int i=res.size()-1;i>=0;i--){
            pre+=res[i];
        }
        return pre+rem; 
    }
};