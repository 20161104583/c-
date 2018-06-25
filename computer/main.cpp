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
    int maek[10];
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
    }

    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fr;
    FILE *fw;
    fr=fopen("//Users//a20161104583//Desktop//GPS//GPSW.txt","r+");
    fw=fopen("//Users//a20161104583//Desktop//GPS//GPSWout.csv","w");
    fprintf(fw,"姓名 ,性别 , ,经度 ,海拔\n");    std::cout << "Hello, World!\n";
    return 0;
}

