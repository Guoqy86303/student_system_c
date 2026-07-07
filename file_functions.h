#ifndef FILE_FUNCTIONS_H  //保护宏，防止重复包含
#define FILE_FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STU 100
#define FILE_NAME "stu_data.dat"

typedef struct {          //定义学生结构体，如果没有保护宏，多个.c文件包含这个头文件，就会重复定义结构体，导致编译错误
    char name[50];
    int age;
    char id[15];
    float score;
} Student;

extern Student students[MAX_STU];//全局

extern int student_count; //学生数量

void load_from_file();//声明各个函数
void save_to_file();
void add_student();
void search_student();
void modify_score();
void delete_student();
void sort_by_score();
void show_all();
#endif


