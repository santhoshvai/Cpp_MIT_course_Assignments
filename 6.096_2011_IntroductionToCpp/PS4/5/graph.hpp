#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <map>
#include <vector>

using std::vector;
using std::map;

class Graph {
  map<int, vector<int> > outgoing;

 public:
 /*Constructs a Graph with the given set of edges, where starts and ends represent the
 ordered list of edges’ start and endpoints.*/
  Graph(const vector<int> &startPoints, const vector<int> &endPoints);
  int numOutgoing(const int nodeID) const;
  const vector<int> &adjacent(const int nodeID) const;
};

#endif
