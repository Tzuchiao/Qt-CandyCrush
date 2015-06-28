#ifndef GAME_H
#define GAME_H


class game
{
public:
    game();
   static  int arr[10][10];
   void init();
   void checkLine(int , int);
   void swap(int & , int &);
   void moveDown();
   void gener();
   void rowBomb(int , int , int);
   void colBomb(int , int , int);
   void Bomb(int , int);
   void typeBomb(int , int , int , int);
   static int score;
};

#endif // GAME_H
