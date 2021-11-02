/* CSCI1510
 * Assignment : 6
 * Student ID : 1155143928
 * Name : Hung Man Kit
 * Email : samhung20011125@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include"zebraspath.h"

//Updating//
void initZebrasPath(ZebrasPath *p, int r, int c){
    int i,j;
    j=0;
    //Assigning the board//

    for(i=0;i<8;i++){
        p->board[i][j] = -1;
        if(i+j==14){
            break;
        }
        if(i==7){
            j++;
            i=-1;
        }
    }
    //Assigning the values//
    p->board[r][c]=0;
    p->currentR = r;
    p->currentC = c;
    p->steps = 0;
}
 
void printZebrasPath(const ZebrasPath *p){
    int i=0;
    int j=0;
    //Printing the initial pattern//
    printf("   0  1  2  3  4  5  6  7\n");
    printf("%d",i);
    for(j=0;j<8;j++){
        printf(" ");
        
        if (p->board[i][j]==-1){
            printf(" .");
        }
        //Initial po//
        else if(p->board[i][j]==0){
            printf(" z");
            
        }
        //Current pos//
        else if(i== p->currentR && j==p->currentC && p->board[i][j]!=0){
           
                printf(" Z");
            }
        
        else{
            printf("%2d",p->board[i][j]);
        }

        if(i+j==14){
            printf("\n");
            break;
        }
        if(j==7){
            j=(-1);
            printf("\n");
            i++;
            printf("%d",i);
        }
        }
    //Steps print//
    printf("Steps: %d\n",p->steps);
        
    }
//Check validity//
bool isZebraMoveValid(const ZebrasPath *p, int r, int c){
    int abs_r = abs( p->currentR - r);
    int abs_c = abs( p->currentC - c);
    if((r<=7 && r>=0)&&(c<=7 && c>=0)&&(p->board[r][c]==-1)&&((abs_r==2 && abs_c ==3)||(abs_r==3 && abs_c ==2))){
        return true;
    }else{
        return false;
    }
    
}

bool hasMoreZebraMoves(const ZebrasPath *p){
    //Caes that have more moves//
    if (isZebraMoveValid(p, p->currentR+3, p->currentC+2)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR+3, p->currentC-2)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR-3, p->currentC+2)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR-3, p->currentC-2)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR+2, p->currentC+3)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR+2, p->currentC-3)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR-2, p->currentC+3)==true){
        return true;
    }else if (isZebraMoveValid(p, p->currentR-2, p->currentC-3)==true){
        return true;
    }else{
        return false;
    }
    
}


bool moveZebra(ZebrasPath *p, int r, int c){
    if((isZebraMoveValid(p, r, c)==true)){
    p->steps++;
    if( p->board[p->currentR][p->currentC] > 0){
        //Now values//
    p->board[p->currentR][p->currentC] = p->steps-1;
    }
    p->currentC = c ;
    p->currentR = r ;
    p->board[r][c]=p->steps;
    return true;
    }else{
        return false;
    }
}

