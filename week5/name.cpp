#include<bits/stdc++.h>
using namespace std;

string name,data;


int main(){
    cin >> name >> data;
    int ni=0,di=0,ns=name.length(),ds=data.length();
    int count = 0;
    while(di < ds){
        if(name[ni] == data[di])
            ni++;
        if(ni == ns){
            ni = 0;
            count+=1;
        }
        di++;
    }
    cout << count;
}