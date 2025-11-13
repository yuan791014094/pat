#include "iostream"
#include "map"
#include "cstdio"
using namespace std;

int main(){
    int k,a;
    double num;
    map<int,double> m;

    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>num;
        m[a]+=num;
    }

    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>num;
        m[a]+=num;
        if(m[a]==0){
            m.erase(a);
        }
    }

    cout<<m.size();
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        printf(" %d %.1f",it->first,it->second);
    }
}