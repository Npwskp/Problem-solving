#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,M,L,R,current;

void minimalCoverage(){
    vector<pair<int,int>> node;
    vector<pair<int,int>> answer;
    cin >> M;

    while(true){
        cin >> L >> R;
        if(L==0 && R==0) break;
        if(R <= 0 || L >= M) continue;

        node.push_back({L,R});
    }
    sort(node.begin(),node.end());

    current = 0;
    pair<int,int> select;
    select.first = 0;
    select.second = 0;
     
    int i=0;
    while(current < M && i < node.size()){
        select.first = 0;
        select.second = 0;
        while(node[i].first <= current){
            if(node[i].second > select.second){
                select.first = node[i].first;
                select.second = node[i].second;
            }
            i++;
        }
        if(select.second == current) break;
        current = select.second;
        answer.push_back(select);
    }
    if(current >= M){
        cout << answer.size() << "\n";
        for(int i=0;i<answer.size();i++){
            cout << answer[i].first << " " << answer[i].second << "\n";
        }
    }
    else{
        cout << "0\n";
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        minimalCoverage();
        cout << "\n";
    }
}
