#include<cstdio>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;
void print();void st(int x1,int y1);
long long p[26][26],a[26][26];
int x,y,mx,my,bx,by,ans;
int main(){
	cin>>x>>y>>mx>>my;
	x++;y++;mx++;my++;
	for(int i=0;i<=y;i++)p[x+1][i]=1;
	for(int i=0;i<=x;i++)p[i][y+1]=1;
	p[mx][my]=1;p[mx-2][my-1]=1;p[mx-1][my-2]=1;p[mx-1][my+2]=1;p[mx-2][my+1]=1;p[mx+1][my-2]=1;p[mx+2][my-1]=1;p[mx+1][my+2]=1;p[mx+2][my+1]=1;
	a[1][1]=1;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			if(p[i][j]!=1)
				a[i][j]=max(a[i-1][j]+a[i][j-1],a[i][j]);
	//st(0,0);
	//freopen("out.out","w",stdout);
	//print();
	cout<<a[x][y];
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
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	} 
}