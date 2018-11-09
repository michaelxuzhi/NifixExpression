#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
  
#define STACK_INIT_SIZE 20  
#define STACKINCREMENT 10  
#define MAXBUFFER   10  
  
typedef char ElemType;  
typedef struct  
{  
    ElemType *base;  
    ElemType *top;  
    int stackSize;  
}sqStack;  
  
void InitStack(sqStack *s)  
{  
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));  
    if( !s->base )  
        exit(0);  
  
    s->top = s->base;  
    s->stackSize = STACK_INIT_SIZE;  
  
}  
  
void Push(sqStack *s, ElemType e)  
{  
    //���ջ��һ��Ҫ���ӿռ䣬������֮ǰҪ��һ���ж�  
    if( s->top - s->base >= s->stackSize)  
    {  
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT)* sizeof(ElemType));  
        if(!s->base)  
             exit(0);  
  
        s->top = s->base + s->stackSize;  
        s->stackSize = s->stackSize + STACKINCREMENT;  
    }  
  
    *(s->top) = e;  
    s->top++;  
  
}  
  
void Pop(sqStack *s, ElemType *e)  
{  
    if( s->top == s->base)  
        return;  
  
    *e = *--(s->top); //��ջ��Ԫ�ص������޸�ջ��ָ��  
  
}  
  
int StackLen(sqStack s)  
{  
    return (s.top - s.base);  
}  
  
int main()  
{  
    sqStack s;  
    ElemType c,e;  
  
  
    InitStack( &s );  
  
    printf("��������׺����ʽ����#Ϊ������־��");  
    scanf("%c", &c);  
  
    while( c != '#')  
    {  
        if( c >= '0' && c <= '9')  
        {  
            printf("%c", c);  
        }  
        else if( ')' == c )  
        {  
            Pop(&s, &e);  
            while('(' != e)  
            {  
                printf("%c", e);  
                Pop(&s, &e);  
            }  
        }  
        else if( '+' == c || '-' == c)  
        {  
            if( !StackLen(s) )  
            {  
                Push(&s, c);  
            }  
            else  
            {  
                do  
                    {  
                      Pop(&s, &e);  
                       if( '(' == e)  
                       {  
                           Push(&s, e);  
                       }  
                       else  
                        {  
                           printf("%c", e);  
                       }  
                    }while( StackLen(s) && '(' != e);  
                    Push(&s, c);  
            }  
        }  
        else if( '*' == c || '/' == c || '(' == c)  
        {  
            Push(&s, c);  
        }  
        else  
        {  
            printf("�����������������!\n");  
            return -1;  
        }  
        scanf("%c", &c);  
    }  
  
    while( StackLen(s))  
    {  
        Pop( &s, &e);  
        printf("%c", e);  
    }  
    return 0;  
} 