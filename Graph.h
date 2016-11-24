#include "Vertex.h"
#include <vector>

const int MAXIMUM_VERTICES = 50;

int getVertexId (string line);
int getAdjacencyId (string line);
int getAdjacencyWeight (string line);
int getValueBetweenSeparators(string line, char start, char end);
int getnumberofvertices (string line);
string cutLine(string line, char separator);
int parseInt(string value);

class Graph {
public:
  Vertex vertices[MAXIMUM_VERTICES];
  int numberOfVertices;
  vector<std::string> enderecos_vertices;

  Vertex get(int id){
    return vertices[id];
  }

  void print(){
    cout << "A estrutura do grafo é: "<< endl;
    for(int vertexId = 1; vertexId <= numberOfVertices; vertexId++){
      cout << vertexId << ":";
      get(vertexId).printAdjacencies();
      cout << endl;
    }
  }

  void generateFromFile (ifstream& file){
    string line;
    int vertexIdcounter = 0;
    getline(file,line);
    cout << "Eu estou na primeira linha "<< endl;
    int vertexId, adjacencyId, adjacencyWeight, greaterId;
    numberOfVertices = getnumberofvertices(line);
    cout << "Começando atribuição" << endl;
    cout << "O número de vértices é: " << numberOfVertices << endl;
    while(file.good()){
      getline(file,line);
      vertexId = getVertexId(line);
      if (vertexIdcounter < numberOfVertices){
        vertexIdcounter = vertexIdcounter +1;
        cout << "Eu estou na linha "<< line << endl;
        cout << "A ID do vértice é: " << vertexId << endl;
          string vertex = to_string(vertexId);
          enderecos_vertices.push_back(vertex);
        cout << "Número de vértices lidos: " << vertexIdcounter << endl;
      }
      while (line.length() > 1){
        adjacencyId = getAdjacencyId(line);
        cout << "A adjacência do vértice " << vertexId << " e " << adjacencyId;
        adjacencyWeight = getAdjacencyWeight(line);
        cout << " tem um peso de " << adjacencyWeight << endl;
        vertices[vertexId].createAdjacency(adjacencyId, adjacencyWeight);
        line = cutLine(line, ',');
      }
    }
  }

};


int getnumberofvertices (string line){
  int numberOfVertices = getValueBetweenSeparators(line,'.','.');
  return numberOfVertices;
}

int getVertexId (string line){
  int vertexId = getValueBetweenSeparators(line, '.', ':');
  return vertexId;
}

int getAdjacencyId (string line){
  int adjacencyId = getValueBetweenSeparators(line, ':', '(');
  return adjacencyId;
}

int getAdjacencyWeight (string line){
  int adjacencyWeight = getValueBetweenSeparators(line, '(', ')');
  return adjacencyWeight;
}

int getValueBetweenSeparators(string line, char start, char end){
  int separatorPosition, value;
  line = cutLine(line, start);
  separatorPosition = line.find_first_of(end);
  value = parseInt(line.substr(0,separatorPosition));
  return value;
}

string cutLine(string line, char separator){
  int separatorPosition = line.find_first_of(separator);
  return line.substr(separatorPosition + 1);
}

int parseInt(string value){
  return atoi(value.c_str());
}
