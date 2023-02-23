#include<iostream> 
#include<list>
using namespace std;

void show_list(list<int> x){
    for(list<int>::iterator i=x.begin(); i!=x.end(); i++){
        cout << *i << endl;
    }
}

int main(){
    list<int> marr[100005];
    int n,i,max = -9999;
    cin >> n ;
    for (i=0;i<n;i++){
        char activity;
        int num1,num2;
        cin >> activity >> num1 >> num2;
        if(activity == 'N'){
            marr[num2].push_back(num1);
        }
        else if(activity == 'M'){
            list<int>::iterator ii = marr[num2].end();
            marr[num2].splice(ii,marr[num1]);
        }
    }
    for(i=0;i<100005;i++){
        show_list(marr[i]);
    }
}