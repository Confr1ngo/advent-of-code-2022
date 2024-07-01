#include<bits/stdc++.h>
using namespace std;
int ans=0,now=0;
string str;
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str==""){
			ans=max(ans,now);
			now=0;
		}
		else{
			stringstream ss(str);
			int temp;ss>>temp;
			now+=temp;
		}
	}
	cout<<ans<<endl;
	return 0;
}