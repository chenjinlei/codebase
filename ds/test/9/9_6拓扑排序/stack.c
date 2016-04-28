Status InitStack(SqStack *S) 
{ 
S->base=(SET *)malloc(STACK_INIT_SIZE*sizeof(SET)); 
if(!S->base) 
return OVERFLOW; 
S->top=S->base; 
S->stacksize=STACK_INIT_SIZE; 
return OK; 
} 
Status StackEmpty(SqStack S) 
{ 
if(S.base==S.top) 
return OK; 
else 
return FALSE; 
} 

Status DestroyStack(SqStack *S) 
{ 
free(S->base); 
return OK; 
} 
Status ClearStack(SqStack *S) 
{ 
SET e; 
if(S->base==S->top) 
return ERROR; 
while(S->base!=S->top) 
Pop(S,&e); 
return OK; 
} 

Status StackLength(SqStack S) 
{ 
return (S.top-S.base); 
} 

Status GetTop(SqStack S,SET *e) 
{ 
if(S.base==S.top) 
return ERROR; 
*e=*(S.top-1); 
return OK; 
} 

SET GetTop_v1(SqStack S) 
{ 
if(S.base==S.top) 
return ERROR; 
return *(S.top-1); 
} 


Status Push(SqStack *S,SET e) 
{ 
if(S->top-S->base>=S->stacksize) 
{ 
S->base=(SET *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SET)); 
if(!S->base) 
return OVERFLOW; 
S->top=S->base+S->stacksize; 
S->stacksize+=STACKINCREMENT; 
} 
*(S->top)++=e; 
return OK; 
} 

Status Pop(SqStack *S,SET *e) 
{ 
if(S->base==S->top) 
return ERROR; 
*e=*(--S->top); 
return OK; 
} 