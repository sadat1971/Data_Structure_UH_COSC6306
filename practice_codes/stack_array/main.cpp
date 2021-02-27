#include <iostream>
#include <string.h>
#include "stack.cpp"
using namespace std;

int main() {
Stack<int> S;
S.push(34);
S.push(21);
S.push(13);
S.push(8);
S.push(5);
S.push(3);
S.push(2);
S.push(1);
S.push(1);
S.printstack();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();

Stack<string> St;
St.push("beautiful");
St.push("is");
St.push("Life");
St.printstack();


S.printstack();

}