#define STACK_INIT_SIZE 100 

#define STACKINCREMENT 10 
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INFEASIBLE -1 
#define OVERFLOW -2 
#define NULL 0 

typedef int TET; 
/* 
typedef struct BiTNode 
{ 
TET data; 
struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree; 
*/ 
typedef int SET; 

typedef int Status; 
typedef struct 
{ 
SET *base; 
SET *top; 
int stacksize; 
}SqStack; 

Status InitStack(SqStack *S); 
Status DestroyStack(SqStack *S); 
Status ClearStack(SqStack *S); 
Status StackEmpty(SqStack S); 
Status StackLength(SqStack S); 
Status GetTop(SqStack S,SET *e); 
Status Push(SqStack *S,SET e); 
Status Pop(SqStack *S,SET *e); 