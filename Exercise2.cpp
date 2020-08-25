#include <iostream>
#include <stdlib.h>
using namespace std;

int randomstatus(int dirt);
bool isClean(int row, int col, int* hashMap);
void printhash(int row, int col, int* hashMap, int x, int y);

int main() {
      int x, y;
      int row, col;
      int dirt=50;
      cout << "Enter the initial location for the agent";
      cin >> x >> y;
      cout << "Enter the size of the environment";
      cin >> row >> col;
      int* hashMap = new int[row * col]();
      int rand_move;
      
      for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++){
                hashMap[i * row + j] = randomstatus(dirt);
          }
        }
        
    int score=0;
    cout<<"Initial Environment:\n";
    printhash(row, col, hashMap, x, y);
    cout<< endl;
    bool clean= isClean(row, col, hashMap);
    while (clean==false) {
        if (hashMap[x * row + y] == 0) {
            hashMap[x * row + y] = 1;
            score+=10;
        }
        else{
            score-=5;
        }
        rand_move = rand() % 4 + 1;
        switch (rand_move) {
            case 1:
                if (!(x - 1 < 0)) {
                    cout<< "move up:\n";
                    x--;
                    score--;
                    printhash(row, col, hashMap, x, y);
                    cout<< endl;
                    cout << "The score is: " << score << endl;
                }
                break;
             case 2:
                if (!(x + 1 >= row)) {
                    cout<< "move down:\n";
                    x++;
                    score--;
                    printhash(row, col, hashMap, x, y);
                    cout<< endl;
                    cout << "The score is: " << score << endl;
                }
                break;
          case 3:
                if (!(y - 1 < 0)) {
                    cout<< "move left:\n";
                    y--;
                    score--;
                    printhash(row, col, hashMap, x, y);
                    cout<< endl;
                    cout << "The score is: " << score << endl;
                }
                break;
          case 4:
                if (!(y + 1 >= col)) {
                    cout<< "move right:\n";
                    y++;
                    score--;
                    printhash(row, col, hashMap, x, y);
                    cout<< endl;
                    cout << "The score is: " << score << endl;
                }
                break;
          }
        clean= isClean(row, col, hashMap);
    }
    cout<<"Final Environment:\n";
    printhash(row, col, hashMap, x, y);
    cout<< endl;
    cout << "The final score is: " << score << endl;
}

int randomstatus(int dirt){
    int x=rand();
    if(x%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

void printhash(int row, int col, int* hashMap, int x, int y){
    for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++)
          if(i==x && j==y){
              if(hashMap[i * row + j]==0){
                cout <<  "Dirty-Agent    ";
              }
              else{
                cout << "Clean-Agent    ";
              }
          }
          else{
            if(hashMap[i * row + j]==0){
                cout <<  "Dirty          ";
              }
              else{
                cout <<  "Clean          ";
              } 
          }
          cout << endl;
    }
}

bool isClean(int row, int col, int* hashMap){
    for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++){
                if(hashMap[i * row + j]==0){
                    return false;
                }
            }
    }
    return true;
}
