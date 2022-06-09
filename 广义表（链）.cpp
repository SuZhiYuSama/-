#include<iostream>
#include<string.h>
using namespace std;
#define MAXSIZE 1000000
typedef enum{ATOM,LIST}ElemTag;
typedef struct GLNODE{
	ElemTag tag;
	union{
		char atom;
		struct {struct GLNODE *hp,*tp;}ptr;
	};
}*GList;
Status CreateGList(GList &L,char *S)
GList GetHead(GList L)
GList GetTail(GList L)
void DestroyGList(GList &L)
void PrintGList(GList L)
int main(){
	int i=0;
	char List[MAXSIZE];
	while(getchar()!='\n'){
		List[i]=getchar();
		i++;
	}
	i=0;
	CreateGList();
	cout<<"generic list:";
	PrintGlist();
	
}
