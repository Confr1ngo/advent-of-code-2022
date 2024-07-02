#include<bits/stdc++.h>
using namespace std;
string str;
int cnt;
int str2int(string s){
	int res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		static int num1,num2,num3,num4;
		if (str=="") break;
		num1=str2int(str.substr(0,str.find('-')));
		str.erase(0,str.find('-')+1);
		num2=str2int(str.substr(0,str.find(',')));
		str.erase(0,str.find(',')+1);
		num3=str2int(str.substr(0,str.find('-')));
		str.erase(0,str.find('-')+1);
		num4=str2int(str);
		if (num1<=num3 && num4<=num2) cnt++;
		else if (num3<=num1 && num2<=num4) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}