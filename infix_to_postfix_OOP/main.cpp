#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;
};


class Stack
{
    private:
        Node *top;
        int size=0;
    public:
        Stack()
    {
            top=NULL;
    }
    void Push(char x);
    int  Pop();
    char StackTop();
    bool isEmpty();
};

void Stack ::Push(char x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        size++;
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack :: Pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return x;
    }
    else
    {
        size--;
        Node *p=top;
        top=top->next;
        x=p->data;
        free(p);
        return x;
    }
}

char Stack :: StackTop()
{
    char ch;
    if(top==NULL)
        return ' ';
        ch=top->data;
    return ch;
}

bool Stack :: isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

class Postfix
{
private:
    Stack stk;
public:
    char *Postfix_Eval(char ch[]);
    bool isCharacter(char ch);
    int isOperator(char ch);
};

bool Postfix :: isCharacter(char ch)
{
    if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/')
        return true;
    else
        return false;
}

int Postfix :: isOperator(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else
        return 0;
}

char * Postfix :: Postfix_Eval(char ch[])
{
    int size=0;
    int i=0,j=0;
    while(ch[i]!='\0')
    {
        size++;
        i++;
    }
    char *postfix=new char[size+1];
    i=0;
    while(ch[i]!='\0')
    {
        if(isCharacter(ch[i]))
        {
            postfix[j++]=ch[i++];
        }
        else
        {
            if(isOperator(ch[i])>isOperator(stk.StackTop()))
            {
                stk.Push(ch[i++]);
            }
                else
                    postfix[j++]=stk.Pop();
            }
        }
    while(!stk.isEmpty())
    {
        postfix[j++]=stk.Pop();
    }
    postfix[j++]='\0';
    return postfix;
}


int main()
{
    cout<<"Enter the expression to be converted to Postfix from Infix : "<<endl;
    char str[100];
    cin>>str;
    cout<<"The postfix form of the given expression is given by : "<<endl;
    Postfix p;
    char *post=p.Postfix_Eval(str);
    int i=0;
    while(post[i]!=0)
    {
        cout<<post[i++];
    }
    return 0;
}
