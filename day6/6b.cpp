#include<bits/stdc++.h>
using namespace std;
string a;
int cnt[256];
bool check(string s){
	memset(cnt,0,sizeof(cnt));
	for (char i:s){
		cnt[i]++;
		if (cnt[i]>1) return false;
	}
	return true;
}
int main(){
	freopen("input.txt","r",stdin);
	getline(cin,a);
	for (int i=0;;i++){
		if (check(a.substr(i,14))){
			cout<<i+14<<endl;
			return 0;
		}
	}
	return 0;
}