#include <string.h>
using namespace std;
struct Node{
  string val;
  Node* next;
  Node* prev;
  Node(string STR="", Node* prevptr=NULL, Node* nextptr=NULL): val(STR), prev(prevptr), next(nextptr) {};
};