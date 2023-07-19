/*
This code takes the Grammar :
S->aBD
S->aBD
B->cC
C->bC
C->#
D->EF
E->g
E->#
F->f
F->#
Which is hardcoded into the code.This can be changed by changing the productions,Terminals and Non Terminals array and the Parse table.
# Symbol is considered as Epsilon. The input String is supposed to have $ appended to at the end it while giving the input itself. 
The code outputs the Stack and input string at each action and also mentions the action performed.
*/
#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
int index(char* arr,char c){
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        if(arr[i]==c){
            return(i);
        }
    }
    return(-1);
}
int main(){
    char Terminals[]={'a','b','c','g','f','h','$'};
    char Non_Terminals[]={'S','B','C','D','E','F'};
    char Productions[9][10]={"S->aBD","B->cC","C->bC","C->#","D->EF","E->g","E->#","F->f","F->#"};
    int Parse_Table[6][7]={{0,-1,-1,-1,-1,-1,-1},
                            {-1,-1,1,-1,-1,-1,-1},
                            {-1,2,-1,3,3,3,3},
                            {-1,-1,-1,4,4,-1,-1},
                            {-1,-1,-1,5,6,6,-1},
                            {-1,-1,-1,-1,7,8,8}};
    char input[10];
    cin>>input;
    int flag=0,i=0;
    vector<char>s;
    cout<<"Stack\t"<<"Input\t"<<"Action\n";
    s.push_back('$');
    s.push_back('S');
    for(int j=0;j<s.size();j++){
        cout<<s[j];
    }
    cout<<"\t";
    while(i!=strlen(input)){
        for(int m=i;m<strlen(input);m++){
            cout<<input[m];
        }
        cout<<'\t';
        if(isupper(s.back())){
            int ind=Parse_Table[index(Non_Terminals,s.back())][index(Terminals,input[i])];
            if(ind==-1){
                break;
            }
            string temp=Productions[ind];
            int x=temp.length()-1;
            cout<<"Production Used "<<temp<<endl;
            s.pop_back();
            while(temp[x]!='>'){
                if(temp[x]!='#'){
                    s.push_back(temp[x]);
                }
                x--;
            }
        }
        else{
            if(s.back()==input[i]){
                if(s.back()=='$'){
                    flag=1;
                    break;
                }
                i++;
                s.pop_back();
                cout<<"Match "<<input[i-1]<<'\n';
            }
            else{
                break;
            }
        }
        for(int j=0;j<s.size();j++){
            cout<<s[j];
        }
        cout<<'\t';
    }
    if(flag==1){
        cout<<"\nString accepted";
    }
    else{
        cout<<"\nString not Accepted";
    }
}
