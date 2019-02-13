#include "tictactoe.h"
#include <stdio.h>
/*#include <string.h>
#include <stdlib.h>*/
unsigned short b3tous( char b3[10] )
{
  unsigned short us;
  int i,value,characterval;
  us=0;
  value=1;
  characterval = 0;
  i=8;
  while(i>=0)
  {
    characterval = b3[i] - '0';
    us=us+(characterval*value);
    value = value*3;
    i--;
  }
  return us;
}


void b3fromus( char b3[10], unsigned short us)
{
  int i;
  int remainder;
  b3[9] = '\0';
  for (i=8;i>=0;i--)
  {
    remainder = us%3+'0';
    b3[i] =remainder;
    us = us/3;

  }
}
void boardfromb3( char board[60], char b3[10])
{
  int index;
  int p;
  strcpy(board,"   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");
  index=0;
  for (p=8;p>=0;p--)
  {
    index=(4*p)+1;
    index=index+((p/3)*12);
    switch(b3[p]){
      case'2':board[index]= 'X';
        break;
      case '1':board[index]='O';
        break;
      case'0':board[index]=' ';
        break;
      default:
        fprintf(stderr,"Error: bad value in b3\n");
        exit(-1);
        break;
    }
  }
}

void boardtob3( char b3[10], char board[60])
{
  int index,p;
  strcpy(board,"   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");
  index=0;
  for (p=8;p>=0;p--)
  {
    index=(4*p)+1;
    index=index+((p/3)*12);
    switch(b3[p]){
      case'2':board[index]= 'X';
        break;
      case '1':board[index]='O';
        break;
      case'0':board[index]=' ';
        break;
      default:
        fprintf(stderr,"Error: bad value in b3\n");
        exit(-1);
        break;
    }
  }
}

char get_move(char b3[10])
{
  int i,count,move;
  count=0;
  move=0;
  for (i=0;i<=8;i++)
  {
    if (b3[i]=='0')
    {
      count=count+1;
    }
  }
  move = 9-count;
  move = move+'0';
  return move;
}

char get_turn( char b3[10])
{
  char move,turn;
  move=get_move(b3);
  move=move-'0';
  if (move%2 == 0){
    turn = '2';
  }else{
    turn = '1';
  }
  return turn;
}
char winner(unsigned short us)
{
  char win;
  char b3[10];
  win = ' ';
  b3fromus(b3,us);
  if ((b3[0]=='2') && (b3[3]=='2') && (b3[6]=='2')){
    win = '2';
  }
  else  if ((b3[1]=='2') && (b3[4]=='2') && (b3[7]=='2')){
    win = '2';
  }
  else if((b3[2]=='2') && (b3[5]=='2') && (b3[8]=='2')){
    win = '2';
  }
  else if ((b3[0]=='1') && (b3[3]=='1') && (b3[6]=='1')){
    win = '1';
  }
  else if ((b3[1]=='1') && (b3[4]=='1') && (b3[7]=='1')){
    win = '1';
  }
  else if((b3[2]=='1') && (b3[5]=='1') && (b3[8]=='1')){
    win = '1';
  }
  else if ((b3[0]=='2') && (b3[1]=='2') && (b3[2]=='2')){
    win = '2';
  }
  else if ((b3[3]=='2') && (b3[4]=='2') && (b3[5]=='2')){
    win = '2';
  }
  else if((b3[6]=='2') && (b3[7]=='2') && (b3[8]=='2')){
    win = '2';
  }
  else if ((b3[0]=='1') && (b3[1]=='1') && (b3[2]=='1')){
    win = '1';
  }
  else if ((b3[3]=='1') && (b3[4]=='1') && (b3[5]=='1')){
    win = '1';
  }
  else if((b3[6]=='1') && (b3[7]=='1') && (b3[8]=='1')){
    win = '1';
  }
  else if ((b3[2]=='2') && (b3[4]=='4') && (b3[6]=='6')){
    win = '2';
  }
  else if ((b3[0]=='2') && (b3[4]=='2') && (b3[8]=='2')){
    win = '2';
  }
  else if((b3[2]=='1') && (b3[4]=='1') && (b3[6]=='1')){
    win = '1';
  }
  else if((b3[0]=='1') && (b3[4]=='1') && (b3[8]=='1')){
    win = '1';
  }
  else if ((b3[0]!='0')&&(b3[1]!='0')&&(b3[2]!='0')&&(b3[3]!='0')&&(b3[4]!='0')&&(b3[5]!='0')&&(b3[6]!='0')&&(b3[7]!='0')&&(b3[8]!='0')&&(b3[9]!='0'))
  {
    win = '0';
  }
  return win;
}
unsigned short next(unsigned short us, char pos)
{
  char b3[10];
  int p;
  char turn;
  b3fromus(b3,us);
  p = pos - '0';
  if (b3[p] != '0')
  {
    return 0;
  }
  else
  {
    turn = get_turn(b3);
    b3[p] = turn;

    us=b3tous(b3);

    return us;
  }
}
void get_record(FILE *fp, unsigned short us, struct strategy_struct *record)
{
  fseek(fp,sizeof(struct strategy_struct)*us,SEEK_SET);
  fread(&record,sizeof(struct strategy_struct),1,fp);
}

void set_record(FILE *fp, unsigned short us, struct strategy_struct record)
{
  fseek(fp,sizeof(struct strategy_struct)*us,SEEK_SET);
  fwrite(&record,sizeof(struct strategy_struct),1,fp);
}
void evaluate_move(unsigned short us, struct strategy_struct record){
  
}
void debug(unsigned short us)
{
  int i;
  char b3[10];
  char board[60];
  char pos;
  printf("Board number: %d\n\n",us);
  b3fromus(b3,us);
  printf("Board b3: %9s\n\n",b3);
  printf("Board Pic:\n");
  boardfromb3(board,b3);
  printf("%s\n",board);
  printf("\n");
  boardtob3(b3,board);
  printf("Move: %c\n\n",get_move(b3));
  printf("Turn: %c\n\n",get_turn(b3));
  printf("Winner:%c\n\n",winner(us));

  for (i=0;i<=8;i++)
  {
    pos=i+'0';
    printf("%d -> %d\n",i,next(us,pos));

  }
}
void debug2(unsigned short us)
{
  struct strategy_struct record;
  FILE *fp;
  int i;
  char b3[10];
  char board[60];
  char pos;
  printf("Board number: %d\n\n",us);
  b3fromus(b3,us);
  printf("Board b3: %9s\n\n",b3);
  printf("Board Pic:\n");
  boardfromb3(board,b3);
  printf("%s\n",board);
  printf("\n");
  boardtob3(b3,board);
  printf("Move: %c\n\n",get_move(b3));
  printf("Turn: %c\n\n",get_turn(b3));
  printf("Winner:%c\n\n",winner(us));

  fp=fopen("strategyfile","rb+");
  get_record(fp,us,&record);

  printf("best_move=%d, winner=%c\n",record.best_move,record.winner);
  fclose(fp);
  for (i=0;i<=8;i++)
  {
    pos = i + '0';
    printf("%d -> %d\n",i,next(us,pos));

  }

}
