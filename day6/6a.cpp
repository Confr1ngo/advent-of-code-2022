#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("input.txt","r",stdin);
	getline(cin,a);
	for (int i=0;;i++){
		if (a[i]!=a[i+1] && a[i]!=a[i+2] && a[i]!=a[i+3] && a[i+1]!=a[i+2] && a[i+2]!=a[i+3] && a[i+1]!=a[i+3]){
			cout<<i+4<<endl;
			return 0;
		}
	}
	return 0;
}