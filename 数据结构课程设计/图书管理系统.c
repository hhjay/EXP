#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct book{ // ���
	int shuhao;
	char bookName[8];
	char author[8];
	int all; //�ܿ��
	int now; // ��ǰ���һ�����鱾
 }BOOK;
typedef struct user{ // ���
	int shuhao;
	char bookName[8];
	char author[8];
	int mark; // ��ǻ���û��
	int bw_all; // �����������
 }USER;
 typedef struct _Sqlist{ //���Ա�Ľṹ��
     BOOK *elem;    //��ʼ��ַ
	 USER *bro;
     int length;
     int maxSize;
 }SqList;

SqList* InitList(int maxSize);
void ruku(SqList *ls,BOOK *list,int i);
void PrintElem(BOOK *list);
void PrintAllElem(SqList *ls);
void save(SqList *ls);
void pipei(SqList *temp); //���ļ�����ȡ����ԭ�������ݣ�����������һ������ţ���ônow++,������all++
void borrow(USER *list,int lengt);
void return_book(SqList *ls,USER *list,int lengt);

SqList* InitList(int maxSize) { //��ʼ��
	SqList *head=NULL;
    head=(SqList *)malloc(sizeof(SqList));
    if(head==NULL)
      return NULL;

    head->elem=(BOOK *)malloc(maxSize*sizeof(BOOK));
	head->bro=(USER *)malloc(maxSize*sizeof(USER));
    if(head->elem==NULL)
      return NULL;
	if(head->bro==NULL)
      return NULL;

    head->length=0;
    head->maxSize=maxSize;
    return head;
}
void ruku(SqList *ls,BOOK *list,int i){// ������⣬���浽�ļ�֮��
    int j=0;
    BOOK *temp=NULL;
    if(list==NULL || ls==NULL || ls->length>=ls->maxSize || i<1 || i>ls->length+1){
		printf("���Ա��쳣\n");
		return;
	}
    temp=ls->elem+i-1;
    
    for(j=ls->length;j>i;j--) {// ����
        *(ls->elem+j)=*(ls->elem+j-1);
    }
    memcpy(temp,list,sizeof(BOOK));// �ڴ濽������
    ls->length++;
	PrintAllElem(ls);
	save(ls,temp);
}
void PrintElem(BOOK *list){// �����������
    printf("%d %s %s %d %d\n",list->shuhao,list->bookName,list->author,list->now,list->all);
}
void PrintAllElem(SqList *ls){
    int i=0;
    if(ls==NULL || ls->elem==NULL || ls->length==0){
        printf("���\n");
		return;
	}
	printf("��� ���� ���� ��ǰ �ܵ�\n");
    for(;i<ls->length;i++){
        PrintElem(ls->elem+i);
    }
}
void save(SqList *ls,BOOK *list){ // ���溯��
	FILE *fp;
	int i=0;
	if((fp=fopen("book.txt","w"))==NULL){
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	for(;i<ls->length;i++){
		list = ls->elem+i;
        fprintf(fp,"%d %s %s %d %d \n",list->shuhao,list->bookName,list->author,list->now,list->all);
    }
	fclose(fp);
	printf("����ɹ�\n");
}
void borrow(USER *list,int lengt){// ����
    int i,j=0;
    USER *temp=NULL;
	FILE *fp;
	if((fp=fopen("user.txt","a"))==NULL){
		printf("�ļ���ʧ��\n");
		exit(0);
	}
    if(list==NULL){
		printf("���Ա��쳣\n");
		return;
	}
	fprintf(fp,"%d %s %s %d %d \n",list->shuhao,list->bookName,list->author,list->mark,list->bw_all);
	printf("����ɹ�\n");
	fclose(fp);
}
void return_book(SqList *ls,USER *list,int lengt){// ����
    int i,j=0;
    USER *temp=NULL;
	FILE *fp;
	if((fp=fopen("user.txt","w"))==NULL){
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	//printf("%d",lengt);
	for(i=0;i<lengt;i++){
		list = ls->bro+i;
		fprintf(fp,"%d %s %s %d %d \n",list->shuhao,list->bookName,list->author,list->mark,list->bw_all);
	}
	printf("����ɹ�\n");
	fclose(fp);
}
void pipei(SqList *temp){// ���ļ��ж�ȡ����� ƥ��֮�����
	int i;
	FILE *fp;
	temp=(SqList *)malloc(sizeof(SqList));
	temp->elem=(BOOK *)malloc(100*sizeof(BOOK));
	if((fp=fopen("book.txt","rt"))==NULL){
		printf("�ļ���ȡʧ��");
		exit(0);
	}
	for(i=0;!feof(fp);i++){
		fscanf(fp,"%d",&temp->elem[i].shuhao);
		fscanf(fp,"%s",temp->elem[i].bookName);
		fscanf(fp,"%s",temp->elem[i].author);
		fscanf(fp,"%d",&temp->elem[i].now);
		fscanf(fp,"%d",&temp->elem[i].all);
	}
	temp->length=i-1;
	PrintAllElem(temp);
	fclose(fp);
	//return temp;
}

 void menu(){
	int flag=1;  //�жϽ���
    int operate;   //������    
    int i,j,x,y;     //Ҫɾ����λ��
	FILE *fp;
    BOOK temp;
	BOOK bro_book;
	USER bro_temp;
    SqList *head=NULL;
	SqList *p = NULL;
	SqList *bro = NULL;//�����
	SqList *q = NULL;
	bro = InitList(100);
    head = InitList(100);
	p = InitList(100);
	q = InitList(100);
	temp.now = 1;
	temp.all = 1;
	bro_temp.mark = 0;
	bro_temp.bw_all = 0;
    if(head==NULL){
        return 1;
		printf("�յ�");
	}
    while(flag){
        printf("1.���\n2.ƥ��\n3.������������\n4.����\n5.����\n6.����\n7.�α����\n8.�˳�\n��ѡ��Ҫִ�еĲ�����");
        scanf("%d",&operate);
        printf("\n");
        switch (operate){
          case 1:
              printf("���������:");
              scanf("%ld",&temp.shuhao);
              printf("����������:");
              scanf("%s",&temp.bookName);
			  printf("����������:");
              scanf("%s",&temp.author);
			  if((fp=fopen("book.txt","rt"))==NULL){
				printf("�ļ���ȡʧ��");
				exit(0);
			  }
			  for(i=0;!feof(fp);i++){
				 fscanf(fp,"%d",&p->elem[i].shuhao);
				 fscanf(fp,"%s",p->elem[i].bookName);
				 fscanf(fp,"%s",p->elem[i].author);
				 fscanf(fp,"%d",&p->elem[i].now);
				 fscanf(fp,"%d",&p->elem[i].all);
			  }
			  fclose(fp);
			  p->length=i-1;
			  if(p==NULL || p->elem==NULL || p->length==0 || head->length==0){
					printf("���\n");
			  }else{
					for(j=0;j<i-1;j++){
						if(p->elem[j].shuhao==temp.shuhao){
							temp.now = p->elem[j].now + 1;
							temp.all = p->elem[j].all + 1;
							*(head->elem+j)=*(head->elem+j-1);
							head->length = head->length - 1;
						}else{
							temp.now = 1;
							temp.all = p->elem[j].all + 1;
						}
					}
			  }
              ruku(head,&temp,head->length+1);
              break;
		  case 2:
			  pipei(p);
			  break;
		  case 3:
			  PrintAllElem(head);
			  break;
		  case 4:
			  // ��������ȡ������Ҫ������ƥ��
			  printf("���������:");
              scanf("%ld",&bro_temp.shuhao);
			 if((fp=fopen("book.txt","rt"))==NULL){
				printf("�ļ���ȡʧ��");
				exit(0);
			  }
			  for(x=0;!feof(fp);x++){
				 fscanf(fp,"%d",&q->elem[x].shuhao);
				 fscanf(fp,"%s",q->elem[x].bookName);
				 fscanf(fp,"%s",q->elem[x].author);
				 fscanf(fp,"%d",&q->elem[x].now);
				 fscanf(fp,"%d",&q->elem[x].all);
			  }
			  fclose(fp);
			  q->length=x-1;
			  printf("%d",x);
			  if(q==NULL || q->elem==NULL || q->length==0){
					printf("��û����\n");
			  }else{
					for(y=0;y<x-1;y++){
						if(bro_temp.shuhao==q->elem[y].shuhao){
							bro_temp.mark = 1;
							bro_temp.bw_all++;
							strcpy(bro_temp.bookName,q->elem[y].bookName);
							strcpy(bro_temp.author,q->elem[y].author);
						}else{
							//printf("û���Ȿ��\n");
							continue;
						}
					}
					
			  }
			  borrow(&bro_temp,x);
			  break;
		  case 5:
			 q->length = 0;
			 bro->length = 0;
			 if((fp=fopen("user.txt","rt"))==NULL){
				printf("�ļ���ȡʧ��");
				exit(0);
			  }
			  for(x=0;!feof(fp);x++){
				 fscanf(fp,"%d",&q->bro[x].shuhao);
				 fscanf(fp,"%s",q->bro[x].bookName);
				 fscanf(fp,"%s",q->bro[x].author);
				 fscanf(fp,"%d",&q->bro[x].mark);
				 fscanf(fp,"%d",&q->bro[x].bw_all);
			  }
			  fclose(fp);
			  printf("��� ���� ����\n");
			  for(y=0;y<x-1;y++){
					printf("%d %s %s\n",q->bro[y].shuhao,q->bro[y].bookName,q->bro[y].author);
			  }
			  printf("�㵱ǰ���������:%d\n",q->bro[x-2].bw_all);
			  printf("ѡ����Ҫ������(���):");
			  scanf("%ld",&bro_temp.shuhao);
			  for(y=0;y<x-1;y++){
						if(bro_temp.shuhao==q->bro[y].shuhao){
							//bro_temp.mark = 0;
							//bro_temp.bw_all = q->bro[y].bw_all - 1;
							q->bro[y].bw_all = q->bro[y].bw_all - 1;
							q->bro[y].mark = 0;
							//strcpy(bro_temp.bookName,q->bro[y].bookName);
							//strcpy(bro_temp.author,q->bro[y].author);
							break;
						}else{
							printf("������֮��û���Ȿ��\n");
							continue;
						}
			  }
			  //printf("%d",bro_temp.mark);
			  return_book(q,&bro_temp,x-1);
			  break;
		  case 8:
			  flag = 0;
			  break;
          default:
              printf("��������ȷ�Ĳ���\n");                      
        }          
    }
}
int main(){
	menu();
    system("pause");
    return 0;
}