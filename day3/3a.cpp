#include<bits/stdc++.h>
using namespace std;
string str;
int cnt;
int compare(string a,string b){
	for (char c='a';c<='z';c++){
		if (a.find(c)!=string::npos && b.find(c)!=string::npos){
			return c-'a'+1;
		}
	}
	for (char c='A';c<='Z';c++){
		if (a.find(c)!=string::npos && b.find(c)!=string::npos){
			return c-'A'+27;
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		cnt+=compare(str.substr(0,str.size()>>1),str.substr(str.size()>>1));
	}
	cout<<cnt<<endl;
	return 0;
}