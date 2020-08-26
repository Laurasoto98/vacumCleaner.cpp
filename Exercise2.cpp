#include <iostream>
#include <stdlib.h>
using namespace std;

int randomValue();
bool isClean(int row, int col, int* environmenr);
void printhash(int row, int col, int* environmenr, int x, int y);

int main() {
      int x, y;
      int row, col;
      cout << "Enter the initial location for the agent: \n";
      cin >> x >> y;
      cout << "Enter the size of the environment: \n";
      cin >> row >> col;
      int* environmenr = new int[row * col]();
      
      for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++){
                environmenr[i * row + j] = randomValue();
          }
        }
        
    int score=0;
    cout<<"Initial Environment:\n";
    printhash(row, col, environmenr, x, y);
    cout<< endl;
    bool clean= isClean(row, col, environmenr);
    while (clean==false) {
        if (environmenr[x * row + y] == 0) {
            environmenr[x * row + y] = 1;
            score+=10;
        }
        int move = rand() % 4 + 1;
        switch (move) {
            case 1:
                if (!(x - 1 < 0)) {
                    cout<< "Move up:\n";
                    x--;
                    score--;
                    printhash(row, col, environmenr, x, y);
                    cout<< endl;
                    
                }
                break;
             case 2:
                if (!(x + 1 >= row)) {
                    cout<< "Move down:\n";
                    x++;
                    score--;
                    printhash(row, col, environmenr, x, y);
                    cout<< endl;
                    
                }
                break;
          case 3:
                if (!(y - 1 < 0)) {
                    cout<< "Move left:\n";
                    y--;
                    score--;
                    printhash(row, col, environmenr, x, y);
                    cout<< endl;
                    
                }
                break;
          case 4:
                if (!(y + 1 >= col)) {
                    cout<< "Move right:\n";
                    y++;
                    score--;
                    printhash(row, col, environmenr, x, y);
                    cout<< endl;
                    
                }
                break;
          }
        clean= isClean(row, col, environmenr);
    }
    cout<<"Final Environment:\n";
    printhash(row, col, environmenr, x, y);
    cout<< endl;
    cout << "The final score is: " << score << endl;
}

int randomValue(){
    int x=rand();
    if(x%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

void printhash(int row, int col, int* environmenr, int x, int y){
    cout<<endl;
    for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++)
          if(i==x && j==y){
              if(environmenr[i * row + j]==0){
                cout <<  "Dirty-Agent    ";
              }
              else{
                cout << "Clean-Agent    ";
              }
          }
          else{
            if(environmenr[i * row + j]==0){
                cout <<  "Dirty          ";
              }
              else{
                cout <<  "Clean          ";
              } 
          }
          cout << endl;
    }
}

bool isClean(int row, int col, int* environmenr){
    for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++){
                if(environmenr[i * row + j]==0){
                    return false;
                }
            }
    }
    return true;
}
