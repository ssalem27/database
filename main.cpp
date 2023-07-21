#include <random>
#include <iostream>
#define BUFFER_SIZE 18


int main() {
  int count = 1;
  int id = count;
  char* rowId = (char*) calloc(BUFFER_SIZE, sizeof(char));
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(32, 126);
  id<<=16;
  id = id+(dist(mt)<<8) + dist(mt);
  count++;
  snprintf(rowId,BUFFER_SIZE,"%x",id);

  printf("%s\n",rowId);

  int p = 17;
  int n = strlen(rowId);
  int sum = 0;
  for(int i=0; i<n; i++){
      sum += rowId[i]* pow(p,i);
  }

  printf("%d\n",sum%23);
  return 0;

}