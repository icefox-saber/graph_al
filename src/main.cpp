//main.Cpp
#include "Graph.h"
using namespace std;
int main() {
    Graph<string,double> myGraph(true);  // 用正确的参数初始化对象
    myGraph.insertVertex("A1");
    myGraph.insertVertex("B2");
    myGraph.insertVertex("C3");
    myGraph.insertVertex("D4");
    myGraph.insertVertex("E5");
    myGraph.insertVertex("F6");
    myGraph.insertEdge("A1","B2");
    myGraph.insertEdge("B2","C3");
    myGraph.insertEdge("C3","D4");
    myGraph.insertEdge("D4","E5");
    myGraph.insertEdge("E5","A1");
    myGraph.insertEdge("B2","F6");
    myGraph.insertEdge("F6","B2");
    std::cout<<"display"<<'\n';
    myGraph.display();
    /*std::cout<<"DFS_D"<<'\n';
    myGraph.DFS_D();
    std::cout<<"DFS_R"<<'\n';
    myGraph.DFS_R();
    std::cout<<"BFS"<<'\n';
    myGraph.BFS();*/
    if(myGraph.connected())
        std::cout<<"connected"<<'\n';
    if(myGraph.hasEulerCircuit())
    {
        std::cout<<"hasEulerCircuit"<<'\n';
        myGraph.fleury();
    }
    if(myGraph.cyclic())
    {
        std::cout<<"cyclic";
    }

    //Graph<string,double> *tmp=myGraph.clone();
    //std::cout<<"clone"<<'\n';
    //tmp->display();
    //delete tmp;
    //tmp=nullptr;

    return 0;
}
