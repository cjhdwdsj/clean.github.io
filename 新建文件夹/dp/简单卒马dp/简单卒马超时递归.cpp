#include<cstdio>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;
void print();void st(int x1,int y1);
int p[26][26];
long long x,y,mx,my,bx,by,ans;
int main(){
	cin>>x>>y>>mx>>my;
	for(int i=0;i<=y;i++)p[x+1][i]=1;
	for(int i=0;i<=x;i++)p[i][y+1]=1;
	p[mx][my]=1;p[mx-2][my-1]=1;p[mx-1][my-2]=1;p[mx-1][my+2]=1;p[mx-2][my+1]=1;p[mx+1][my-2]=1;p[mx+2][my-1]=1;p[mx+1][my+2]=1;p[mx+2][my+1]=1;
	st(0,0);
	//print();
	//freopen("out.out","w",stdout);
	cout<<ans;
	return 0;
}
void st(int x1,int y1){
	//cout<<x1<<','<<y1<<" > ";
	if(p[x1+1][y1]==0)st(x1+1,y1);
	if(p[x1][y1+1]==0)st(x1,y1+1);
	if(x1==x){
		if(y1==y){
			ans++;
			//cout<<"  ok  "<<endl;
		}
	}
}
void print(){
	for(int i=0;i<=25;i++){
		for(int j=0;j<=25;j++){
			cout<<p[i][j]<<' ';
		}
		cout<<endl;
	} 
}