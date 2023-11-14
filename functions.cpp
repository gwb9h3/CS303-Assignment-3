#include "functions.h"

//This is the function that checks to see if the parenthesis usage is balanced in the input prefix function by inserting the brackets into a stack. If it is not balanced it will return false
bool is_balanced(string statement){
  stack<char> stack;
  char x;
  for(int i = 0; i < statement.length(); i++){
    if(statement[i] == '(' || statement[i] == '[' || statement[i] == '{' ){
      stack.push(statement[i]);
      continue;
    }
    switch(statement[i]){
      case ')':
        if (stack.empty())
          return false;
        x = stack.top();
        stack.pop();
        if(x == '{' || x == '[')
          return false;
        break;
      
      case '}':
        if (stack.empty())
          return false;
        x = stack.top();
        stack.pop();
        if(x == '(' || x == '[')
          return false;
        break;
      
      case ']':
        if (stack.empty())
          return false;
        x = stack.top();
        stack.pop();
        if(x == '(' || x == '{')
          return false;
        break;
    }
  }
  return (stack.empty());
}

// This function is used to determine the order of operations when converting from prefix to postfix
int get_value(char c){
  switch(c){
    case '+':
      return 1;
      break;

    case '-':
      return 1;
      break;

    case '*':
      return 2;
      break;

    case '/':
      return 2;
      break;

    case '%':
      return 2;
      break;
  }
  return 0;
}



string to_postfix(string statement){
  if (!is_balanced(statement)){
    string error = "The statement was not balanced please try again.";
    return error;
  }
  
  stack<char> stack;
  string compare0 = "{[()]}+-*/%";
  string compare1 = ")]}";
  string compare2 = "{[(";
  string final = "";
  for(int i = 0; i < statement.length(); i++){
    if (compare0.find(statement[i]) == std::string::npos){
      final += statement[i];
      continue;
    }
    //This tests to see if the char is a beginning parenthesis
    else if(compare2.find(statement[i]) != std::string::npos){
      stack.push(statement[i]);
      continue;
    }
    // This tests to see if the char is an ending parenthesis 
    else if(compare1.find(statement[i]) != std::string::npos){
      //This will loop until the top of the stack is a starting parenthesis
      while(compare2.find(stack.top()) == std::string::npos){
        final += stack.top();
        stack.pop();
      }
      stack.pop();
    }
    // This tests to see what to do with the given operator if it is larger or smaller than the top of the stack
    else{
      while(!stack.empty() && get_value(statement[i]) <= get_value(stack.top())){
        final += stack.top();
        stack.pop();
      }
      stack.push(statement[i]);
    }
  }
  while (!stack.empty()){
    final += stack.top();
    stack.pop();
  }
  return final;
}

// This is the info for the queue

Queue::Queue(){ // This is the constructor for the list
  head = NULL;
  tail = NULL;
  num_items = 0;
}


void Queue::insert(string s){ // This function pushes a new node to the back of the queue
  node* tempNode = new node;
  tempNode ->  item = s;
  tempNode -> next = NULL;
  if(tail == NULL){
    head = tempNode;
    tail = tempNode;
  }
  else{
    tail -> next = tempNode;
    tail = tempNode;
  }
  num_items ++;
}

string Queue::pop_front(){ // This function removes the first node in the queue
  node* tempNode = new node;
  // This saves the data held in the node inside the queue so it can be removed and returned at the same time
  string data = head ->item;
  if (head == NULL){
    return NULL;
  }
  else if(head -> next == NULL){ 
    tempNode -> next = head;
    head = NULL;
    delete tempNode;
    num_items --;
  }
  else{
    tempNode -> next = head;
    head = head -> next;
    delete tempNode;
    num_items --;
  }
  return data;
}

bool Queue::empty(){
  if (head == NULL){
    return true;
  }
  else{
    return false;
  }
}