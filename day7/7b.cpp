#include<bits/stdc++.h>
using namespace std;
int ans;
string str;
int str2int(string s){
	int res=0;
	for (char c:s){
		res=res*10+(c-'0');
	}
	return res;
}
struct File{
	string name;
	int size;
	File():name(""),size(0){}
	File(string names,int sizei):name(names),size(sizei){}
};
struct Node{
	int father;
	vector<int>son;
	vector<File>files;
	Node():father(0){}
}node[10010];
int count_size(int id){
	int res=0;
	for (auto i:node[id].files){
		res+=i.size;
	}
	for (int i:node[id].son){
		res+=count_size(i);
	}
	return res;
}
vector<string>info;
string current_dir="/";
int current_dir_id=0,lastunused=1;
map<string,int>dir_map;
set<int>listed;
int main(){
	freopen("input.txt","r",stdin);
	while (getline(cin,str)){
		if (str=="") break;
		info.emplace_back(str);
	}
	dir_map["/"]=0;
	for (int i=0;i<(int)info.size();i++){
		if (info[i]=="$ cd .."){
			if (current_dir=="/") continue;
			current_dir.pop_back();
			while (current_dir.back()!='/') current_dir.pop_back();
			current_dir_id=dir_map[current_dir];
		}
		else if (info[i]=="$ cd /"){
			current_dir="/";
			current_dir_id=0;
		}
		else if (info[i].substr(0,4)=="$ cd"){
			info[i].erase(0,5);
			current_dir=current_dir+info[i]+"/";
			current_dir_id=dir_map[current_dir];
		}
		else{
			if (listed.count(current_dir_id)){
				while (i+1<info.size() && info[i+1][0]!='$') i++;
				continue;
			}
			listed.emplace(current_dir_id);
			while (i+1<info.size() && info[i+1][0]!='$'){
				i++;
				if (info[i][0]=='d'){
					info[i].erase(0,4);
					int newid=(dir_map[current_dir+info[i]+"/"]=lastunused++);
					node[newid].father=current_dir_id;
					node[current_dir_id].son.emplace_back(newid);
				}
				else{
					File temp(info[i].substr(info[i].find(" ")+1),str2int(info[i].substr(0,info[i].find(" "))));
					node[current_dir_id].files.emplace_back(temp);
				}
			}
		}
	}
	int sizeneeded=30000000-(70000000-count_size(0));
	int ans=count_size(0);
	for (int i=1;i<lastunused;i++){
		int sz=count_size(i);
		if (sz>=sizeneeded && sz<ans) ans=sz;
	}
	cout<<ans<<endl;
	return 0;
}