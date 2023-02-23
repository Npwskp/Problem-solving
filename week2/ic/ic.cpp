#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void show_list(list<int> x){
    for(list<int>::iterator i=x.begin(); i!=x.end(); i++){
        cout << *i << endl;
    }
}

int main(){
    int n,i;
    cin >> n;
    list<int> x;
    for (i = 0 ; i < n ; i++){
        int tmp2;
        string tmp1;
        cin >> tmp1;
        if(tmp1 == "li" || tmp1 == "ri"){
            cin >> tmp2;
        }
        //cout << i << endl;
        if(tmp1 == "li"){
            x.push_front(tmp2);
        }
        else if(tmp1 == "ri"){
            x.push_back(tmp2);
        }
        else if(tmp1 == "lr"){
            int rote;
            rote = x.front();
            //cout << rote;
            x.push_back(rote);
            x.pop_front();
        }
        else if(tmp1 == "rr"){
            int rote;
            rote = x.back();
            //cout << rote;
            x.push_front(rote);
            x.pop_back();
        }
    }
    show_list(x);
}

