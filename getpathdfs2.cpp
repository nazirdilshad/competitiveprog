#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int** edges,int start,int v,bool* visited,int target,vector<int> &vec){
    if(visited[start]){
        return false;
    }
    visited[start]=true;
    if(start == target){
        vec.push_back(start);
        return true;
    }
    
    for(int i= 0;i<v;i++){
        if(edges[start][i]){
            bool x = dfs(edges,i,v,visited,target,vec);
                if(x==true){
                    vec.push_back(start);
                    return true;
                }
            }
    }
    return false;
        
    
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    
    int a,b;
    for(int j=0;j<E;j++){
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1; 
        }
    cin>>a>>b;
    
    bool* visited = new bool[V];
    
    for(int j=0;j<V;j++){
        visited[j]=false;
    }
    vector<int>vec;
    
    dfs(edges,a,V,visited,b,vec);
    if(visited[b]){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }
    

  return 0;
}
