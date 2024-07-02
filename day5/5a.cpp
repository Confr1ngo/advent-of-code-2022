#include<bits/stdc++.h>
using namespace std;
vector<char>stk[10];
string str;
int str2int(string s){
	int res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
int main(){
	freopen("input.txt","r",stdin);
	for (int i=1;i<=8;i++){
		getline(cin,str);
		for (int j=1;j<=9;j++){
			if (str[4*j-3]!=' ') stk[j].insert(stk[j].begin(),str[4*j-3]);
		}
	}
	getline(cin,str);
	getline(cin,str);
	while (getline(cin,str)){
		if (str=="") break;
		str.erase(0,5);
		int cnt=str2int(str.substr(0,str.find(" ")));
		str.erase(0,str.find("m")+2);
		int from=str2int(str.substr(0,str.find(" ")));
		str.erase(0,str.find("o")+2);
		int to=str2int(str);
		while (cnt--){
			stk[to].emplace_back(stk[from].back());
			stk[from].pop_back();
		}
	}
	for (int i=1;i<=9;i++){
		cout<<stk[i].back();
	}
	cout<<endl;
	return 0;
}