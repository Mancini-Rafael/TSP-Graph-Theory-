class Vertex {
  public:
    list <int> adjacenciesId;
    list <int> adjacenciesWeight;

    void createAdjacency(int id, int weight){
      adjacenciesId.push_back(id);
      adjacenciesWeight.push_back(weight);
    }

    void printAdjacencies(){
      std::list<int>::iterator id = adjacenciesId.begin();
      std::list<int>::iterator weight = adjacenciesWeight.begin();

      while(id != adjacenciesId.end()){
        cout << *id << "(" << *weight << "),";
        id++;
        weight++;
      }
    }
};
