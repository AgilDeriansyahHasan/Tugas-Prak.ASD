#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v){
	for(i=1;i<=n;i++)
		if(a[v][i] && !visited[i])
			q[++r]=i;
		if(f<=r){
			visited[q[f]]=1;
		bfs(q[f++]);};
}

int main(){
	int v;
	cout<<"Masukkan Matriks atau Vertex : "; cin >> n;
	for(i=1;i<=n;i++){
		q[i]=0;
	visited[i]=0;}
	cout<<"Masukkan Data Graph Dalam Bentuk Matriks [nxn] : "<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		cin >> a[i][j];
		}
	}
	cout<<"Masukkan Vertex Awal : "; cin >> v;
	bfs(v);
	cout<<" Node Yang Dapat Dicapai : ";
	for(i=1;i<=n;i++){
		if(visited[i])
			cout<<i<<" ";
		else
		{
			cout<<"BFS - Tidak Semua Node Dapat Dijangkau";
			break;
		}
	}
	cout<<endl;
	cin.get();
}
