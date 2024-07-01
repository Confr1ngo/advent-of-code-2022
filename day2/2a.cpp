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
int calcscore(char a,char b){
	int typea=type(a),typeb=type(b);
	if (typea==typeb) return 3+typea;
	if (typea==1 && typeb==2) return typea;
	if (typea==2 && typeb==3) return typea;
	if (typea==3 && typeb==1) return typea;
	return 6+typea;
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		score+=calcscore(str[2],str[0]);
	}
	cout<<score<<endl;
	return 0;
}