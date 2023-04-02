#include <iostream>
#include <time.h>
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

const int row=30, columns=100; //wymiary planszy
const int length=1000; //ile tur ma minac zanim program sie wylaczy
int boardOrg[row][columns];
int boardNew[row][columns];

void draw_board(int board[row][columns])
{
    cout<<"+";
    for(int i=0; i<columns; i++) cout<<"-";
    cout<<"+"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if (j==0) cout<<"|";
            if (board[i][j]==0) cout<<" ";
            else
            {
                cout<<"X";
            }
        }
        cout<<"|"<<endl;
    }
    cout<<"+";
    for(int i=0; i<columns; i++) cout<<"-";
    cout<<"+"<<endl;
}

void set_random(int board[row][columns])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<columns; j++)
        {
            board[i][j]=rand()% 2;
        }
    }
}

void clearBoard(int board[row][columns])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<columns; j++)
        {
            board[i][j]=0;
        }
    }
}

void life_or_dead(int x, int y)
{
    int counter=0;
    for(int i=-1; i<2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0 && boardOrg[x - i][y - j]==1) counter--;
            if ((x - i) == row) i = row - 2;
            if ((y - j) == columns) j = columns - 2;
            counter += boardOrg[x - i][y - j];
        }
    }

    //cout<< counter<<endl;
    if(boardOrg[x][y]==1) //alive
    {
        if(counter!=2 and counter!=3)
        {
            boardNew[x][y]=0;
        }
    }
    if(boardOrg[x][y]==0) //dead
    {
        if(counter==3)
        {
            boardNew[x][y]=1;
        }
    }
}

void chechStatus()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<columns; j++)
        {
            life_or_dead(i, j);
        }
    }
}

void update()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<columns; j++)
        {
            boardOrg[i][j]=boardNew[i][j];
        }
    }
}

int main() {
    int i=0;
    srand(time(NULL));
    clearBoard(boardOrg);
    clearBoard(boardNew);

    draw_board(boardOrg);
    set_random(boardOrg);
    draw_board(boardOrg);

    while (i<length)
    {
        chechStatus();
        update();
        draw_board(boardOrg);
        Sleep(100);
        system("CLS");
        i++;
    }
    system("PAUSE");
    return 0;
}
