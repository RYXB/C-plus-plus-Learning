#include<iostream>
#include<queue>

using namespace std;
/*一些量的定义*/
queue<char> q;				//定义一个队列，使用库函数queue
#define	                    //表示最大顶点个数
bool visited[MVNum];		//定义一个visited数组，记录已被访问的顶点

/*邻接矩阵存储表示*/
typedef struct AMGraph
{
	char vexs[MVNum];            //顶点表
	int arcs[MVNum][MVNum];      //邻接矩阵
	int vexnum, arcnum;          //当前的顶点数和边数
}AMGraph;

