#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <time.h>
#include <QDebug>
using namespace std;

int game::arr[10][10] = {0};
int game::score = 0;

game::game()
{
    srand(time(NULL));
}

void game::init()
{
    for(int row = 0; row<10 ; row++)
    {
        for(int col =0 ;col<10 ; col++)
        {
            arr[row][col] = (rand()%6+1);
        }
    }
}

void game::swap(int &x , int &y)
{
    int temp = x;
    x = y;
     y = temp;
}

bool game::checkLine(int row , int col)
{
    //check way of row
    int count = 1;
    int nextrow = row+1;
    while(arr[row][col] == arr[nextrow][col])
    {
        count++;
        nextrow++;
    }
    if(row != 0)
    {
    int prerow = row - 1;
    while(arr[row][col] == arr[prerow][col])
    {
        count++;
        if(prerow!=0)
            prerow--;
        else
        break;
    }
    }

    //check way of col
    int colcount = 1;
    int nextcol = col+1;
    while(arr[row][col] == arr[row][nextcol])
    {
        colcount++;
        nextcol++;
    }
    if(col != 0)
    {
    int precol = col - 1;
    while(arr[row][col] == arr[row][precol])
    {
        colcount++;
        if(precol!=0)
        precol--;
        else
        break;
    }
    }

    // check the way to bomb

    if(count >= 3 && colcount <3)
    {
        if(count >= 4)
        {
            if(count >= 5)
            {
                rowBomb(row,col,3);
                qDebug() << "row bomb type 3";
            }
            else
            {
            rowBomb(row,col ,2);
            qDebug() << "row bomb type 2";
            }
        }
        else
        {
        rowBomb(row,col ,1);
        qDebug() << "row bomb type 1";
        }
    }

    if(colcount >= 3 && count < 3)
    {
        if(colcount >= 4)
        {
            if(colcount >= 5)
            {
                colBomb(row,col,3);
                qDebug() << "col bomb type 3";
            }
            else
            {
            colBomb(row,col ,2);
            qDebug() << "col bomb type 2";
            }
        }
        else
        {
        colBomb(row,col ,1);
        qDebug() << "col bomb type 1";
        }
    }

    if(count > 3&&colcount >3)
    {
        Bomb(row,col);
    }

    if(count <3 && colcount <3)
    {
        return false;
    }
    else
        return true;
}

void game::rowBomb(int row , int col , int type)
{
    //check way of row
    int value = arr[row][col];
    int nextrow = row+1;
    while(value == arr[nextrow][col])
    {
        arr[nextrow][col] = 0;
        score++;
        nextrow++;
    }
    if(row != 0)
    {
    int prerow = row - 1;
    while(value == arr[prerow][col])
    {
        arr[prerow][col] = 0;
        score++;
        if(prerow!=0)
        prerow--;
        else
        break;
    }
    }
    if(type == 1)
         arr[row][col] = 0;
    else if (type == 2)
         arr[row][col] = 7;
    else if (type == 3)
         arr[row][col] = 10;
    score++;
}
void game::colBomb(int row , int col , int type)
{
    //check way of col
    int value = arr[row][col];
    int nextcol = col+1;
    while(value == arr[row][nextcol])
    {
        arr[row][nextcol] = 0;
        score++;
        nextcol++;
    }
    if(col != 0)
    {
    int precol = col - 1;
    while(value == arr[row][precol])
    {
        arr[row][precol] = 0;
        score++;
        if(precol!=0)
        precol--;
        else
        break;
    }
    }
    if(type == 1)
         arr[row][col] = 0;
    else if (type == 2)
         arr[row][col] = 8;
    else if (type == 3)
         arr[row][col] = 10;
    score++;
}

void game::Bomb(int row , int col)
{
    int value = arr[row][col];
    rowBomb(row,col,1);
    arr[row][col] = value;
    colBomb(row,col,1);
    arr[row][col] = 9;
}

void game::typeBomb(int type , int row , int col , int color)
{
    switch(type)
    {
        case 8:
            for(int c=0;c<10;c++)
            {
                arr[row][c] = 0;
                score++;
            }
            break;
       case 7:
            for(int r=0;r<10;r++)
            {
                arr[r][col] = 0;
                score++;
            }
            break;
        case 9:
            arr[row+1][col] = 0;
            arr[row-1][col] = 0;
            arr[row+1][col+1] = 0;
            arr[row-1][col+1] = 0;
            arr[row+1][col-1] = 0;
            arr[row-1][col-1] = 0;
            arr[row][col+1] = 0;
            arr[row][col-1] = 0;
            arr[row][col] = 0;
            break;
        case 10:
            for(int r = 0; r < 10;r++)
            {
                for(int c = 0; c < 10; c++)
                {
                    if(arr[r][c] == color)
                    {
                        arr[r][c] = 0;
                        score++;
                    }
                }
            }
            arr[row][col] = 0;
            break;
    }
}

void game::moveDown()
{
    for(int row = 0;row<10;row++)
    {
        for(int col = 0 ; col < 10;col++)
        {
            if(arr[row][col] == 0 && row!=0)
            {
                int now = row;
                int up = row - 1;
                while(arr[up][col]!=0&&now!=0)
                {
                arr[now][col] = arr[up][col];
                arr[up][col] = 0;
                now--;
                up--;
                }
            }
        }
    }
    gener();
}

void game::gener()
{
    for(int row = 0;row<10;row++)
    {
        for(int col = 0 ; col < 10;col++)
        {
            if(arr[row][col] == 0)
            {
                arr[row][col] = rand()%6+1;
            }
         }
     }
}
