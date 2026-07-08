#define _CRT_SECURE_NO_WARNINGS
#include "stu_link.h"

#define FILE_NAME "stu_list_link.dat"

int main()
{
    // 程序启动先加载文件数据
    load_from_file(FILE_NAME);

    int choice;
    char name[20], id[15], new_name[20];
    float score, new_score;

    while (1)
    {
        printf("\n===== 学生管理系统 =====\n");
        printf("1. 新增学生\n");
        printf("2. 显示全部学生\n");
        printf("3. 按学号查询学生\n");
        printf("4. 修改学生姓名\n");
        printf("5. 修改学生分数\n");
        printf("6. 删除学生\n");
        printf("7. 按分数排序\n");
        printf("8. 保存数据到文件\n");
        printf("0. 退出程序\n");
        printf("============================\n");
        printf("请输入功能选择：");
        scanf("%d", &choice);
        getchar(); // 吸收回车，避免后面scanf/gets异常

        switch (choice)
        {
            case 1:
                printf("请输入姓名：");
                scanf("%s", name);
                printf("请输入学号：");
                scanf("%s", id);
                printf("请输入分数：");
                scanf("%f", &score);
                add_node(name, id, score);
                printf("添加成功！\n");
                break;

            case 2:
                show_all();
                break;

            case 3:
                printf("输入要查询的学号：");
                scanf("%s", id);
                {
                    stu *res = find_node(id);
                    if (res == NULL)
                    {
                        printf("未找到该学生！\n");
                    }
                    else
                    {
                        printf("姓名：%s  学号：%s  分数：%.2f\n", res->name, res->id, res->score);
                    }
                }
                break;

            case 4:
                printf("输入待修改学号：");
                scanf("%s", id);
                printf("输入新姓名：");
                scanf("%s", new_name);
                modify_node_name(id, new_name);
                printf("姓名修改完成\n");
                break;

            case 5:
                printf("输入待修改学号：");
                scanf("%s", id);
                printf("输入新分数：");
                scanf("%f", &new_score);
                modify_node_score(id, new_score);
                printf("分数修改完成\n");
                break;

            case 6:
                printf("输入要删除的学号：");
                scanf("%s", id);
                delete_node(id);
                break;

            case 7:
                sort_by_score();
                printf("已按分数升序排序完成\n");
                break;

            case 8:
                save_to_file(FILE_NAME);
                break;

            case 0:
                // 退出前自动保存 + 释放链表内存
                save_to_file(FILE_NAME);
                free_link();
                printf("数据已保存，内存释放完毕，程序退出！\n");
                return 0;

            default:
                printf("输入错误，请选择0~8之间的数字！\n");
                break;
        }
    }
}