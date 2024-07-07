//change the amount variable to change the amount of numbers generated

//change min and max to change the range of numbers generated

#include <iostream>
#include <random>
using namespace std;

int amount = 10;

int *sort = new int[amount];


void random(int min, int max){

  for (int i = 0; i < amount; i++){
    random_device rd;
    uniform_int_distribution<int> dist(min, max);
    sort[i] = dist(rd);
  }
}


void insert(){
for(int i = 0; i < amount; i++){
  int minvalIndex = sort[i];
  for(int x = i; x < amount; x++){
    if(minvalIndex >= sort[x]){
      minvalIndex = sort[x];
      for(int y = x; y > i; y--){
        sort[y] = sort[y-1];
        sort[y - 1] = minvalIndex;
        }
      }
    }
  }
}



int main() {
  
  random(0, 10);
  cout << "unsorted: ";
  for(int i = 0; i < amount; i++){
    cout << sort[i] << " ";
  }
  
  cout << endl << endl;
  
  insert();
  cout << "sorted: ";
  for(int i = 0; i < amount; i++){
    cout << sort[i] << " ";
  }
  
  delete[]sort;
}


  
