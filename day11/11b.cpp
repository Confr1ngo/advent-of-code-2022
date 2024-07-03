// I think this code is self-adaptive.
#include<bits/stdc++.h>
using namespace std;
long long eval(string s){
	if (s[0]=='-') s="0"+s;
	stack<long long>num;
	stack<char>op;
	map<char,long long>prio;
	prio['+']=1;
	prio['-']=1;
	prio['*']=2;
	prio['/']=2;
	prio['(']=0;
	prio[')']=0;
	long long i=0;
	while (i<(long long)s.size()){
		if (s[i]>='0' && s[i]<='9'){
			long long sum=0;
			while (s[i]>='0' && s[i]<='9'){
				sum=sum*10+(s[i]-'0');
				i++;
			}
			num.push(sum);
		}
		else{
			if (s[i]=='(') op.push(s[i]);
			else if (s[i]==')'){
				while (op.size() && op.top()!='('){
					char op_now=op.top();op.pop();
					long long b=num.top();num.pop();
					long long a=num.top();num.pop();
					if (op_now=='+') num.push(a+b);
					else if (op_now=='-') num.push(a-b);
					else if (op_now=='*') num.push(a*b);
					else if (op_now=='/') num.push(a/b);
					else assert(!"Invalid operator!");
				}
				op.pop();
			}
			else{
				while (op.size() && prio[op.top()]>=prio[s[i]]){
					char op_now=op.top();op.pop();
					long long b=num.top();num.pop();
					long long a=num.top();num.pop();
					if (op_now=='+') num.push(a+b);
					else if (op_now=='-') num.push(a-b);
					else if (op_now=='*') num.push(a*b);
					else if (op_now=='/') num.push(a/b);
					else assert(!"Invalid operator!");
				}
				op.push(s[i]);
			}
			i++;
		}
	}
	while (op.size()){
		char op_now=op.top();op.pop();
		long long b=num.top();num.pop();
		long long a=num.top();num.pop();
		if (op_now=='+') num.push(a+b);
		else if (op_now=='-') num.push(a-b);
		else if (op_now=='*') num.push(a*b);
		else if (op_now=='/') num.push(a/b);
		else assert(!"Invalid operator!");
	}
	return num.top();
}
long long str2int(string s){
	long long res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
struct Monkey{
	long long cond,trueop,falseop,inspectcnt;
	vector<long long>items;
	string op;
}monkeys[110];
long long currentid,mod=1;
string str;
void inspect(long long id){
	for (long long i:monkeys[id].items){
		monkeys[id].inspectcnt++;
		string newop=monkeys[id].op;
		while (newop.find("old")!=string::npos){
			newop.replace(newop.find("old"),3,to_string(i));
		}
		i=eval(newop)%mod;
		if (i%monkeys[id].cond==0) monkeys[monkeys[id].trueop].items.emplace_back(i);
		else monkeys[monkeys[id].falseop].items.emplace_back(i);
	}
	monkeys[id].items.clear();
}
long long lcm(long long a,long long b){
	return a/__gcd(a,b)*b;
}
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str.size()>6 && str.substr(0,6)=="Monkey"){
			// starting items
			getline(cin,str);
			str.erase(0,str.find(":")+2);
			while (str.find(",")!=string::npos){
				monkeys[currentid].items.emplace_back(str2int(str.substr(0,str.find(","))));
				str.erase(0,str.find(",")+2);
			}
			monkeys[currentid].items.emplace_back(str2int(str));
			// operation
			getline(cin,str);
			str.erase(0,str.find("=")+2);
			while (str.find(" ")!=string::npos) str.erase(str.find(" "),1);
			monkeys[currentid].op=str;
			// test
			getline(cin,str);
			str.erase(0,str.find("by")+3);
			monkeys[currentid].cond=str2int(str);
			mod=lcm(mod,monkeys[currentid].cond);
			// true
			getline(cin,str);
			str.erase(0,str.find("monkey")+7);
			monkeys[currentid].trueop=str2int(str);
			// false
			getline(cin,str);
			str.erase(0,str.find("monkey")+7);
			monkeys[currentid].falseop=str2int(str);
			currentid++;
		}
	}
	for (long long i=1;i<=10000;i++){
		for (long long j=0;j<currentid;j++){
			inspect(j);
		}
	}
	long long maxn=0,maxn2=0;
	for (long long i=0;i<currentid;i++){
		if (monkeys[i].inspectcnt>maxn){
			maxn2=maxn;
			maxn=monkeys[i].inspectcnt;
		}
		else if (monkeys[i].inspectcnt>maxn2) maxn2=monkeys[i].inspectcnt;
	}
	cout<<maxn*maxn2<<endl;
	return 0;
}