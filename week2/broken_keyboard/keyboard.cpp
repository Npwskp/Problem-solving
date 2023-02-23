#include <bits/stdc++.h>
using namespace std;

void show_list(list<char> x){
    for(list<char>::iterator i=x.begin(); i!=x.end(); i++){
        cout << *i;
    }
}

int main(){
    string tmp;
    
    while(getline(cin,tmp)){
        list<char> bj;
        list<char>::iterator itr = bj.begin();
        for(int i=0;i<tmp.length();i++){
            if(tmp[i] == '['){
                itr = bj.begin();
            }
            else if(tmp[i] == ']'){
                itr = bj.end();
            }
            else{
                bj.insert(itr,tmp[i]);
            }
        }
        bj.push_back('\n');
        show_list(bj);
        //cout << '\n';
        
    }
    
    
}