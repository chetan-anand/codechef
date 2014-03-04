#include <iostream>
#include<utility>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

int flag[21][21],R,C;
char board[21][21];
bool visited[21][21];

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

bool ispass(int r,int c) {
	if(r>=0 && r<R && c>=0 && c<C && board[r][c]=='^') {
		return true;
	}
	return false;
}

bool BFS(int X,int Y) {
	queue<pair<int,int> > Q;
	Q.push(make_pair(X,Y));
	int escapeCount=0;
	while(!Q.empty()) {
		pair<int,int> T;
		T = Q.front();
		Q.pop();
		int rr = T.first;
		int cc = T.second;
		if(!visited[rr][cc])
		{
		if(flag[rr][cc]) {
			//cout<<rr<<" "<<cc<<endl;
			escapeCount++;
		}
		visited[rr][cc] = true;
		int i;
		for(i=0;i<4;i++) {
			if(ispass(rr+dr[i],cc+dc[i]) && !visited[rr+dr[i]][cc+dc[i]]) {
				Q.push(make_pair(rr+dr[i],cc+dc[i]));
			}
		}
		}
	}
	//cout<<escapeCount<<endl;
	if(escapeCount==2) {
		return true;
	}
	return false;
}

int main() {
	int cases;
	int i,j;
	scanf("%d",&cases);
	while(cases--) {
		scanf("%d%d",&R,&C);
		int cnt=0;
		for(i=0;i<R;i++) {
			if(i == 0 || i == R-1) {
				scanf("%s",board[i]);
				for(j=0;j<C;j++) {
					if(board[i][j]=='^') {
						flag[i][j]=1;
					}
				}
			}
			else {
				scanf("%s",board[i]);
				if(board[i][0]=='^') flag[i][0]=1;
				if(board[i][C-1]=='^') flag[i][C-1]=1;
			}
		}
		for(i=0;i<R;i++) {
			for(j=0;j<C;j++)
			{
		//		cout<<flag[i][j]<<" ";
				if(flag[i][j])
				{
					//cout<<i<<" "<<j<<endl;
					cnt++;
				}
			}
		//	cout<<endl;
		}
		if(cnt!=2)
		{
			printf("Asuna");
			if(cases)printf("\n");
		//	cout<<"Hi"<<endl;
			memset(flag,0,sizeof(flag));
			memset(visited,false,sizeof(visited));
			continue;
		}
		bool f;
		for(i=0;i<R;i++) {
			for(j=0;j<C;j++) {
				if(!visited[i][j]&&flag[i][j])
				{
					f=BFS(i,j);
				}
			}
		}
		if(f) {
			printf("Kirito");
		}
		else {
				printf("Asuna");
		}
		if(cases)	printf("\n");
		memset(flag,0,sizeof(flag));
		memset(visited,false,sizeof(visited));
	}
	return 0;
}


