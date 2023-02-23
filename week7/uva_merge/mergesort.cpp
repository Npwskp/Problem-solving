#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int start,int mid,int end){
    int s1 = mid - start + 1;
    int s2 = end - mid;

    int left_a[s1],right_a[s2];
    for(int i=0;i<s1;i++){
        left_a[i] = arr[start+i];
    }
    for(int i=0;i<s2;i++){
        right_a[i] = arr[mid+1+i];
    }

    int i=0,j=0;

    while(i < s1 && j < s2){
        if(left_a[i] <= right_a[j]){
            arr[start] = left_a[i];
            i++;
        }
        else {
            arr[start] = right_a[j];
            j++;
        }
        start++;
    }

    while(i<s1){
        arr[start++] = left_a[i++];
    }
    while(j<s2){
        arr[start++] = right_a[j++];
    }

}

void Mergesort(int arr[],int start,int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    Mergesort(arr,start,mid);
    Mergesort(arr,mid+1,end);
    Merge(arr,start,mid,end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (1)
    {   
        cin >> n;
        if(n == 0) return 0;
        int arr[n+1];
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            arr[i] = tmp;
        }
        Mergesort(arr,0,n-1);
        for(int i=0;i<n;i++){
            if(i == n-1) cout << arr[i];
            else cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    
}