#ifndef STU_LINK_H
#define STU_LINK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stu_node
{
    char name[20];
    char id[15];
    float score;
    struct stu_node *next;
} stu;

extern stu *head;//返回结构体的函数要用结构体名称

stu* create_link(char *name, char *id, float score);//创建列表用结构体函数声明
void add_node(char *name, char *id, float score);//添加节点函数
void show_all();//显示所有节点函数
stu* find_node(char *id);//查找节点函数
void delete_node(char *id);//删除节点函数
void free_link();//释放链表函数
void modify_node_name(char *id, char *new_name);//修改节点名称函数
void modify_node_score(char *id, float new_score);//修改节点成绩函数
void sort_by_score();//排序链表函数
void save_to_file(const char *filename);//保存链表到文件函数
void load_from_file(const char *filename);//从文件加载链表函数
#endif
