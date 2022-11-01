#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

int N,now=0,endN=1;

typedef struct album{ // tree 구조체
	string name="";
	map<string, int> photo;
	map<string, int> ALBUM;
}album;
album alb[100001]; //alb[0]=album

typedef struct deletedN{ // rmalb 명령시 삭제된 앨범, 사진 개수 count용 구조체
	int PhotoN=0;
	int AlbumN=0;
}deletedN;

stack<int> visit; // 방문한 폴더 idx

void mkalb(string S){// alb[now]에 S앨범 조회
	if(alb[now].ALBUM.find(S)!=alb[now].ALBUM.end()) // 있다면 "~" 출력
		cout<<"duplicated album name\n";
	else{ // 없다면 alb[now].ALBUM에 현재 마지막 배열 index에 추가
		alb[now].ALBUM.insert({S,endN});
		alb[endN].name=S;
		endN++; // 마지막 배열 index ++
	}
}

void initAlbum(int n){ // alb[n] 초기화(삭제)
	alb[n].name="";
	alb[n].photo.clear();
	alb[n].ALBUM.clear();
}

deletedN dalb(int n){ // alb[n]번 삭제
	deletedN dN, tmp;
	if(alb[n].name!=""){//현재 앨범이 존재한다면
		for(auto iter = alb[n].ALBUM.begin(); iter != alb[n].ALBUM.end(); iter++){// 앨범에 존재하는 앨범의 개수만큼 앨범 삭제
			tmp=dalb(iter->second);
			dN.PhotoN+=tmp.PhotoN;
			dN.AlbumN+=tmp.AlbumN;
		}
		dN.PhotoN+=alb[n].photo.size();//현재 앨범의 사진 개수
		dN.AlbumN+=alb[n].ALBUM.size();//현재 앨범의 앨범 개수
	}
	initAlbum(n);
	return dN;
}

void rmalb(string S){// alb[now]에 S앨범 조회
	deletedN dN, tmp;
	if(S=="-1"){
		if(!alb[now].ALBUM.empty()){
			map<string, int>::iterator it = alb[now].ALBUM.begin();
			dN=dalb(it->second);
			dN.AlbumN++;
			alb[now].ALBUM.erase(alb[now].ALBUM.begin());
		}
	}
	else if(S=="0"){
		for(auto iter = alb[now].ALBUM.begin(); iter != alb[now].ALBUM.end(); iter++){
			
			if(alb[iter->second].name!="") dN.AlbumN++;
			tmp=dalb(iter->second);
			dN.PhotoN+=tmp.PhotoN;
			dN.AlbumN+=tmp.AlbumN;
		}
		alb[now].ALBUM.erase(alb[now].ALBUM.begin());
		alb[now].ALBUM.clear();
	}
	else if(S=="1"){
		if(!alb[now].ALBUM.empty()){
			map<string, int>::iterator it = --alb[now].ALBUM.end();
			dN=dalb(it->second);
			dN.AlbumN++;
			alb[now].ALBUM.erase(--alb[now].ALBUM.end());
		}
	}
	else{
		if(alb[now].ALBUM.find(S)!=alb[now].ALBUM.end()){ // 있다면 해당 앨범 삭제
			dN=dalb(alb[now].ALBUM[S]); // dalb(현재 앨범안의 'S'앨범 idx)+현재앨범개수(1개) 
			dN.AlbumN++;
			alb[now].ALBUM.erase(S);
		}
	}
	cout<<dN.AlbumN<<' '<<dN.PhotoN<<'\n';
}

void ins(string S){
	if(alb[now].photo.find(S)!=alb[now].photo.end()) // 있다면 "~" 출력
		cout<<"duplicated photo name\n";
	else{ // 없다면 alb[now].photo에 추가
		alb[now].photo.insert({S,0});
	}	
}
						 
void del(string S){// alb[now]에 S앨범 조회
	int delPhoto=0;
	if(S=="-1"){
		if(!alb[now].photo.empty()){
			alb[now].photo.erase(alb[now].photo.begin());
			delPhoto++;
		}
	}
	else if(S=="0"){
		delPhoto=alb[now].photo.size();
		alb[now].photo.clear();
	}
	else if(S=="1"){
		if(!alb[now].photo.empty()){
			alb[now].photo.erase(--alb[now].photo.end());
			delPhoto++;
		}
	}
	else{
		if(alb[now].photo.find(S)!=alb[now].photo.end()){ // 있다면 해당 사진 삭제
			alb[now].photo.erase(S);
			delPhoto++;
		}
	}
	cout<<delPhoto<<'\n';
}						 
				
void ca(string S){
	if(S==".."){
		if(now!=0){//최상위 앨범이 아니라면
			visit.pop();
			now=visit.top();//이전 앨범으로 이동
		}
	}
	else if(S=="/"){
		now=0;
		while(!visit.empty()) visit.pop();// 방문기록 삭제
		visit.push(0);
	}
	else{
		if(alb[now].ALBUM.find(S)!=alb[now].ALBUM.end()){ // 있다면 해당 앨범으로 이동
			now=alb[now].ALBUM[S];
			visit.push(now);
		}
	}
	//cout<<now<<'\n';
	cout<<alb[now].name<<'\n';
}	
	
void input(){
	cin>>N;
	string mode, type;
	for(int i=0;i<N;i++){
		cin>>mode>>type;
		if(mode=="mkalb") mkalb(type);
		else if(mode=="rmalb") rmalb(type);
		else if(mode=="insert") ins(type);
		else if(mode=="delete") del(type);
		else if(mode=="ca") ca(type);
	}
}

void solve(){
	visit.push(0);
	alb[0].name="album";
	input();
}

int main(){
	solve();
	return 0;
}
