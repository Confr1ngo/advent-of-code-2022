#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>>s;
int knotx[10],knoty[10];
string str;
int str2int(string s){
	int res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
void tailkeepup(int id){
	int &headx=knotx[id-1],&heady=knoty[id-1],&tailx=knotx[id],&taily=knoty[id];
	if (abs(headx-tailx)<=1 && abs(heady-taily)<=1) return;
	if (headx==tailx){
		if (heady>taily) taily++;
		else taily--;
	}
	else if (heady==taily){
		if (headx>tailx) tailx++;
		else tailx--;
	}
	else{
		if (headx>tailx && heady>taily) tailx++,taily++;
		else if (headx>tailx) tailx++,taily--;
		else if (heady>taily) tailx--,taily++;
		else tailx--,taily--;
	}
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		char dir=str[0];
		int len=str2int(str.substr(2)),dx,dy;
		if (dir=='R') dx=1,dy=0;
		else if (dir=='L') dx=-1,dy=0;
		else if (dir=='U') dx=0,dy=1;
		else dx=0,dy=-1;
		while (len--){
			knotx[0]+=dx;
			knoty[0]+=dy;
			for (int i=1;i<=9;i++) tailkeepup(i);
			s.emplace(knotx[9],knoty[9]);
		}
	}
	cout<<s.size()<<endl;
	return 0;
}