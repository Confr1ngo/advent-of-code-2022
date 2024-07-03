#include<bits/stdc++.h>
using namespace std;
int mp[50][200],stp[50][200],n,m;
int startx,starty,endx,endy;
string str;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};
int main(){
	memset(stp,0x3f,sizeof(stp));
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		m=str.size();
		n++;
		for (int i=1;i<=m;i++){
			if (str[i-1]=='S') startx=n,starty=i,mp[n][i]=0;
			else if (str[i-1]=='E') endx=n,endy=i,mp[n][i]=25;
			else mp[n][i]=str[i-1]-'a';
		}
	}
	queue<tuple<int,int,int>>q;
	q.emplace(startx,starty,0);
	stp[startx][starty]=0;
	while (!q.empty()){
		auto now=q.front();q.pop();
		if (get<2>(now)>stp[get<0>(now)][get<1>(now)]) continue;
		for (int i=0;i<4;i++){
			int newx=get<0>(now)+dx[i];
			int newy=get<1>(now)+dy[i];
			if (newx<1 || newy<1 || newx>n || newy>m) continue;
			if (mp[newx][newy]>mp[get<0>(now)][get<1>(now)]+1) continue;
			if (stp[newx][newy]!=0x3f3f3f3f) continue;
			stp[newx][newy]=get<2>(now)+1;
			q.emplace(newx,newy,stp[newx][newy]);
		}
	}
	cout<<stp[endx][endy]<<endl;
	return 0;
}