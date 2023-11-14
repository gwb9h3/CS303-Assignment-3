#include <iostream>
#include "functions.h"

int main() {
  string s = "a+b*c+d";
  cout << to_postfix(s) << endl;
}