#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std; 

int main(){
    bool **graph; 
    srand(time(0));
    int size;
    cout<<"please insert number of nodes in graph: "<<endl;
    cin>>size;
    graph = new bool*[size];
    for(int i=0;i<size;i++){
        graph[i] = new bool[size];
    }   

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                graph[i][j]=false;
            }
            else{
                graph[i][j] = graph[j][i] = ((rand() / static_cast<double>(RAND_MAX)) < 0.2);
            }
        cout << graph[i][j] << "\t";
        }
        cout<<""<<endl;
    }

}
