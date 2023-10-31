#include <iostream>
#include <queue>
using namespace std;

void print(int **edges,int n,int sv,bool* visited) {
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv]=true;
    while(!pendingNodes.empty()) {
        int currentVertex=pendingNodes.front();
        pendingNodes.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++) {
            if(i==currentVertex) {
                continue;
            }
            
            if(edges[currentVertex][i]==1 && !visited[i]) {
               pendingNodes.push(i);
               visited[i]=true;
            }
        }
        
    }
}

int main()
{
    int n,e;
    cout<<"Enter number of vertices and edges\n";
    cin>>n>>e;
    
    int**edges=new int*[n];
    for(int i=0;i<n;i++) {
        edges[i]=new int[n];
        
        for(int j=0;j<n;j++) {
            edges[i][j]=0;
        }
    }
    
    cout<<"Enter the edges\n";
    int f,s;
    for(int i=0;i<e;i++) {
        cin>>f>>s;
        
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    bool* visited =new bool[n];
    for(int i=0;i<n;i++) {
        visited[i]=false;
    }
    
    cout<<"Output: \n";
    print(edges,n,0,visited);
    return 0;
}
