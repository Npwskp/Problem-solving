#include<bits/stdc++.h>
using namespace std;

int n,m;


int main(){
    cin >> n >> m;
    int cost[n],price[n],weight[n],package[m];
    for(int i=0;i<n;i++){
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        cost[i] = tmp1;
        price[i] = tmp2;
        weight[i] = tmp3;
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        package[i] = tmp;
    }
    int car[n],count  = 0;
    for(int i=0;i<n;i++){
        car[i] = 0;
        count = 0;
        for(int j=0;j<m;j++){
            count+=package[j];
            if(package[j]>weight[i]){
                car[i] = 0;
                count = 0;
                break;
            }
            if(count > weight[i]){
                j--;
                count = 0;
                car[i]+=1;
            }
            //cout << count << " " << weight[i] << " " << car[i] << "\n";
        }
        if(count > 0){
            car[i] += 1;
        }
        //cout << last << "\n";
    }
    int minn = 9999999;
    for(int i=0;i<n;i++){
        if(car[i] == 0) continue;
        int P = cost[i] + (price[i]*car[i]);
        if(P < minn) minn = P;
    }
    /*for(int i=0;i<n;i++){
        cout << car[i] << " " << weight[i] << "\n";
    }*/

    cout << minn;
    
}