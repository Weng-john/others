#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, **arr;
    while(cin >> k){
        arr= new int*[k];
        for(int i=0;i<k;i++){
            arr[i]= new int[k];
            for(int j=0;j<k;j++)
                cin >> arr[i][j];
            sort(arr[i], arr[i]+k);
        }

        for(int i=0;i<k;i++){
            
        }

        for(int i=0;i<k;i++)
            delete [] arr[i];
        delete [] arr;
    }
    return 0;
}