#include<bits/stdc++.h>
using namespace std;
string str;
int score;
int type(char c){
	if (c=='A' || c=='X') return 1;
	if (c=='B' || c=='Y') return 2;
	if (c=='C' || c=='Z') return 3;
	assert(!!"Impossible");
}
int restype(char c){
	if (c=='X') return 0;
	if (c=='Y') return 3;
	if (c=='Z') return 6;
	assert(!!"Impossible");
}
int getresult(int typea,int typeb){
	if (typea==typeb) return 3;
	if (typea==1 && typeb==2) return 0;
	if (typea==2 && typeb==3) return 0;
	if (typea==3 && typeb==1) return 0;
	return 6;
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		if (getresult(1,type(str[0]))==restype(str[2])) score+=(1+restype(str[2]));
		if (getresult(2,type(str[0]))==restype(str[2])) score+=(2+restype(str[2]));
		if (getresult(3,type(str[0]))==restype(str[2])) score+=(3+restype(str[2]));
	}
	cout<<score<<endl;
	return 0;
}