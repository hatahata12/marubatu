#include <stdio.h>  
#include <stdlib.h>
#define X 3 //��
#define Y 3 //�c
#define N 3 //�S�̒l
void Tel(void);//�̈�쐬�֐�
void Con(void);//�R���s���[�^�[�w��֐�
int Sh(void);//���s�`�F�b�N�֐�
int Sh2(void);//���s�`�F�b�N�֐�
int check(int y1,int x1);//�d���`�F�b�N�֐�
int a[Y][X]; //�O���[�o���ϐ�
int main (void)
{
 int i,j,yc,xc,c,k ;
	
	
 printf ("\nX�͉��AY�͏c�̎w��\n\n");

 while(1){	
	for(i=0 ; i<Y ; i++){
		for(j=0 ; j<X ; j++){
			a[i][j]=0;
		}
	}
	
	printf ("���H(0)���H(1)\n");scanf("%d",&k);
	if (k==1){
		Con();
	}
	
	//�\�̌Ăяo��
	
	Tel();
	
	
  //�ŏ��̓���
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
				printf ("�d���G���[\n");
			}
	   }
		else {
			printf ("�w��G���[\n");
		}
	}
		
  	
  	 //�R���s���[�^����
		
  	 Con();
		
  	//�̈�쐬����
  	
  	Tel();
		
  	//���s�`�F�b�N����
  	
  	if (Sh()==1){
  		printf("���Ȃ��̏����ł�");
  		break ;
  	}
  	else if (Sh()==-1){
  		printf("���Ȃ��̕����ł�");
  		break ;
  	}
	else if (Sh2()==2){
		printf("���������ł�");
		break;
	}
	else if (Sh2()==-2){
		printf("���������ł�");
		break;
	}
  }
   	printf("\n�����܂����H YES(0) NO(1)\n");scanf("%d",&k);
  	if(k==1){
  		break ;
  	}
 }
	return 0 ;
}
	

void Tel(void){
 int i,j;
	system("cls"); //��ʂ̏�����
	
	printf ("   0 1 2\n");
	printf ("---------\n");
	
    //��ʏo��
	
	for(i=0 ; i<Y ; i++){
		printf ("%d |",i);
		for(j=0 ; j<X ; j++){
	     switch(a[i][j]){
         case 1:
          printf("��");
         break;
         case 2:
          printf("�~");
         break;
	     default:
	      printf("�@");
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
