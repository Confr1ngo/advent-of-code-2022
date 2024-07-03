#include<bits/stdc++.h>
using namespace std;
int trees[110][110],ans,n,m;
string str;
bool checkdir(int x,int y,int dx,int dy){
	int maxheight=trees[x][y]-1;
	x+=dx;y+=dy;
	while (x>=1 && x<=n && y>=1 && y<=m){
		if (trees[x][y]>maxheight) return false;
		x+=dx;y+=dy;
	}
	return true;
}
bool check(int x,int y){
	if (checkdir(x,y,0,1)) return true;
	if (checkdir(x,y,0,-1)) return true;
	if (checkdir(x,y,1,0)) return true;
	if (checkdir(x,y,-1,0)) return true;
	return false;
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
			if (check(i,j)) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}