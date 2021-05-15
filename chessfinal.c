#include <conio.h>
#include <stdio.h>
#include <dos.h>
// #include <iostream>
#include <graphics.h>
#include <stdlib.h>

int gd = DETECT, gm;

int board[8][8];
int cordx, cordy;
int cango[8][8];
int movable_piece,movable_piece_position[1][2];

enum piece
{
    WhitePawn,
    WhiteKnight,
    WhiteBishop,
    WhiteRook,
    WhiteQueen,
    WhiteKing,
    BlackPawn,
    BlackKnight,
    BlackBishop,
    BlackRook,
    BlackQueen,
    BlackKing
};

void board_initialise()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
            {board[i][j] = -1; cango[i][j]=0;}
    }

    board[0][0] = BlackRook;
    board[0][7] = BlackRook;
    board[7][0] = WhiteRook;
    board[7][7] = WhiteRook;

    board[0][1] = BlackKnight;
    board[0][6] = BlackKnight;
    board[7][6] = WhiteKnight;
    board[7][1] = WhiteKnight;

    board[0][2] = BlackBishop;
    board[0][5] = BlackBishop;
    board[7][5] = WhiteBishop;
    board[7][2] = WhiteBishop;

    board[0][3] = BlackQueen;
    board[0][4] = BlackKing;
    board[7][4] = WhiteKing;
    board[7][3] = WhiteQueen;

    for (int i = 0; i < 8; i++)
        board[1][i] = BlackPawn;


    for (int i = 0; i < 8; i++)
        board[6][i] = WhitePawn;
}
void GraphGenerator()
{
    closegraph();
    initgraph(&gd, &gm, "");
    int x=50,y=50;
    int r,c;
    int red=0;
    for (r = 0; r < 8; r++)
    {
        for (c = 0; c <8; c++)
        {

            if (!red)
            {
                setcolor(YELLOW);
                setfillstyle(SOLID_FILL, RED);
                rectangle(x, y, x + 50, y + 50);
                floodfill(x + 1, y + 1, YELLOW);
            }
            else
            {
                setcolor(YELLOW);
                setfillstyle(SOLID_FILL, YELLOW);
                rectangle(x, y, x + 50, y + 50);
                floodfill(x + 1, y + 1, YELLOW);
            }
            x += 50;
            red=1-red;
        }

        red=1-red;
        x = 50;
        y = 50 + y;

        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++)
            {
                switch (board[i][j])
                {
                    case(WhitePawn):
                        readimagefile("whitepawn.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(WhiteKnight):
                    readimagefile("whiteknight.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(WhiteBishop):
                    readimagefile("whitebishop.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(WhiteRook):
                    readimagefile("whiterook.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(WhiteQueen):
                    readimagefile("whitequeen.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(WhiteKing):
                    readimagefile("whiteking.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(BlackPawn):
                        readimagefile("blackpawn.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(BlackKnight):
                    readimagefile("blackknight.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(BlackBishop):
                    readimagefile("blackbishop.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(BlackRook):
                    readimagefile("blackrook.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(BlackQueen):
                    readimagefile("blackqueen.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    case(BlackKing):
                    readimagefile("blackking.jpeg", (j+1)*50+5, (i+1)*50+5, (j+2)*50-5, (i+2)*50-5);
                        break;
                    default:
                        break;
                }
            }

        }

    }
}



int firstclick(int cordx,int cordy)
{
    int j=(cordx-50)/50,i=(cordy-50)/50;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
            cango[i][j]=0;
    }

    if(i>=0&&i<8&&j>=0&&j<8)
    {

        switch (board[i][j])
        {

            case WhitePawn:

                if(i-1>0&&board[i-1][j]==-1)
                    cango[i-1][j]=1;
                if(i-1>0&&j-1>=0&&((board[i-1][j-1]==-1)||board[i-1][j-1]>5))
                    cango[i-1][j-1]=1;
                if(i-1>0&&j+1<8&&((board[i-1][j+1]==-1)||board[i-1][j+1]>5))
                    cango[i-1][j+1]=1;
                movable_piece=WhitePawn;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;



                break;
            case WhiteKnight:
                if(i-1>=0&&j-2>=0&&((board[i-1][j-2]==-1)||board[i-1][j-2]>5))
                    cango[i-1][j-2]=1;
                if(i-1>=0&&j+2>=0&&((board[i-1][j+2]==-1)||board[i-1][j+2]>5))
                    cango[i-1][j+2]=1;
                if(i+1>=0&&j-2>=0&&((board[i+1][j-2]==-1)||board[i+1][j-2]>5))
                    cango[i+1][j-2]=1;
                if(i+1>=0&&j+2>=0&&((board[i+1][j+2]==-1)||board[i+1][j+2]>5))
                    cango[i+1][j+2]=1;

                if(i-2>=0&&j-1>=0&&((board[i-2][j-1]==-1)||board[i-2][j-1]>5))
                    cango[i-2][j-1]=1;
                if(i-2>=0&&j+1>=0&&((board[i-2][j+1]==-1)||board[i-2][j+1]>5))
                    cango[i-2][j+1]=1;
                if(i+2>=0&&j-1>=0&&((board[i+2][j-1]==-1)||board[i+2][j-1]>5))
                    cango[i+2][j-1]=1;
                if(i+2>=0&&j+1>=0&&((board[i+2][j+1]==-1)||board[i+2][j+1]>5))
                    cango[i+2][j+1]=1;

                movable_piece=WhiteKnight;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;
            case WhiteRook:
                for(int m=0; m<8 ; m++)
                {
                  if(i-m>=0&&((board[i-m][j]==-1)||board[i-m][j]>5))
                    cango[i-m][j]=1;
                  if(i+m>=0&&((board[i+m][j]==-1)||board[i+m][j]>5))
                    cango[i+m][j]=1;
                  if(j+m>=0&&((board[i][j+m]==-1)||board[i][j+m]>5))
                    cango[i][j+m]=1;
                  if(j-m>=0&&((board[i][j-m]==-1)||board[i][j-m]>5))
                    cango[i][j-m]=1;
                }
                movable_piece=WhiteRook;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;
            case WhiteBishop:
                for(int m=0; m<8 ; m++)
                {
                  if(i-m>=0&&j-m>=0&&((board[i-m][j-m]==-1)||board[i-m][j-m]>5))
                    cango[i-m][j-m]=1;
                  if(i+m>=0&&j+m>=0&&((board[i+m][j+m]==-1)||board[i+m][j+m]>5))
                    cango[i+m][j+m]=1;
                  if(i-m>=0&&j+m>=0&&((board[i-m][j+m]==-1)||board[i-m][j+m]>5))
                    cango[i-m][j+m]=1;
                  if(i+m>=0&&j-m>=0&&((board[i+m][j-m]==-1)||board[i+m][j-m]>5))
                    cango[i+m][j-m]=1;
                }
                movable_piece=WhiteBishop;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;
            case WhiteKing:
                if(i-1>0&&j-1>=0&&((board[i-1][j-1]==-1)||board[i-1][j-1]>5))
                    cango[i-1][j-1]=1;
                if(i+1>0&&j+1>=0&&((board[i+1][j+1]==-1)||board[i+1][j+1]>5))
                    cango[i+1][j+1]=1;
                if(i-1>0&&j+1>=0&&((board[i-1][j+1]==-1)||board[i-1][j+1]>5))
                    cango[i-1][j+1]=1;
                if(i+1>0&&j-1>=0&&((board[i+1][j-1]==-1)||board[i+1][j-1]>5))
                    cango[i+1][j-1]=1;
                if(i-1>=0&&((board[i-1][j]==-1)||board[i-1][j]>5))
                    cango[i-1][j]=1;
                if(i+1>=0&&((board[i+1][j]==-1)||board[i+1][j]>5))
                    cango[i+1][j]=1;
                if(j+1>=0&&((board[i][j+1]==-1)||board[i][j+1]>5))
                    cango[i][j+1]=1;
                if(j-1>=0&&((board[i][j-1]==-1)||board[i][j-1]>5))
                    cango[i][j-1]=1;
                movable_piece=WhiteKing;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                    break;
            case WhiteQueen:
                for(int m=0; m<8 ; m++)
                {
                  if(i-m>=0&&((board[i-m][j]==-1)||board[i-m][j]>5))
                    cango[i-m][j]=1;
                  if(i+m>=0&&((board[i+m][j]==-1)||board[i+m][j]>5))
                    cango[i+m][j]=1;
                  if(j+m>=0&&((board[i][j+m]==-1)||board[i][j+m]>5))
                    cango[i][j+m]=1;
                  if(j-m>=0&&((board[i][j-m]==-1)||board[i][j-m]>5))
                    cango[i][j-m]=1;
                  if(i-m>=0&&j-m>=0&&((board[i-m][j-m]==-1)||board[i-m][j-m]>5))
                    cango[i-m][j-m]=1;
                  if(i+m>=0&&j+m>=0&&((board[i+m][j+m]==-1)||board[i+m][j+m]>5))
                    cango[i+m][j+m]=1;
                  if(i-m>=0&&j+m>=0&&((board[i-m][j+m]==-1)||board[i-m][j+m]>5))
                    cango[i-m][j+m]=1;
                  if(i+m>=0&&j-m>=0&&((board[i+m][j-m]==-1)||board[i+m][j-m]>5))
                    cango[i+m][j-m]=1;

                }
                movable_piece=WhiteQueen;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                    break;

            case BlackPawn:
                if(i+1<7&&board[i+1][j]==-1)
                    cango[i+1][j]=1;
                if(i+1<7&&j-1>=0&&((board[i+1][j-1]==-1)||board[i+1][j-1]<6))
                    cango[i+1][j-1]=1;
                if(i+1<7&&j+1<8&&((board[i+1][j+1]==-1)||board[i+1][j+1]<6))
                    cango[i+1][j+1]=1;
                movable_piece=BlackPawn;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;

            case BlackKnight:
                if(i-1<=7&&j-2>=0&&((board[i-1][j-2]==-1)||board[i-1][j-2]<6))
                    cango[i-1][j-2]=1;
                if(i-1<=7&&j+2>=0&&((board[i-1][j+2]==-1)||board[i-1][j+2]<6))
                    cango[i-1][j+2]=1;
                if(i+1<=7&&j-2>=0&&((board[i+1][j-2]==-1)||board[i+1][j-2]<6))
                    cango[i+1][j-2]=1;
                if(i+1<=7&&j+2>=0&&((board[i+1][j+2]==-1)||board[i+1][j+2]<6))
                    cango[i+1][j+2]=1;

                if(i-2<=7&&j-1>=0&&((board[i-2][j-1]==-1)||board[i-2][j-1]<6))
                    cango[i-2][j-1]=1;
                if(i-2<=7&&j+1>=0&&((board[i-2][j+1]==-1)||board[i-2][j+1]<6))
                    cango[i-2][j+1]=1;
                if(i+2<=7&&j-1>=0&&((board[i+2][j-1]==-1)||board[i+2][j-1]<6))
                    cango[i+2][j-1]=1;
                if(i+2<=7&&j+1>=0&&((board[i+2][j+1]==-1)||board[i+2][j+1]<6))
                    cango[i+2][j+1]=1;
                movable_piece=BlackKnight;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;

           case BlackBishop:
                for(int m=0; m<8 ; m++)
                {
                  if(i-m>=0&&j-m>=0&&((board[i-m][j-m]==-1)||board[i-m][j-m]<6))
                    cango[i-m][j-m]=1;
                  if(i+m>=0&&j+m>=0&&((board[i+m][j+m]==-1)||board[i+m][j+m]<6))
                    cango[i+m][j+m]=1;
                  if(i-m>=0&&j+m>=0&&((board[i-m][j+m]==-1)||board[i-m][j+m]<6))
                    cango[i-m][j+m]=1;
                  if(i+m>=0&&j-m>=0&&((board[i+m][j-m]==-1)||board[i+m][j-m]<6))
                    cango[i+m][j-m]=1;
                }
                movable_piece=BlackBishop;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;

             case BlackRook:
                for(int m=0; m<8 ; m++)
                {
                  if(i-m>=0&&((board[i-m][j]==-1)||board[i-m][j]<6))
                    cango[i-m][j]=1;
                  if(i+m>=0&&((board[i+m][j]==-1)||board[i+m][j]<6))
                    cango[i+m][j]=1;
                  if(j+m>=0&&((board[i][j+m]==-1)||board[i][j+m]<6))
                    cango[i][j+m]=1;
                  if(j-m>=0&&((board[i][j-m]==-1)||board[i][j-m]<6))
                    cango[i][j-m]=1;
                }
                movable_piece=BlackRook;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                break;

            case BlackKing:
                if(i-1>0&&j-1>=0&&((board[i-1][j-1]==-1)||board[i-1][j-1]<6))
                    cango[i-1][j-1]=1;
                if(i+1>0&&j+1>=0&&((board[i+1][j+1]==-1)||board[i+1][j+1]<6))
                    cango[i+1][j+1]=1;
                if(i-1>0&&j+1>=0&&((board[i-1][j+1]==-1)||board[i-1][j+1]<6))
                    cango[i-1][j+1]=1;
                if(i+1>0&&j-1>=0&&((board[i+1][j-1]==-1)||board[i+1][j-1]<6))
                    cango[i+1][j-1]=1;
                if(i-1>=0&&((board[i-1][j]==-1)||board[i-1][j]<6))
                    cango[i-1][j]=1;
                if(i+1>=0&&((board[i+1][j]==-1)||board[i+1][j]<6))
                    cango[i+1][j]=1;
                if(j+1>=0&&((board[i][j+1]==-1)||board[i][j+1]<6))
                    cango[i][j+1]=1;
                if(j-1>=0&&((board[i][j-1]==-1)||board[i][j-1]<6))
                    cango[i][j-1]=1;
                movable_piece=BlackKing;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                    break;
            case BlackQueen:
                for(int m=0; m<8 ; m++)
                {
                  if(i-m>=0&&((board[i-m][j]==-1)||board[i-m][j]<6))
                    cango[i-m][j]=1;
                  if(i+m>=0&&((board[i+m][j]==-1)||board[i+m][j]<6))
                    cango[i+m][j]=1;
                  if(j+m>=0&&((board[i][j+m]==-1)||board[i][j+m]<6))
                    cango[i][j+m]=1;
                  if(j-m>=0&&((board[i][j-m]==-1)||board[i][j-m]<6))
                    cango[i][j-m]=1;
                  if(i-m>=0&&j-m>=0&&((board[i-m][j-m]==-1)||board[i-m][j-m]<6))
                    cango[i-m][j-m]=1;
                  if(i+m>=0&&j+m>=0&&((board[i+m][j+m]==-1)||board[i+m][j+m]<6))
                    cango[i+m][j+m]=1;
                  if(i-m>=0&&j+m>=0&&((board[i-m][j+m]==-1)||board[i-m][j+m]<6))
                    cango[i-m][j+m]=1;
                  if(i+m>=0&&j-m>=0&&((board[i+m][j-m]==-1)||board[i+m][j-m]<6))
                    cango[i+m][j-m]=1;

                }
                movable_piece=BlackQueen;
                movable_piece_position[0][0]=i;
                movable_piece_position[0][1]=j;
                    break;






            default:
                break;
        }
    }
    else
        return -1;

}

int secondclick(int cordx,int cordy)
{
    int j=(cordx-50)/50,i=(cordy-50)/50;

    if(cango[i][j])
    {
        board[movable_piece_position[0][0]][movable_piece_position[0][1]]=-1;
        board[i][j]=movable_piece;
    }

}





int main()
{
    initgraph(&gd, &gm, "");

    outtextxy(50, 120, "WELCOME TO CHESS GAME");
    settextstyle(1, HORIZ_DIR, 3);
    getch();
    cleardevice();

    setcolor(CYAN);
    outtextxy(50, 220, "DESIGNED BY ");
    settextstyle(1, HORIZ_DIR, RED);
    setcolor(6);
    outtextxy(50, 250, "SHIRIN");

    getch();
    cleardevice();

    board_initialise();
    GraphGenerator();

    int cordx = 0, cordy = 0;

    while (1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, cordx, cordy);
            printf("%d   %d\n", cordx, cordy);
            firstclick(cordx,cordy);
            while(ismouseclick(WM_LBUTTONDOWN)!=1){}
            getmouseclick(WM_LBUTTONDOWN, cordx, cordy);
            printf("%d   %d\n", cordx, cordy);
            secondclick(cordx,cordy);
            GraphGenerator();
        }
    }


    return 0;
}
