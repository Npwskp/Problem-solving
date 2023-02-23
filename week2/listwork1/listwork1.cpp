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
        char tmp1;
        cin >> tmp1 >> tmp2;
        if(tmp1 == 'I'){
            x.push_front(tmp2);
        }
        else if(tmp1 == 'D' && tmp2 <= x.size()){
            list<int>::iterator ii = x.begin();
            tmp2 = tmp2-1;
            advance(ii,tmp2);
            x.erase(ii);
        }
    }
    show_list(x);
}   