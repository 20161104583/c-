//
//  main.cpp
//  computer
//
//  Created by 20161104586 on 2018/6/25.
//  Copyright © 2018年 20161104586. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 10
#define true 1
#define false 0
int n=0;
typedef struct node
{
    long num;
    string name;
    int mark[10];
    int sum;
    float aver;
    struct node *next;
}LNode;
class Singer
{
    private:
        LNode data[MAXSIZE];
    public:
        Singer(){};
        void print(LNode *head);
        void grade(LNode *head);
        void rank(LNode *head);
        void insert(LNode *head,LNode *sin);
        void inquire(LNode *head,long num);
        void save(LNode *head,char filename[]);
        void import(char filename[],LNode*head);
};
void menu()
{
    cout<<"1.---------创建选手信息"<<endl;
    cout<<"2.---------评委打分"<<endl;
    cout<<"3.---------打印所有信息"<<endl;
    cout<<"4.---------成绩排序"<<endl;
    cout<<"5.---------按编号查询"<<endl;
    cout<<"6.---------追加选手数据"<<endl;
    cout<<"7.---------保存信息表到文件"<<endl;
    cout<<"8.---------从文件导入信息"<<endl;
    cout<<"0.---------退出"<<endl;
    cout<<"输入您的选择："<<endl;
}
LNode *Create()
{
    LNode *p1,*p2,*head;
    head=NULL;
    p1=head;
    while(true)
    {
        p2=p1;
        p1=new LNode;
        cout<<"请输入选手姓名：";
        cin>>p1->name;
        if(p1->name=="0")
            break;
        cout<<"请输入编号: ";
        cin>>p1->num;
        n++;
        if(n==1)
        {
            head=p1;
            p1->next=NULL;
        }
        else
        {
            p2->next=p1;
            p1->next=NULL;
        }
    }
    cout<<"输入结束"<<endl;
    return head;
}
void Singer ::print(LNode *head)
{
    LNode *p=head;
    if(p!=NULL)
    {
        cout<<setw(15)<<"姓名"<<setw(10)<<"编号"<<setw(10)<<"平均分"<<endl;
        do
        {
            cout<<setw(15)<<p->name<<setw(10)<<p->num<<setw(10)<<p->aver<<endl;
            p=p->next;
        }
        while(p!=NULL);
    }
    else
    {
        cout<<"没有信息!"<<endl;
    }
}
void Singer ::grade(LNode *head)
{
    LNode *p;
    p=head;
    if(p!=NULL)
    {
        do
        {
            int i,max,min;
            int sum=0;
            max=-1;
            min=11;
            cout<<"请输入"<<p->num<<"号选手"<<p->name<<"的得分"<<endl;
            for(i=0;i<10;i++)
            {
                cout<<"第"<<i+1<<"个评委的评分：";
                cin>>p->mark[i];
                if(p->mark[i]>max)
                    max=p->mark[i];
                if(p->mark[i]<min)
                    min=p->mark[i];
                sum+=p->mark[i];
            }
            p->sum=sum;
            p->aver=(p->sum-max-min)/8.0;
            cout<<endl;
            cout<<"总分"<<p->sum<<"平均分："<<p->aver<<endl;
            p=p->next;
            cout<<endl;
        }
        while(p!=NULL);
    }
    else
    {
        cout<<"\n所有选手的评分输入完毕。";
    }
}
void Singer ::rank(LNode *head)
{
    LNode *p,*q,*tail,*h;
    if(!head)
        return ;
    tail=NULL;
    h=new LNode;
    h->next=head;
    while(h->next!=tail)
    {
        p=h;
        q=p->next;
        while(q->next!=tail)
        {
            if(p->next->aver<q->next->aver)
            {
                p->next=q->next;
                q->next=q->next->next;
                p->next->next=q;
                p=p->next;
            }
            else
            {
                q=q->next;
                p=p->next;
            }
        }
        tail=q;
    }
    head=p->next;
    p=h->next;
    cout<<setw(10)<<"编号"<<setw(10)<<"姓名"<<setw(10)<<"总分"<<setw(15)<<"平均分"<<endl;
    do
    {
        cout<<setw(10)<<p->num<<setw(10)<<p->name<<setw(10)<<p->sum<<setw(15)<<p->aver<<endl;
        p=p->next;
    }
    while(p!=NULL);
}
void Singer ::insert(LNode *head,LNode *sin)
{
    LNode *p0,*p1;
    p1=head;
    p0=sin;
    if(head==NULL)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while(p1->next!=NULL)
        {
            if(p0->num==p1->num)
            {
                cout<<"编号为"<<p0->num<<"的选手已存在！"<<endl;
            }
            p1=p1->next;
        }
        p1->next=p0;
        p0->next=NULL;
        n++;
    }
    grade(p0);
    cout<<"成功输入信息！"<<endl;
}
void Singer ::inquire(LNode *head,long num)
{
    LNode *p=head;
    if(p==NULL)
    {
        cout<<"信息为空!"<<endl;
        return;
    }
    else
    {
        if(p->num==num)
        {
            if(true)
            {
                cout<<"编号是"<<num<<"的选手是:"<<endl;
                cout<<setw(15)<<"姓名"<<setw(7)<<"成绩"<<endl;
            }
            cout<<setw(15)<<p->name<<setw(7)<<p->aver<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"查无此人"<<endl;
}
void Singer ::save(LNode *head,char filename[])
{
    LNode *p=head;
    if(head==NULL)
    {
        cout<<"没有可以保存的信息"<<endl;
        return;
    }
    else
    {
        ofstream outfile(filename,ios::out);
        if(!outfile)
        {
            cout<<"打开数据文件出错！"<<endl;
            return;
        }
        do
        {
            if(false)
                outfile<<endl;
            outfile<<p->name<<"\t"<<p->num<<"\t"<<p->aver;
            p=p->next;
        }
        while(p!=NULL);
        outfile.close();
        cout<<"保存成功！保存到"<<filename<<endl;
    }
}
void Singer ::import(char filename[],LNode*head)
{
    ifstream infile;
    infile.open(filename,ios::in);
    if(!infile)
    {
        cout<<"打开文件失败！"<<endl;
    }
    head=NULL;
    n=0;
    LNode *p1;
    LNode *p;
    while(!infile.eof())
    {
        p=new LNode;
        if(n>=1)
            p1->next=p;
        infile>>p->name>>p->num;
        p->next=NULL;
        if(n==0)
            head=p;
        p1=p;
        n++;
    }
    infile.close();
    cout<<"导入成功"<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string singer;
    LNode *head=NULL;
    LNode newsin;
    string name;
    void grade(LNode*);
    ifstream infile;
    char filename[20];
    long num;
    char choose;
    int quit=false;
    char c;
    while(true)
    {
        menu();
        cin>>choose;
        switch(choose)
        {
            case '1':
                if(false)
                {
                    cout<<"你所创建的链表，原有链表将丢失，是否继续！（Y/N）";
                }
        }
    }
    return 0;
}

