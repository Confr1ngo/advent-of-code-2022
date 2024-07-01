#include<bits/stdc++.h>
using namespace std;
vector<int>totals;
int now=0;
string str;
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str==""){
			totals.emplace_back(now);
			now=0;
		}
		else{
			stringstream ss(str);
			int temp;ss>>temp;
			now+=temp;
		}
	}
	sort(totals.begin(),totals.end(),greater<int>());
	cout<<totals[0]+totals[1]+totals[2]<<endl;
	return 0;
}