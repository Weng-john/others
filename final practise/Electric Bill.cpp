#include <bits/stdc++.h>

using namespace std;

int a, b;
const int price[4]= {2, 3, 5, 7};
const int range[3]= {100, 9900, 990000};

int bill_to_wat(int bill){
    int level=0, ttWat=0;
    while(range[level]*price[level]<bill){
        bill -= range[level]*price[level];
        ttWat += range[level++];
    }
    ttWat += (bill/price[level]);
    return ttWat;
}

int wat_to_bill(int wat){
    int level=0, bill=0;
    while(wat>range[level]){
        bill += (range[level]*price[level]);
        wat -= range[level++];
    }
    bill += (wat*price[level]);
    return bill;
}

int find_less_wat(int cwTotal, int difBill){
    int ans;
    int L= 0, R= cwTotal;
    while(L<=R){
        int mid= (L+R)/2;
        int nowDif= abs(wat_to_bill(mid)-wat_to_bill(R-mid));
        if(difBill==nowDif){
            ans= mid;
            break;
        }
        if(difBill<nowDif)
            L= mid+1;
        else
            R= mid;
    }
    return ans;
}

int main(){
    while(cin >> a >> b && (a&&b)){
        int cwTotal= bill_to_wat(a);
        int myWat= find_less_wat(cwTotal, b);
        cout << wat_to_bill(myWat) << endl;
    }
    return 0;
}