#include<bits/stdc++.h>
using namespace std;
int trees[110][110],ans,n,m;
string str;
int countdir(int x,int y,int dx,int dy){
	int maxheight=trees[x][y]-1,num=0;
	x+=dx;y+=dy;
	while (x>=1 && x<=n && y>=1 && y<=m){
		if (trees[x][y]>maxheight) return num+1;
		x+=dx;y+=dy;num++;
	}
	return num;
}
int calc(int x,int y){
	return countdir(x,y,0,1)*countdir(x,y,0,-1)*countdir(x,y,1,0)*countdir(x,y,-1,0);
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		n++;
		m=str.size();
		int pos=1;
		for (char i:str){
			trees[n][pos]=i-'0';
			pos++;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			ans=max(ans,calc(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
}