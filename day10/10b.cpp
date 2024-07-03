#include<bits/stdc++.h>
using namespace std;
int cyc=0,strength[500]={1},ans;
string str;
int str2int(string s){
	if (s[0]=='-') return -str2int(s.substr(1));
	int res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		if (str=="noop"){
			strength[cyc+1]=strength[cyc];
			cyc++;
		}
		else{
			int delta=str2int(str.substr(5));
			strength[cyc+1]=strength[cyc];
			strength[cyc+2]=strength[cyc]+delta;
			cyc+=2;
		}
	}
	for (int i=1;i<=6;i++){
		for (int j=0;j<=40;j++){
			if (j==0 || abs(strength[i*40-40+j]-j)<=1) cout<<"#";
			else cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}