#include<iostream>
using namespace std;
int yin[52][1002],n,maxn,y[52];
int main(){
    cin>>n>>y[0]>>maxn;
    yin[0][y[0]]=1;
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    for(int i=1;i<=n;i++){
		for(int j=0;j<=maxn;j++){
			if(j+y[i]<=maxn)yin[i][j]=yin[i][j]||yin[i-1][j+y[i]];
			if(j-y[i]>=0)yin[i][j]=yin[i][j]||yin[i-1][j-y[i]];
		}
	}
    for(int i=maxn;i>=0;i--)
        if(yin[n][i]==1){
            cout<<i;
            return 0;
        }
    cout<<"-1";
	cin>>y[0];
    return 0;
}