#include <iostream>
using namespace std;

int main() {
  char in_string[500] = {0};
  char out_string[26] = {0};
  int times[26] = {0};
  int pointer = 0;
  cin >> in_string;

  //Pre-process the in_string
  for (int i = 0; i < 500; i++){
    if (in_string[i] >= 'a' && in_string[i] <= 'z'){
      in_string[i] = in_string[i] - 32;
    }
  }

  //Main
  for (int i = 0; i < 500; i++){
    if (in_string[i] >= 'A' && in_string[i] <= 'Z'){
      int flag = 0;
      for (int j = 0; j < 26; j++){
        if (out_string[j] == in_string[i]){
          times[j]++;
          flag = 1;
          break;
        }
      }
      if (flag == 0){
        out_string[pointer] = in_string[i];
        times[pointer] = 1;
        pointer++;
      }
    }
  }

  int second = 0, max = 0;
  char second_char = ' ';
  for (int i = 0; i < 26; i++){
    if (times[i] > max){
      max = times[i];
    }
  }
  for (int i = 0; i < 26; i++){
    if (times[i] > second && times[i] != max){
      second = times[i];
      second_char = out_string[i];
    }
  }

  cout << second_char << '+' << (char)(second_char+32) << ':' << second << endl;

  return 0;
}
