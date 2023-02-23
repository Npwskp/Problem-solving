#include<iostream>
#include<vector>
using namespace std;

int com_to_num(char x){
    if(x == 'N')
        return 1;
    else if(x == 'E')
        return 2;
    else if(x == 'S')
        return 3;
    else if(x == 'W')
        return 4;   
}

int main(){
    string command;
    cin >> command;
    int len = command.length();
    int current_st = 1;
    vector<char> ans;
    //int x = 0,y = 0;
    for(int i=0;i<len;i++){
        if(command[i] == 'Z'){
            ans.push_back('Z');
            current_st = 1;
            continue;
        }
        int tmp = com_to_num(command[i]);
        //cout << command[i] <<tmp << endl;
        while(current_st != tmp){
            current_st++;
            ans.push_back('R');
            if(current_st >= 5){
                current_st = 1;
            }
        }
        ans.push_back('F');
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
}