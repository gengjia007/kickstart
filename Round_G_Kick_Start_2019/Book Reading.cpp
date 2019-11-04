#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
typedef long long ll;
using namespace std;
int main(){
    int num = 0;
    cin>>num;
    for(ll i=0;i<num;i++){
        unordered_map<ll,ll> map;
        int N,M,Q=0;
        cin>>N>>M>>Q;
        vector<ll> MP;
        vector<ll> QP;
        for(ll j=0;j<M;j++){
            ll temp = 0;
            cin>>temp;
            for(ll z=1;z<=floor(sqrt(temp));z++){
                if(temp%z==0){
                    if(map.find(z)==map.end()){
                        map[z] = 0;
                    }
                    if(map.find(temp/z)==map.end()){
                        map[temp/z] = 0;
                    }
                    map[z]--;
                    if(z != temp/z) map[temp/z]--;
                }
            }
            MP.push_back(temp);
        }
        for(int j=0;j<Q;j++){
            ll temp = 0;
            cin>>temp;
            QP.push_back(temp);
        }
        //process the task
        ll total = 0;
        for(int j=0;j<Q;j++){
            ll page = N / QP[j] + map[QP[j]];
            if(page<0) page=0;
            total += page;
        }
        cout<<"Case #"<<i+1<<": "<<total<<endl;
    }
    return 0;
}