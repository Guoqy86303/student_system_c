#include"file_functions.h"
#define _CRT_SECURE_NO_WARNINGS
Student students[MAX_STU]; //定义全局变量
int student_count = 0; //学生数量

void load_from_file() {//从文件中加载学生数据
    FILE *fp = fopen(FILE_NAME, "ab+");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", FILE_NAME);
        return;
    }
    student_count = fread(students, sizeof(Student), MAX_STU, fp);//分别是，数据读出来存到哪？、数据大小，最大读取数量，文件指针
    fclose(fp);
}
void save_to_file() {//保存学生数据到文件
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", FILE_NAME);
        return;
    }
    fwrite(students, sizeof(Student), student_count, fp);//分别是，数据存到哪？、数据大小，最大写入数量，文件指针
    fclose(fp);
}
void add_student()
{
    if(student_count >= MAX_STU)
    {
        printf("学生数量已达上限，无法添加新学生。\n");
        return;
    }
    Student s;
    printf("请输入学生姓名: ");
    scanf("%s",s.name);
    printf("请输入学生学号: ");
    scanf("%s",s.id);
    for(int i=0;i<student_count;i++)
    {
        if(strcmp(students[i].id, s.id) == 0)
        {
            printf("学号已存在，请重新输入。\n");
            return;
        }
    }
    printf("请输入学生年龄: ");
    scanf("%d",&s.age);
    printf("请输入学生成绩: ");
    scanf("%f",&s.score);
    students[student_count] = s;
    student_count++;
    save_to_file();
    printf("学生添加成功。\n");
}
void search_student()
{
    char id[15];
    printf("请输入要查询的学生学号: ");
    scanf("%s",id);
    for(int i=0;i<student_count;i++)
    {
        if(strcmp(students[i].id, id) == 0)
        {
            printf("学生姓名: %s\n",students[i].name);
            printf("学生学号: %s\n",students[i].id);
            printf("学生年龄: %d\n",students[i].age);
            printf("学生成绩: %.2f\n",students[i].score);
            return;
        }
    }
    printf("未找到该学号的学生。\n");
}
void modify_score()
{
    char id[15];
    printf("请输入要修改成绩的学生学号: ");
    scanf("%s",id);
    for(int i=0;i<student_count;i++)
    {
        if(strcmp(students[i].id, id) == 0)
        {
            printf("当前成绩: %.2f\n",students[i].score);
            printf("请输入新的成绩: ");
            scanf("%f",&students[i].score);
            save_to_file();
            printf("成绩修改成功。\n");
            return;
        }
    }
    printf("未找到该学号的学生。\n");
}
void delete_student()
{
    char id[15];
    printf("请输入要删除的学生学号: ");
    scanf("%s",id);
    for(int i=0;i<student_count;i++)
    {
        if(strcmp(students[i].id, id) == 0)
        {
            for(int j=i;j<student_count-1;j++)
            {
                students[j] = students[j+1];
            }
            student_count--;
            save_to_file();
            printf("学生删除成功。\n");
            return;
        }
    }
    printf("未找到该学号的学生。\n");
}
void sort_by_score()
{
    for(int i=0;i<student_count-1;i++)
    {
        for(int j=0;j<student_count-i-1;j++)
        {
            if(students[j].score < students[j+1].score)
            {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    printf("按成绩排序完成。\n");
    show_all();
}
void show_all()
{
    if(student_count == 0) {
        printf("没有学生信息。\n");
        return;
    }
    printf("学生信息列表:\n");
    printf("姓名\t学号\t年龄\t成绩\n");
    for(int i=0;i<student_count;i++)
    {
        printf("%s\t%s\t%d\t%.2f\n",students[i].name,students[i].id,students[i].age,students[i].score);
    }
}