#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
//定义用邻接表表示的无权有向图

struct Edge 
{
	char dest;//储存边的值
	int nextVertex;
	Edge* link;
	Edge(){}
	Edge(char c,Edge* p,int num):dest(c),link(p),nextVertex(num){}
};

struct Vertex
{
	int data;
	int final = 0;
	Edge* adj;
	bool end = false;
};

class Graph
{
private:
	int maxVertices;
	int numEdges;

public:
	Vertex* NodeTable;
	int numVertices;

	Graph()
	{
		maxVertices = 100;
		numVertices = 0;
		numEdges = 0;
		NodeTable = new Vertex[maxVertices];
		for (int i = 0; i < maxVertices; i++) {
			NodeTable[i].adj = 0;
		}
	}

	bool insertVertex();//插入点
	bool insertEdge(int v1, int v2, char c);//插入边

	int getFirstNeighbor(int v, char c);
	int getNextNeighbor(int v, int w, char c);

	int getValue(int i);//根据结点序号获取结点的值
	int getVertexPos(int Vertex);//根据结点的值获取结点的序号

	int NumberOfVertices();
	int NumberOfEdges();

	//深度优先搜索
	void DFS(int v, char c, bool visited[]);
	void DFS(int v, char c);
};

#endif // !GRAPH_H
