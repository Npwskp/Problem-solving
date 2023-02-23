#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> N;
    while(1){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            break;
        }
        N.push_back(tmp);
    }   
    int len = N.size();
    list<int>::iterator itr = N.begin();
    for(int i=0;i<len;i++){
        list<int> out;
        list<int> remain;
        int n = *itr;
        for(int j=0;j<n;j++){
            remain.push_back(j+1);
        }
        int k = 1;
        while(remain.size() > 1){
            if(k%2 == 1){
                out.push_back(remain.front());
                remain.pop_front();
            }
            else if(k%2 == 0){
                remain.push_back(remain.front());
                remain.pop_front();
            }
            k++;
        }
        cout << "Discarded cards:";
        for(list<int>::iterator ii=out.begin(); ii!=(--out.end()); ii++){
            cout << " " << *ii << ",";
        }
        if(out.size()>=1){
            list<int>::iterator ii= --out.end();
            cout << " " << *ii << endl;
        }
        else
            cout << endl;
        list<int>::iterator ir= remain.begin();
        cout << "Remaining card: " << *ir << endl;
        itr++;
    }
}