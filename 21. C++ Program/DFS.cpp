#include <iostream>
using namespace std;

void print(int**arr, int n,int sv,bool* visited) {
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++) {
        if(i==sv) {
            continue;
        }
        
        if (arr[sv][i]==1) {
            if(visited[i]) {
                continue;
            }
            print(arr,n,i,visited);
        }
    }
}

int main()
{
    int n,e;
    
    cout<<"Enter number of vertex and edges\n";
    cin>>n>>e;
    
    int**edges=new int*[n];
    
    for(int i=0;i<n;i++) {
        edges[i]=new int[n];
        for(int j=0;j<n;j++) {
            edges[i][j]=0;
        }
    }
    
    int f,s;
    cout<<"enter the edges\n";
    for(int i=0;i<e;i++) {
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    bool* visited= new bool [n];
    for(int i=0;i<n;i++) {
        visited[i]=false;
    }
    cout<<"Output: "<<endl;
    print(edges,n,0,visited);

    return 0;
}
