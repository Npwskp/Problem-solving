#include <bits/stdc++.h>
using namespace std;

int check(list<int> calculate,int n){
    stack<int> stax;
    list<int> tmp;
    for(int i = 0;i < n;i++){
        tmp.push_back(i+1);
    }
    auto itr_t = tmp.begin();
    for(auto itr = calculate.begin();
    itr != calculate.end();itr++){
        if(stax.empty()){
            stax.push(*itr_t);
            itr_t++;
        }
        //if(*itr_c != stax.top()){
            
        while(*itr != stax.top()){
            if(itr_t != tmp.end()){
                stax.push(*itr_t);
                itr_t++;
            }
            else{
                return 0;
            }
        }
        //}
        //else if(*itr_c == stax.top()){
        stax.pop();
        //}
    }
    return 1;
}

int main(){
    list<string> ans;
    while(1){
        int n;
        cin >> n;
        if(n != 0){
            int i = 0;
            list<int> calculate;
            while(1){
                if(i == n){
                    int ch = check(calculate,n);
                    if(ch == 1){
                        ans.push_back("Yes");
                    }
                    else if(ch == 0){
                        ans.push_back("No");
                    }
                    i = 0;
                    calculate.clear();
                }
                int tmp;
                cin >> tmp;
                if(tmp == 0){
                    ans.push_back("");
                    break;
                }
                calculate.push_back(tmp);
                i++;
            }
        }
        else{
            break;
        }
    }
    for(auto itr = ans.begin();
    itr != ans.end();itr++){
        cout << *itr << endl;
    }
}
