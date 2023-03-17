/*
  Aprendendo conceito de Matrizes com Jogo de Damas desenvolvido em Linguagem C
  
  /////GitHub/////
  Alexsander S Costa: DraftKingDL
  Gabriel T Ceolin: Tresceolin3
  Mateus A Vicente: matvicen-dev

  O codigo foi feito em Windows. As coordenadas dos movimentos sao lidas conforme a seguir: linha, coluna. 
  Exemplo: mover peca da linha 3 coluna 4 -> insira: 3,4
*/


#include <stdio.h>  //printf, scanf
#include <stdlib.h> //system("cls"), rand, srand
#include <ctype.h> //tolower
#include <math.h> //abs
#include <time.h> //para a funcao time(NULL) usada no srand

char vez, tabuleiro[8][8]={ 'x','b','x','b','x','b','x','b',
                            'b','x','b','x','b','x','b','x',
                            'x','b','x','b','x','b','x','b',
                            '0','x','0','x','0','x','0','x',
                            'x','0','x','0','x','0','x','0',
                            'p','x','p','x','p','x','p','x',
                            'x','p','x','p','x','p','x','p',
                            'p','x','p','x','p','x','p','x'};
int c, l, xi, yi, xf, yf, venc=0, mov, empate=100; //yi = linha inicial, xi = coluna inicial, yf = linha final, xf = coluna final

void VerificaDama() //transforma pecas nas ultimas linhas em dama
{
    for (c=0;c<8;c++)
    {
        if (tabuleiro[7][c]=='b')
            tabuleiro[7][c]='B';
        if (tabuleiro[0][c]=='p')
            tabuleiro[0][c]='P';
    }
}
void ImprimirTabuleiro() //funcao que imprime o tabuleiro na tela
{
    system("cls");
    printf ("\t       1   2   3   4   5   6   7   8 \n\n");
    for (l=0;l<8;l++)
    {
        printf ("\t%d    ",l+1);
        for(c=0;c<8;c++)
        {
            switch (tabuleiro[l][c])
            {
            case 'x': printf ("\xB2\xB2\xB2\xB2");
            break;
            case '0': printf ("    ");
            break;
            case 'p': printf ("  P ");
            break;
            case 'P': printf (" PP ");
            break;
            case 'b': printf ("  B ");
            break;
            case 'B': printf (" BB ");
            break;
            }
        }
        printf ("\n");
    }
}
void MovBranca () //Funcao de movimento das pecas brancas
{
    char op;
    int xc, yc, caminho=0,captura;
    mov=0;
    do{
        do{
            printf ("\nInsira a coordenada da peca a ser movimentada: ");
            scanf("\n%d,%d",&yi,&xi);
        }while(tolower(tabuleiro[yi-1][xi-1])!=vez);
        do {
            printf("\nInsira a coordenada da casa destino: ");
            scanf("\n%d,%d",&yf,&xf);
        } while (tabuleiro[yf-1][xf-1]!='0');
        xc=(xi+xf)/2;
        yc=(yi+yf)/2;
        if (tabuleiro[yi-1][xi-1]=='b') //movimentar peca que nao seja dama
        {
            if (yi-yf==-1 && abs(xi-xf)==1) //movimentacao simples
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                mov=1;
            }
            else //comendo peca adversaria
            {
                if (yi-yf==-2 && abs(xi-xf)==2 && tolower(tabuleiro[yc-1][xc-1])=='p')
                {
                    tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                    tabuleiro[yi-1][xi-1]='0';
                    tabuleiro[yc-1][xc-1]='0';
                    printf("\nDeseja capturar mais alguma peca? (s/n): "); //para captura em cadeia
                    scanf ("\n%c",&op);
                    if (op!='s')
                        mov=1;
                    while (op=='s') {
                        ImprimirTabuleiro();
                        xi=xf;
                        yi=yf;
                        do {
                            printf("\nInsira a coordenada da casa destino: ");
                            scanf("\n%d,%d",&yf,&xf);
                        } while (tabuleiro[yf-1][xf-1]!='0');
                         xc=(xi+xf)/2;
                         yc=(yi+yf)/2;
                         if (abs(yi-yf)==2 && abs(xi-xf)==2 && tolower(tabuleiro[yc-1][xc-1])=='p')
                         {
                            tabuleiro [yf-1][xf-1]='b';
                            tabuleiro[yi-1][xi-1]='0';
                            tabuleiro[yc-1][xc-1]='0';
                            VerificaDama();
                            printf("\nDeseja capturar mais alguma peca? (s/n): ");
                            scanf ("\n%c",&op);
                         }
                         else
                         {
                             printf ("\nMov Invalido! Deseja tentar capturar mais alguma peca? (s/n): ");
                             scanf ("\n%c",&op);
                         }
                         if (op!='s')
                             mov=1;
                        }
                }
            }
        }
                else //movimentar dama branca
        {
            caminho=0;
            captura=0;
            if (yf>yi && xf>xi) //verifica��o para baixo e para direita
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1+i][xi-1+i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf-2][xf-2])=='p')
                        captura=1;
            }
            if (yf<yi && xf<xi) //verifica��o para cima e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1-i][xi-1-i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf][xf])=='p')
                        captura=1;
            }
            if (yf>yi && xf<xi) //verifica��o para cima e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1+i][xi-1-i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf-2][xf])=='p')
                        captura=1;
            }
            if (yf<yi && xf>xi) //verifica��o para baixo e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1-i][xi-1+i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf][xf-2])=='p')
                        captura=1;
            }
            if (abs(yi-yf)==abs(xi-xf) && caminho==0) //Verifica��o do caminho da dama para mov simples
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                mov=1;
            }
            if (abs(yi-yf)==abs(xi-xf) && caminho==1 && captura==1) //verifica��o para captura de pe�as pela dama
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                if (yf>yi && xf<xi)
                    tabuleiro[yf-2][xf]='0';
                if (yf>yi && xf>xi)
                    tabuleiro[yf-2][xf-2]='0';
                if (yf<yi && xf>xi)
                    tabuleiro[yf][xf-2]='0';
                if (yf<yi && xf<xi)
                    tabuleiro[yf][xf]='0';
                printf("\nDeseja capturar mais alguma peca? (s/n): ");
                scanf("\n%c",&op);
                if (op=='n')
                    mov=1;
                while (op!='n'){
                    caminho=0;
                    captura=0;
                    xi=xf;
                    yi=yf;
                    ImprimirTabuleiro();
                    do {
                        printf("\nInsira a coordenada da casa destino: ");
                        scanf("\n%d,%d",&yf,&xf);
                    } while (tabuleiro[yf-1][xf-1]!='0');
                    if (yf>yi && xf>xi) //verifica��o para baixo e para direita
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1+i][xi-1+i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf-2][xf-2])=='p')
                            captura=1;
                    }
                    if (yf<yi && xf<xi) //verifica��o para cima e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1-i][xi-1-i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf][xf])=='p')
                            captura=1;
                    }
                    if (yf>yi && xf<xi) //verifica��o para cima e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1+i][xi-1-i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf-2][xf])=='p')
                            captura=1;
                    }
                    if (yf<yi && xf>xi) //verifica��o para baixo e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1-i][xi-1+i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf][xf-2])=='p')
                            captura=1;
                    }
                    tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                    tabuleiro[yi-1][xi-1]='0';
                    if (yf>yi && xf<xi)
                        tabuleiro[yf-2][xf]='0';
                    if (yf>yi && xf>xi)
                        tabuleiro[yf-2][xf-2]='0';
                    if (yf<yi && xf>xi)
                        tabuleiro[yf][xf-2]='0';
                    if (yf<yi && xf<xi)
                        tabuleiro[yf][xf]='0';
                    printf("\nDeseja capturar mais alguma peca? (s/n): ");
                    scanf("\n%c",&op);
                    if (op=='n')
                        mov=1;
                }
            }
        }
        if (mov==0)
        {
            ImprimirTabuleiro();
            printf ("Mov Invalido! MOVIMENTAM AS BRANCAS! Tente novamente");
        }
    }while (mov==0);
}
void MovPreta () //Fun�ao de movimento das pe�as pretas
{
    char op;
    int xc, yc, caminho=0, captura;
    mov=0;
    do{
        do{
            printf ("\nInsira a coordenada da peca a ser movimentada: ");
            scanf("\n%d,%d",&yi,&xi);
        }while(tolower(tabuleiro[yi-1][xi-1])!=vez);
        do {
            printf("\nInsira a coordenada da casa destino: ");
            scanf("\n%d,%d",&yf,&xf);
        } while (tabuleiro[yf-1][xf-1]!='0');
        xc=(xi+xf)/2;
        yc=(yi+yf)/2;
        if (tabuleiro[yi-1][xi-1]=='p') //movimentar pe�a que n�o seja dama
        {
            if (yi-yf==1 && abs(xi-xf)==1)  //movimenta��o simples
            {
                tabuleiro [yf-1][xf-1]='p';
                tabuleiro[yi-1][xi-1]='0';
                mov=1;
            }
            else //comendo pe�a adversaria
            {
                if (yi-yf==2 && abs(xi-xf)==2 && tolower(tabuleiro[yc-1][xc-1])=='b')
                {
                    tabuleiro [yf-1][xf-1]='p';
                    tabuleiro[yi-1][xi-1]='0';
                    tabuleiro[yc-1][xc-1]='0';
                    printf("\nDeseja capturar mais alguma peca? (s/n): ");
                    scanf ("\n%c",&op);
                    if (op=='n')
                        mov=1;
                    while (op=='s') {
                        ImprimirTabuleiro();
                        xi=xf;
                        yi=yf;
                        do {
                            printf("\nInsira a coordenada da casa destino: ");
                            scanf("\n%d,%d",&yf,&xf);
                        } while (tabuleiro[yf-1][xf-1]!='0');
                        xc=(xi+xf)/2;
                        yc=(yi+yf)/2;
                        if (abs(yi-yf)==2 && abs(xi-xf)==2 && tolower(tabuleiro[yc-1][xc-1])=='b')
                        {
                            tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                            tabuleiro[yi-1][xi-1]='0';
                            tabuleiro[yc-1][xc-1]='0';
                            VerificaDama();
                            printf("\nDeseja comer mais alguma peca? (s/n): ");
                            scanf ("\n%c",&op);
                        }
                        else
                        {
                            printf ("\nMov Invalido! Deseja tentar capturar mais alguma peca? (s/n): ");
                            scanf ("\n%c",&op);
                        }
                        if (op=='n')
                            mov=1;
                        }
                }
            }
        }
        else //movimentar dama preta
        {
            caminho=0;
            captura=0;
            if (yf>yi && xf>xi) //verifica��o para baixo e para direita
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1+i][xi-1+i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf-2][xf-2])=='b')
                        captura=1;
            }
            if (yf<yi && xf<xi) //verifica��o para cima e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1-i][xi-1-i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf][xf])=='b')
                        captura=1;
            }
            if (yf>yi && xf<xi) //verifica��o para cima e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1+i][xi-1-i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf-2][xf])=='b')
                        captura=1;
            }
            if (yf<yi && xf>xi) //verifica��o para baixo e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1-i][xi-1+i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf][xf-2])=='b')
                        captura=1;
            }
            if (abs(yi-yf)==abs(xi-xf) && caminho==0) //Verifica��o do caminho da dama para mov simples
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                mov=1;
            }
            if (abs(yi-yf)==abs(xi-xf) && caminho==1 && captura==1) //verifica��o para captura de pe�as pela dama
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                if (yf>yi && xf<xi)
                    tabuleiro[yf-2][xf]='0';
                if (yf>yi && xf>xi)
                    tabuleiro[yf-2][xf-2]='0';
                if (yf<yi && xf>xi)
                    tabuleiro[yf][xf-2]='0';
                if (yf<yi && xf<xi)
                    tabuleiro[yf][xf]='0';
                printf("\nDeseja capturar mais alguma peca? (s/n): ");
                scanf("\n%c",&op);
                if (op=='n')
                    mov=1;
                while (op!='n'){
                    caminho=0;
                    captura=0;
                    xi=xf;
                    yi=yf;
                    ImprimirTabuleiro();
                    do {
                        printf("\nInsira a coordenada da casa destino: ");
                        scanf("\n%d,%d",&yf,&xf);
                    } while (tabuleiro[yf-1][xf-1]!='0');
                    if (yf>yi && xf>xi) //verifica��o para baixo e para direita
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1+i][xi-1+i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf-2][xf-2])=='b')
                            captura=1;
                    }
                    if (yf<yi && xf<xi) //verifica��o para cima e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1-i][xi-1-i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf][xf])=='b')
                            captura=1;
                    }
                    if (yf>yi && xf<xi) //verifica��o para cima e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1+i][xi-1-i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf-2][xf])=='b')
                            captura=1;
                    }
                    if (yf<yi && xf>xi) //verifica��o para baixo e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1-i][xi-1+i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf][xf-2])=='b')
                            captura=1;
                    }
                    tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                    tabuleiro[yi-1][xi-1]='0';
                    if (yf>yi && xf<xi)
                        tabuleiro[yf-2][xf]='0';
                    if (yf>yi && xf>xi)
                        tabuleiro[yf-2][xf-2]='0';
                    if (yf<yi && xf>xi)
                        tabuleiro[yf][xf-2]='0';
                    if (yf<yi && xf<xi)
                        tabuleiro[yf][xf]='0';
                    printf("\nDeseja capturar mais alguma peca? (s/n): ");
                    scanf("\n%c",&op);
                    if (op=='n')
                        mov=1;
                }
            }
        }
        if (mov==0)
        {
            ImprimirTabuleiro();
            printf ("Mov Invalido! MOVIMENTAM AS PRETAS! Tente novamente");
        }
    }while (mov==0);
}
void VerificaResultado() //fun��o que determina o resultado da partida
{
    int QntP=0, QntB=0, Qnt_DB=0, Qnt_DP=0;
    for (l=0;l<8;l++)
    {
        for (c=0;c<8;c++)
        {
            if (tolower(tabuleiro[l][c])=='p')
                QntP++;
            if (tolower(tabuleiro[l][c])=='b')
                QntB++;
            if    (tabuleiro[l][c]=='B')
                Qnt_DB++;
            if    (tabuleiro[l][c]=='P')
                Qnt_DP++;
        }
    }
    if ((Qnt_DP<=3 && Qnt_DB==1)||(Qnt_DP=1 &&Qnt_DB<=3))
        empate=20;
    if (empate!=100)
        empate--;
    if (QntP==0)
        venc=1;
    if (QntB==0)
        venc=2;
    if ((Qnt_DP==1 && Qnt_DB==1 && QntB==1 && QntP==1)||empate==0)
        venc=3;
}
void JogadorVsComputador() //Fun��o para gerar jogadas aleat�rias
{
    srand((unsigned)time(NULL)); //Fun��o srand gera n�meros aleat�rios, unsigned � para numeros naturais, e o time NULL para a semente do rand
    char op;
    int xc, yc, caminho=0, captura;
    mov=0;
    do{
        do{
            yi=rand()%9; //gera��o de numeros de 1 a 8
            xi=rand()%9; //gera��o de numeros de 1 a 8
        }while(tolower(tabuleiro[yi-1][xi-1])!=vez);
        do {
            yf=rand()%9;
            xf=rand()%9;
        } while (tabuleiro[yf-1][xf-1]!='0');
        xc=(xi+xf)/2;
        yc=(yi+yf)/2;
        if (tabuleiro[yi-1][xi-1]=='p')//movimentar pe�a que n�o seja dama
        {
            if (yi-yf==1 && abs(xi-xf)==1)//movimenta��o simples
            {
                tabuleiro [yf-1][xf-1]='p';
                tabuleiro[yi-1][xi-1]='0';
                mov=1;
            }
            else //comendo pe�as adversaria
            {
                if (yi-yf==2 && abs(xi-xf)==2 && tolower(tabuleiro[yc-1][xc-1])=='b')
                {
                    tabuleiro [yf-1][xf-1]='p';
                    tabuleiro[yi-1][xi-1]='0';
                    tabuleiro[yc-1][xc-1]='0';
                    printf("\nDeseja comer mais alguma peca? (s/n): ");
                    scanf ("\n%c",&op);
                    if (op=='n')
                        mov=1;
                    while (op=='s') {
                        ImprimirTabuleiro();
                        xi=xf;
                        yi=yf;
                        do {
                            printf("\nInsira a coordenada da casa destino: ");
                            scanf("\n%d,%d",&yf,&xf);
                        } while (tabuleiro[yf-1][xf-1]!='0');
                        xc=(xi+xf)/2;
                        yc=(yi+yf)/2;
                        if (abs(yi-yf)==2 && abs(xi-xf)==2 && tolower(tabuleiro[yc-1][xc-1])=='b')
                        {
                            tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                            tabuleiro[yi-1][xi-1]='0';
                            tabuleiro[yc-1][xc-1]='0';
                        }
                        VerificaDama();
                        printf("\nDeseja comer mais alguma peca? (s/n): ");
                        scanf ("\n%c",&op);
                        if (op=='n')
                            mov=1;
                        }
                }
            }
        }
        else //movimentar dama
        {
            caminho=0;
            captura=0;
            if (yf>yi && xf>xi) //verifica��o para baixo e para direita
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1+i][xi-1+i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf-2][xf-2])=='b')
                        captura=1;
            }
            if (yf<yi && xf<xi) //verifica��o para cima e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1-i][xi-1-i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf][xf])=='b')
                        captura=1;
            }
            if (yf>yi && xf<xi) //verifica��o para cima e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1+i][xi-1-i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf-2][xf])=='b')
                        captura=1;
            }
            if (yf<yi && xf>xi) //verifica��o para baixo e para esquerda
            {
                for (int i = 1; i<=abs (xi-xf);i++)
                    if (tabuleiro[yi-1-i][xi-1+i]!='0')
                        caminho++;
                if (tolower(tabuleiro[yf][xf-2])=='b')
                        captura=1;
            }
            if (abs(yi-yf)==abs(xi-xf) && caminho==0) //Verifica��o do caminho da dama para mov simples
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                mov=1;
            }
            if (abs(yi-yf)==abs(xi-xf) && caminho==1 && captura==1) //verifica��o para captura de pe�as pela dama
            {
                tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                tabuleiro[yi-1][xi-1]='0';
                if (yf>yi && xf<xi)
                    tabuleiro[yf-2][xf]='0';
                if (yf>yi && xf>xi)
                    tabuleiro[yf-2][xf-2]='0';
                if (yf<yi && xf>xi)
                    tabuleiro[yf][xf-2]='0';
                if (yf<yi && xf<xi)
                    tabuleiro[yf][xf]='0';
                printf("\nDeseja capturar mais alguma peca? (s/n): ");
                scanf("\n%c",&op);
                if (op=='n')
                    mov=1;
                while (op!='n'){
                    caminho=0;
                    captura=0;
                    xi=xf;
                    yi=yf;
                    ImprimirTabuleiro();
                    do {
                        printf("\nInsira a coordenada da casa destino: ");
                        scanf("\n%d,%d",&yf,&xf);
                    } while (tabuleiro[yf-1][xf-1]!='0');
                    if (yf>yi && xf>xi) //verifica��o para baixo e para direita
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1+i][xi-1+i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf-2][xf-2])=='b')
                            captura=1;
                    }
                    if (yf<yi && xf<xi) //verifica��o para cima e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1-i][xi-1-i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf][xf])=='b')
                            captura=1;
                    }
                    if (yf>yi && xf<xi) //verifica��o para cima e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1+i][xi-1-i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf-2][xf])=='b')
                            captura=1;
                    }
                    if (yf<yi && xf>xi) //verifica��o para baixo e para esquerda
                    {
                        for (int i = 1; i<=abs (xi-xf);i++)
                            if (tabuleiro[yi-1-i][xi-1+i]!='0')
                                caminho++;
                        if (tolower(tabuleiro[yf][xf-2])=='b')
                            captura=1;
                    }
                    tabuleiro [yf-1][xf-1]=tabuleiro[yi-1][xi-1];
                    tabuleiro[yi-1][xi-1]='0';
                    if (yf>yi && xf<xi)
                        tabuleiro[yf-2][xf]='0';
                    if (yf>yi && xf>xi)
                        tabuleiro[yf-2][xf-2]='0';
                    if (yf<yi && xf>xi)
                        tabuleiro[yf][xf-2]='0';
                    if (yf<yi && xf<xi)
                        tabuleiro[yf][xf]='0';
                    printf("\nDeseja capturar mais alguma peca? (s/n): ");
                    scanf("\n%c",&op);
                    if (op=='n')
                        mov=1;
                }
            }
        }
        if (mov==0)
        {
            ImprimirTabuleiro();
            printf ("Mov Invalido! Tente novamente");
        }
    }while (mov==0);
}
int main ()
{
    int turn_b=0, turn_p=0, turn=0;
    float OpcaoInicial;

    do
    {
      system("cls");
      printf("\tBem Vindo(a) ao jogo de damas!!\n\tQual opcao deseja?\n\n\t1 - Jogador vs Computador\n\t2 - Jogador vs Jogador\n\t3 - Sair\n");
      scanf("\n%f", &OpcaoInicial);
    }while(OpcaoInicial<1||OpcaoInicial>3);
    if(OpcaoInicial==3)
      return 0;
    do{
    if (turn%2==0)
    {
        vez='b';
        ImprimirTabuleiro();
        printf("\nMovimentam as BRANCAS!");
        MovBranca();
        turn_b++;
    }
    else
    {
        vez='p';
        ImprimirTabuleiro();
        printf("\nMovimentam as PRETAS!");
        if (OpcaoInicial==1)
                JogadorVsComputador();
        else MovPreta();
        turn_p++;
    }
    VerificaDama();
    VerificaResultado ();
    ImprimirTabuleiro();
    turn++;
    }while (venc==0);
    ImprimirTabuleiro();
    switch (venc)
    {
        case 1: printf("\nO Venceram as BRANCAS.\nAs brancas moveram %d vezes e as pretas, %d vezes.",turn_b, turn_p);
        break;
        case 2: printf("\nO Venceram as PRETAS.\nAs pretas moveram %d vezes e as brancas, %d vezes.",turn_p, turn_b);
        break;
        case 3: printf("\nO jogo empatou.\nAs brancas moveram %d vezes e as pretas, %d vezes.",turn_b, turn_p);
        break;
    }
    return 0;
  }
