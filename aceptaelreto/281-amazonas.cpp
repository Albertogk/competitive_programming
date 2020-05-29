#include <iostream>

using namespace std;

class Edge {
    public:
        int src, dest, weight;
        Edge(int src, int dest, int weight) {
            this->src = src;
            this->dest = dest;
            this->weight = weight;
        }
};

class Node {
    public:
        int id;
        Edge *edges;
        Node(int id, Edge* edges = NULL) {
            this->id = id;
            this->edges = edges;
        }
};

int main() {
    int n;
    cin >> n;
    Node **nodes = NULL;
    nodes = new Node*[n];
    for(int i=0; i<n-1; i++) {
        Edge *edges = new Edge[n-1-i];
        for(int j=0; j<n-1-i; j++) {

        }
        nodes[i] = new Node(i, )
    }
    return 0;
}