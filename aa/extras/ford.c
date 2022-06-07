#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES  10
int flow[MAX_NODES][MAX_NODES] ; 
int capacity[MAX_NODES][MAX_NODES] ; 
int n ,e ;
int path[MAX_NODES+2];
int pathPointer = -1;
int MAX_FLOW =0;

void printPath(){

    printf(" S ->" );
    for(int i=1 ; i<pathPointer; i++){
        printf(" %c ->"  , (path[i]+64 ) );
    }
    printf(" T    ");
}

void upDateFlow(){
    int pathMaxFlow =capacity[path[0]][path[1]] - flow[path[0]][path[1]];

    for(int i =1; i<pathPointer; i++){

        int res = capacity[path[i]][path[i+1]] - flow[path[i]][path[i+1]];
        if(pathMaxFlow > res){
            pathMaxFlow =res;
        }
    }

    // UPDATE FLOW
    for(int i =1; i<pathPointer; i++){
         flow[path[i]][path[i+1]] += pathMaxFlow;
    }
    printf("FLOW : %d ", pathMaxFlow);
    MAX_FLOW += pathMaxFlow;
}

void findPath(int node, int goal , int visited[]){

    visited[node]=1;
    if(node == goal){
        printPath();
        upDateFlow();
        printf("\n");
        return ;
    }

    // PATH        
    for(int j=0; j<n; j++){
        if(visited[j] !=1 && capacity[node][j] - flow[node][j] > 0 ){
            path[++pathPointer]=j;
            findPath(j, goal, visited);
            visited[j]=0 ;
            pathPointer--;
        }
    }

}

int ford(int start , int target){

    int maxflow;
    int visited[MAX_NODES+2];
    pathPointer = 0;
    for(int j=0; j<MAX_NODES+2; j++){
       visited[j]=0;
       path[j]=0;
    }    

    findPath(start,  target, visited );
    return maxflow;
}

int main(){

    // clear old values
    for(int i=0; i<MAX_NODES ; i++){
        for(int j=0; j<MAX_NODES; j++){
            flow[i][j] =0;
            capacity[i][j] =0;
        }
    }


    n=6; // No. of Nodes
    e = 7; // No. of edges

    capacity[0][1] = 8;
    capacity[0][4] = 3;
    capacity[1][2] = 9;
    capacity[2][5] = 2;
    capacity[3][5] = 5;
    capacity[4][2] = 7;
    capacity[4][3] = 4;

    int s = 0, t = 5;

    int maxflow = ford(s,t);
    printf(" MAX FLOW : %d\n\n", MAX_FLOW);



}





