#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct book{ // 入库
	int shuhao;
	char bookName[8];
	char author[8];
	int all; //总库存
	int now; // 当前书号一样的书本
 }BOOK;
typedef struct user{ // 入库
	int shuhao;
	char bookName[8];
	char author[8];
	int mark; // 标记还书没有
	int bw_all; // 借的所有书数
 }USER;
 typedef struct _Sqlist{ //线性表的结构体
     BOOK *elem;    //起始地址
	 USER *bro;
     int length;
     int maxSize;
 }SqList;

SqList* InitList(int maxSize);
void ruku(SqList *ls,BOOK *list,int i);
void PrintElem(BOOK *list);
void PrintAllElem(SqList *ls);
void save(SqList *ls);
void pipei(SqList *temp); //从文件中提取出来原来的数据，输入的如果是一样的书号，那么now++,否则是all++
void borrow(USER *list,int lengt);
void return_book(SqList *ls,USER *list,int lengt);

SqList* InitList(int maxSize) { //初始化
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
void ruku(SqList *ls,BOOK *list,int i){// 将书入库，并存到文件之中
    int j=0;
    BOOK *temp=NULL;
    if(list==NULL || ls==NULL || ls->length>=ls->maxSize || i<1 || i>ls->length+1){
		printf("线性表异常\n");
		return;
	}
    temp=ls->elem+i-1;
    
    for(j=ls->length;j>i;j--) {// 插入
        *(ls->elem+j)=*(ls->elem+j-1);
    }
    memcpy(temp,list,sizeof(BOOK));// 内存拷贝函数
    ls->length++;
	PrintAllElem(ls);
	save(ls,temp);
}
void PrintElem(BOOK *list){// 输出单条数据
    printf("%d %s %s %d %d\n",list->shuhao,list->bookName,list->author,list->now,list->all);
}
void PrintAllElem(SqList *ls){
    int i=0;
    if(ls==NULL || ls->elem==NULL || ls->length==0){
        printf("表空\n");
		return;
	}
	printf("书号 书名 作者 当前 总的\n");
    for(;i<ls->length;i++){
        PrintElem(ls->elem+i);
    }
}
void save(SqList *ls,BOOK *list){ // 保存函数
	FILE *fp;
	int i=0;
	if((fp=fopen("book.txt","w"))==NULL){
		printf("文件打开失败\n");
		exit(0);
	}
	for(;i<ls->length;i++){
		list = ls->elem+i;
        fprintf(fp,"%d %s %s %d %d \n",list->shuhao,list->bookName,list->author,list->now,list->all);
    }
	fclose(fp);
	printf("保存成功\n");
}
void borrow(USER *list,int lengt){// 借书
    int i,j=0;
    USER *temp=NULL;
	FILE *fp;
	if((fp=fopen("user.txt","a"))==NULL){
		printf("文件打开失败\n");
		exit(0);
	}
    if(list==NULL){
		printf("线性表异常\n");
		return;
	}
	fprintf(fp,"%d %s %s %d %d \n",list->shuhao,list->bookName,list->author,list->mark,list->bw_all);
	printf("借书成功\n");
	fclose(fp);
}
void return_book(SqList *ls,USER *list,int lengt){// 借书
    int i,j=0;
    USER *temp=NULL;
	FILE *fp;
	if((fp=fopen("user.txt","w"))==NULL){
		printf("文件打开失败\n");
		exit(0);
	}
	//printf("%d",lengt);
	for(i=0;i<lengt;i++){
		list = ls->bro+i;
		fprintf(fp,"%d %s %s %d %d \n",list->shuhao,list->bookName,list->author,list->mark,list->bw_all);
	}
	printf("还书成功\n");
	fclose(fp);
}
void pipei(SqList *temp){// 从文件中读取并输出 匹配之后入库
	int i;
	FILE *fp;
	temp=(SqList *)malloc(sizeof(SqList));
	temp->elem=(BOOK *)malloc(100*sizeof(BOOK));
	if((fp=fopen("book.txt","rt"))==NULL){
		printf("文件读取失败");
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
	int flag=1;  //判断结束
    int operate;   //操作数    
    int i,j,x,y;     //要删除的位置
	FILE *fp;
    BOOK temp;
	BOOK bro_book;
	USER bro_temp;
    SqList *head=NULL;
	SqList *p = NULL;
	SqList *bro = NULL;//借书的
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
		printf("空的");
	}
    while(flag){
        printf("1.入库\n2.匹配\n3.已入库的所有书\n4.借书\n5.还书\n6.保存\n7.参编入库\n8.退出\n请选择要执行的操作：");
        scanf("%d",&operate);
        printf("\n");
        switch (operate){
          case 1:
              printf("请输入书号:");
              scanf("%ld",&temp.shuhao);
              printf("请输入书名:");
              scanf("%s",&temp.bookName);
			  printf("请输入作者:");
              scanf("%s",&temp.author);
			  if((fp=fopen("book.txt","rt"))==NULL){
				printf("文件读取失败");
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
					printf("表空\n");
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
			  // 将数据提取出来与要借的书号匹配
			  printf("请输入书号:");
              scanf("%ld",&bro_temp.shuhao);
			 if((fp=fopen("book.txt","rt"))==NULL){
				printf("文件读取失败");
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
					printf("你没借书\n");
			  }else{
					for(y=0;y<x-1;y++){
						if(bro_temp.shuhao==q->elem[y].shuhao){
							bro_temp.mark = 1;
							bro_temp.bw_all++;
							strcpy(bro_temp.bookName,q->elem[y].bookName);
							strcpy(bro_temp.author,q->elem[y].author);
						}else{
							//printf("没有这本书\n");
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
				printf("文件读取失败");
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
			  printf("书号 书名 作者\n");
			  for(y=0;y<x-1;y++){
					printf("%d %s %s\n",q->bro[y].shuhao,q->bro[y].bookName,q->bro[y].author);
			  }
			  printf("你当前借的书总数:%d\n",q->bro[x-2].bw_all);
			  printf("选择你要还的书(书号):");
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
							printf("你借的书之中没有这本书\n");
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
              printf("请输入正确的操作\n");                      
        }          
    }
}
int main(){
	menu();
    system("pause");
    return 0;
}