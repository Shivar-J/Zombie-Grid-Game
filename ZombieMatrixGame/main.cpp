//
//  main.cpp
//  ZombieMatrixGame
//
//  Created by Shivar Jadoonanan on 2021-11-24.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <ncurses.h>
#include <chrono>
#include <thread>

#define N 11

using namespace std;
using namespace chrono;
using namespace this_thread;

int turnCounter = 0;
int zombiesNum = 2;

void print(vector<vector<int>> &grid) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n\r";
    }
    printf("%c[2K", 27);
    system("clear");
}

void moveLeft(vector<vector<int>> &grid) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                if(i == 0 && j == 0){
                    cout << "Cannot move left" << "\n\r";
                    break;
                } else if(i == 0 && j == 10){
                    grid[i][j] = 0;
                    grid[i][j-1] = 1;
                    break;
                } else if(i == 10 && j == 0){
                    cout << "Cannot move left" << "\n\r";
                    break;
                } else if(i == 10 && j == 10){
                    grid[i][j] = 0;
                    grid[i][j-1] = 1;
                    break;
                } else if(j == 0){
                    cout << "Cannot move left" << "\n\r";
                    break;
                } else {
                    grid[i][j] = 0;
                    grid[i][j-1] = 1;
                    break;
                }
            } else {
                continue;
            }
        }
    }
    
    
}

void moveRight(vector<vector<int>> &grid) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                if(i == 0 && j == 0){
                    grid[i][j] = 0;
                    grid[i][j+1] = 1;
                    break;
                } else if(i == 0 && j == 10){
                    cout << "Cannot move right" << "\n\r";
                    break;
                } else if(i == 10 && j == 10){
                    cout << "Cannot move right" << "\n\r";
                    break;
                } else if(i == 10 && j == 10){
                    cout << "Cannot move right" << "\n\r";
                    break;
                } else if(j == 10){
                    cout << "Cannot move right" << "\n\r";
                    break;
                } else {
                    grid[i][j] = 0;
                    grid[i][j+1] = 1;
                    break;
                }
            }
        }
    }
}

void moveUp(vector<vector<int>> &grid) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                if(i == 0 && j == 0){
                    cout << "Cannot move up" << "\n\r";
                    break;
                } else if(i == 0 && j == 10){
                    cout << "Cannot move up" << "\n\r";
                    break;
                } else if(i == 0){
                    cout << "Cannot move up" << "\n\r";
                    break;
                } else {
                    grid[i][j] = 0;
                    grid[i-1][j] = 1;
                    break;
                }
            }
        }
    }
}

void moveDown(vector<vector<int>> &grid) {
    int counter = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                if(i == 10){
                    cout << "Cannot move down" << "\n\r";
                    break;
                } else {
                    counter++;
                    grid[i+1][j] = 1;
                    grid[i][j] = 0;
                    if(counter != 0){
                        break;
                    }
                }
            }
        }
        if(counter != 0){
            break;
        }
    }
}

void generateZombies(vector<vector<int>> &grid) {
    /*for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
        
        }
    }*/
}

int zombiesPerRound(int zombiesNum) {
    int tempNum = zombiesNum * 2;
    return tempNum;
}

int main(int argc, const char * argv[]) {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    srand(time(NULL));
    vector<vector<int>> grid(N, vector<int> (N));
    grid[5][5] = 1;
    //print(grid);
    //generateZombies(grid);
    
    printw("Left Arrow: Move Left\nRight Arrow: Move Right\nUp Arrow: Move Up\nDown Arrow: Move Down\nBackspace: Quit");
    
        
    while(true){
        refresh();
        int userNum;
        userNum = getch();
        
        if(userNum == KEY_LEFT){
            moveLeft(grid);
            print(grid);
            continue;
        } else if(userNum == KEY_RIGHT){
            moveRight(grid);
            print(grid);
            continue;
        } else if(userNum == KEY_UP){
            moveUp(grid);
            print(grid);
            continue;
        } else if(userNum == KEY_DOWN){
            moveDown(grid);
            print(grid);
            continue;
        } else if(userNum == KEY_BACKSPACE){
            endwin();
            refresh();
        } else {
            //printw("Invalid Output");
        }
    }
    //print(grid);
}
