#include<iostream>
#include<list>
using namespace std;

void show_list(list<int> x){
    for(auto i=x.begin(); i!=x.end(); i++){
        cout << *i << " ";
    }
}

list<int>::iterator search(list<int> marr[100005],int n,int num){
    list<int>::iterator ans_itr = marr[0].begin();
    for(int i=1;i<=n;i++){
        auto itr = marr[i].begin();
        if(*itr == num)
            return itr;
        while(*itr != num && itr != marr[i].end())
            itr++;
        if(*itr == num)
            ans_itr = itr;
    }
    return ans_itr;
}

int head(list<int> marr[100005],int n,int num){
    for(int i=1;i<=n;i++){
        auto itr = marr[i].begin();
        while(*itr != num && itr != marr[i].end())
            itr++;
        if(*itr == num)
            return i;
    }
}

int main(){
    list<int> marr[100005];
    int n;
    cin >> n;
    marr[0].push_back(-1);
    for(int i=1;i<=n;i++){
        marr[i].push_back(i);
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        int h = head(marr,n,y);
        list<int>::iterator ii = search(marr,n,y);
        ii++;
        marr[h].splice(ii,marr[x]);
        
        //show_list(marr[h]);
        //cout << "\n";
        
    }
    for(int i=1;i<=n;i++)
        show_list(marr[i]);
}

//welp fuc it

