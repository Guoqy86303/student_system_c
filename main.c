#include "file_functions.h"
#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
void menu()
{
    int choice;
    while(1)
    {
    printf("学生成绩管理系统\n");
    printf("1. 添加学生\t 2. 查询学生\t 3. 修改成绩\n");
    printf("4. 删除学生\t 5. 按成绩排序\t 6. 显示所有学生\n");
    printf("0. 退出系统\n");
    printf("请输入您的选择: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add_student();
            break;
        case 2:
            search_student();
            break;
        case 3:
            modify_score();
            break;
        case 4:
            delete_student();
            break;
        case 5:
            sort_by_score();
            break;
        case 6:
            show_all();
            break;
        case 0:
            printf("退出系统。\n");
            exit(0);
        default:
            printf("无效的选择，请重新输入。\n");
    }
}
    
}
int main()
{
    
    setvbuf(stdout, NULL, _IONBF, 0);
    load_from_file();
    menu();
    return 0;
}
