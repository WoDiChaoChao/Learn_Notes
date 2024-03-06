## 最小生成树_Prime算法

Prime算法是通过两个辅助变量数组和邻接矩阵实现最小生成树，两个辅助变量分别是记录是否已经被访问过的数组already_add[105]，一个是更新距离的数组dist[105]

##### 首先利用邻接矩阵存图，同时初始化already_add数组，一开始所有的结点都没有被访问过

```c++
int map[105][105];
int n,m;

cin>>n>>m;
for(int i=0;i<n;i++){
	already_add[i] = false;
	for(int j=0;j<n;j++){
		if(i == j)
			map[i][j] = 0;
		else
			map[i][j] = INT_MAX;
	}
}

for(int i=0;i<m;i++){
	int x,y,w;
	cin>>x>>y>>w;
	map[x][y] = map[y][x] = w;
}
```

##### 选择一个起点，同时更新dist数组和already_add数组

```c++
int s;
cin>>s;

for(int i=0;i<n;i++){
	dist[i] = INT_MAX;
}

already_add[s]=true;	//起点被访问过
dist[s]=0; //起点到起点的距离为0

//更新起点到其他点的距离
for(int i=0;i<n;i++){
    if(already_add[i] == false)
		dist[i] = min(dist[i],map[s][i]);
}
```

##### 选出一个起点后，循环n-1次，找到还未被访问过，并且距离最小的点，这里找到的点肯定是和上一个点连接，因为如果不连接的话dist数组的值是INT_MAX，不可能是距离最小的点

```c++
for(int i=1;i<=n-1;i++){
	int tmp = -1;
	int x = INT_MAX;
	for(int j=0;j<n;j++){
		if(already_add[j]==false && dist[j]<x){
			tmp = j;
			x = dist[j];
		}
	}
}
```

##### 选出来这个点后，更新already_add数组，同时更新其它未被访问过的点到该点的距离

```c++
for(int j=0;j<n;j++){
	if(already_add[j]==false){
		dist[j] = min(dist[j],map[tmp][j]);
	}
}
```

##### 循环n-1次之后，最小生成树也就完成了



###### Prime算法就是选择一个点为起点，然后不断地去寻找与该点连接并且权值最小的点，然后再以这个点为起点，循环往复执行n-1次