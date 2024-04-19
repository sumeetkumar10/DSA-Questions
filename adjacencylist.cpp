#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool dir){
        adj[u].push_back(v);

        if(dir==0){
            adj[v].push_back(u);
        }
    }

    void printList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of node you want to create"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges you want to create"<<endl;
    cin>>m;

    Graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v,0);
    }
    g.printList();

    return 0;
}