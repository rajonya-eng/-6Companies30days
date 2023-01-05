class Solution {
public:
    int sttonum(string number){
        int newNumber=0;
        int k=0;
        if(number[0]=='-'){
            k=1;
        }
        for ( int i = number.length() -1 ; i >= k; i-- ) {
        int power = number.length() - i -1;
        newNumber += (std::pow( 10.0,  power) * (number[i] - '0'));
    }
    if(k==1){
        newNumber=newNumber*(-1);
    }
    cout<<newNumber;
    return newNumber;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> st1;
       

        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){

                long long p=st1.top();
                st1.pop();
                long long q=st1.top();
                st1.pop();
                if(tokens[i]=="+"){
                    st1.push(p+q);
                }
                if(tokens[i]=="-"){
                    st1.push(q-p);
                }
                if(tokens[i]=="*"){
                    st1.push(p*q);
                }
                if(tokens[i]=="/"){
                    
                    st1.push(q/p);
                }
            }
            else{
                int k=sttonum(tokens[i]);
                
                st1.push(k);
            }
        }
        
        int l= st1.top();
        
        return l;
    }
};