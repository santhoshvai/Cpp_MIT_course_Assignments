#include "./graph.hpp"
#include <stdexcept>

Graph::Graph(const vector<int> &startPoints, const vector<int> &endPoints) {
  if ( startPoints.size() != endPoints.size() ) {
    throw std::invalid_argument(" Start/end points lists differ in length ");
  }
  for ( size_t i = 0; i < startPoints.size(); i++ ) {
      int start = startPoints[i], end = endPoints[i];
      outgoing[start].push_back(end);
      outgoing[end];  // Just to indicate this node exists
  }
}

/*Returns the number of outgoing edges from nodeID –
that is, edges with nodeID as the start point */
int Graph::numOutgoing(const int nodeID) const {
  return adjacent(nodeID).size();
}

// Returns a reference to the list of nodes to which nodeID has outgoing edges
const vector<int> &Graph::adjacent(const int nodeID) const {
  // this is O(lg n) and access using outgoing[i] is also O(lg n)
  map< int, vector<int> >::const_iterator i = outgoing.find(nodeID);
  if (i == outgoing.end()) {
    throw std::invalid_argument("Invalid node ID");
  }
  return i->second;
  // dereferencing a map iterator gives an std::pair which has first and second elements
  // first element refers to key in a map
  // second refers to value in a map
  // http://stackoverflow.com/questions/15451287/what-does-iterator-second-mean
}
