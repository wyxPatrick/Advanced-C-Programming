#include <iostream>
using namespace std;

char boy;

int recur(char queue[], int s){
  int n;
  if (queue[s] != boy){
    return s;
  }
  else{
    n = recur(queue, s+1);
    cout << s << ' ' << n << endl;
    return recur(queue, n+1);
  }
}

int main(){
  char queue[100] = {0};
  cin >> queue;
  boy = queue[0];
  int n = recur(queue, 1);
  cout << "0 " << n << endl;
  return 0;
}
