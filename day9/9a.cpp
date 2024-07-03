#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>>s;
int headx,heady,tailx,taily;
string str;
int str2int(string s){
	int res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
void tailkeepup(){
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
			headx+=dx;
			heady+=dy;
			tailkeepup();
			s.emplace(tailx,taily);
		}
	}
	cout<<s.size()<<endl;
	return 0;
}