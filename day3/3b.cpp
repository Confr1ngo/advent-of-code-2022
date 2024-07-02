#include<bits/stdc++.h>
using namespace std;
string str1,str2,str3;
int cnt;
int compare(string a,string b,string c){
	for (char i='a';i<='z';i++){
		if (a.find(i)!=string::npos && b.find(i)!=string::npos && c.find(i)!=string::npos){
			return i-'a'+1;
		}
	}
	for (char i='A';i<='Z';i++){
		if (a.find(i)!=string::npos && b.find(i)!=string::npos && c.find(i)!=string::npos){
			return i-'A'+27;
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	while (true){
		getline(cin,str1);
		if (str1=="") break;
		getline(cin,str2);
		getline(cin,str3);
		cnt+=compare(str1,str2,str3);
	}
	cout<<cnt<<endl;
	return 0;
}