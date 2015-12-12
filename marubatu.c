#include <stdio.h>  
#include <stdlib.h>
#define X 3 //横
#define Y 3 //縦
#define N 3 //全体値
void Tel(void);//領域作成関数
void Con(void);//コンピューター指定関数
int Sh(void);//勝敗チェック関数
int Sh2(void);//勝敗チェック関数
int check(int y1,int x1);//重複チェック関数
int a[Y][X]; //グローバル変数
int main (void)
{
 int i,j,yc,xc,c,k ;
	
	
 printf ("\nXは横、Yは縦の指定\n\n");

 while(1){	
	for(i=0 ; i<Y ; i++){
		for(j=0 ; j<X ; j++){
			a[i][j]=0;
		}
	}
	
	printf ("先手？(0)後手？(1)\n");scanf("%d",&k);
	if (k==1){
		Con();
	}
	
	//表の呼び出し
	
	Tel();
	
	
  //最初の入力
  while(1){
	while (1){
		printf("Y=");scanf("%d",&yc);
		printf("X=");scanf("%d",&xc);
		if(yc<X && xc<Y && yc>=0 && xc>=0){
		c=check(yc,xc);
		if(c>0){
			a[yc][xc]=1;
		    break ;
		}
			else {
				printf ("重複エラー\n");
			}
	   }
		else {
			printf ("指定エラー\n");
		}
	}
		
  	
  	 //コンピュータ処理
		
  	 Con();
		
  	//領域作成処理
  	
  	Tel();
		
  	//勝敗チェック処理
  	
  	if (Sh()==1){
  		printf("あなたの勝ちです");
  		break ;
  	}
  	else if (Sh()==-1){
  		printf("あなたの負けです");
  		break ;
  	}
	else if (Sh2()==2){
		printf("引き分けです");
		break;
	}
	else if (Sh2()==-2){
		printf("引き分けです");
		break;
	}
  }
   	printf("\n続けますか？ YES(0) NO(1)\n");scanf("%d",&k);
  	if(k==1){
  		break ;
  	}
 }
	return 0 ;
}
	

void Tel(void){
 int i,j;
	system("cls"); //画面の初期化
	
	printf ("   0 1 2\n");
	printf ("---------\n");
	
    //画面出力
	
	for(i=0 ; i<Y ; i++){
		printf ("%d |",i);
		for(j=0 ; j<X ; j++){
	     switch(a[i][j]){
         case 1:
          printf("○");
         break;
         case 2:
          printf("×");
         break;
	     default:
	      printf("　");
	     break;
		}
	}
	  printf("\n");
   }
	printf ("---------\n");
}

int check(int y1,int x1){
 if(a[y1][x1]==0){
    return 1 ;
  }
  else {
    return -1 ;
  }
}

void Con(void){
 int r,rr,c,i,j,sum=0;
	for (i=0 ; i<Y ; i++){
		for(j=0 ; j<X ; j++){
			sum+=a[i][j];
		}
	}
	srand((unsigned)time(NULL));
	if(sum!=13){
	while(1){
		r=rand()%N;
		rr=rand()%N;
		c=check(r,rr);
		if(c>0){
			a[r][rr]=2;
		    break ;
		}
	}
   }
}

int Sh(void){

int i,j,sum=0,sun=1,sum1=0,sun1=1,sum2=0,sun2=1,sum3=0,sun3=1 ;
	
for (i=0 ; i<3 ; i++){
 for (j=0 ; j< 3 ; j++){
  
   sum+=a[i][j];
   sun*=a[i][j];
  sum1+=a[j][i];
  sun1*=a[j][i];
 }
  if (sum==3 && sun>0 || sum1==3 && sun1>0){
   return 1 ;
  }
   else if (sum==6 && sun>0 || sum1==6 && sun1>0){
    return -1 ;
   }
    sum=sum1=0; sun=sun1=1 ;
   
    sum2+=a[i][i];
    sun2*=a[i][i];
   sum3+=a[i][2-i];
   sun3*=a[i][2-i];
  }
   if (sum2==3 && sun2>0 || sum3==3 && sun3>0){
    return 1;
   }
    else if (sum2==6 && sun2>0 || sum3==6 && sun3>0){
     return -1;
    }
   return 0;
}

int Sh2(void){
	int i,j,sum=0 ;
	for (i=0 ; i<Y ; i++){
		for(j=0 ; j<X ; j++){
			sum+=a[i][j];
		}
	}
	if(sum==13){
	  return 2;
	}
	if(sum==14){
	  return-2;
	}
  return 0;
}
