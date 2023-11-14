#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_balanced(string statement);
string to_postfix(string statement);
int get_value(char c);


//This is the queue class for the second question. It was implemented using a linked list
class Queue {
private:

  typedef struct node{
    string item;
    node* next;
  } *nodePtr;

  nodePtr head;
  nodePtr tail;
  int num_items;


public:
  Queue();
  void insert(string s);
  string pop_front();
  node front(){return *head;};
  bool empty();
  int size(){return num_items;};
};