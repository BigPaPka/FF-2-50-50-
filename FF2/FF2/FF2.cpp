#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <map>
#include <sstream>
#include <vector>
#include <iterator>
#include <limits.h>
#include <list>
#include <queue>
#include<algorithm>

using namespace std;

class Graph {
    vector<vector<int>> Matrix;
    vector<string> split(const string& str, char delim) {
        vector<string> result;
        istringstream iss(str);
        string item;
        while (getline(iss, item, delim)) //ввода данных из потока
            result.push_back(item);
        return result;
    }
    vector<string> vertexTable;

public:
    int getNumOfVertices() { return vertexTable.size(); }

    string getVertexById(int id) {
        return vertexTable.at(id);
    }

    int getVertexId(string vertex) {
        for (int i = 0; i < vertexTable.size(); i++) {
            if (vertexTable.at(i) == vertex)
                return i;
        }
        return -1;
    }

    int getWeight(int vFrom, int vTo) { return Matrix[vFrom][vTo]; }

    void setWeight(int vFrom, int vTo, int weight) { Matrix[vFrom][vTo] = weight; }

    Graph(string data);

    Graph(Graph& graph) {
       
    }

    void updateNet(int s, int t, int flow, vector<int> path) {
        for (int v = t; v != s; v = path[v]) {
            int u = path[v];
            setWeight(u, v, getWeight(u, v) - flow);
            setWeight(v, u, getWeight(v, u) + flow);
        }
    }

    int findFlowByPath(int s, int t, vector<int> path) {
        int flow = INT_MAX;
        for (int v = t; v != s; v = path[v]) {
            int u = path[v];
            flow = min(flow, getWeight(u, v));
        }
        return flow;
    }
};

Graph::Graph(string data) {
   
}



bool isThereFlow(Graph graph, int s, int t, vector<int>& path)
{
    int n = graph.getNumOfVertices();
    vector<int> visited;
    queue<int> q;
    q.push(s);
    visited.push_back(s);
    if (path.size() != n)
    {
        while ()
        {
        }
       
    }
    return false;
}

int fordFulkerson(Graph graph, string ss, string tt)
{
    int s = graph.getVertexId(ss);
    int t = graph.getVertexId(tt);
    int n = graph.getNumOfVertices();
    Graph rGraph(graph);
    vector<int> path;
    int maxFlow = 0;

    while (isThereFlow(rGraph, s, t, path)) {
        int flow = rGraph.findFlowByPath(s, t, path);
        rGraph.updateNet(s, t, flow, path);
        maxFlow += flow;
    }

    return maxFlow;
}
void EdgeConnect(Graph graph)
{
    for (int i = 0; i< graph.getNumOfVertices(); i++)
    {
       
    }
}

int main()
{
   // string data = readData("input.txt");
   // Graph graph(data);
   // int maxFlow = fordFulkerson(graph, "S", "T");
   // cout << maxFlow;
}