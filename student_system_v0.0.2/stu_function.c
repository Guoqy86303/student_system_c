#define _CRT_SECURE_NO_WARNINGS
#include"stu_link.h"

stu*head = NULL;

stu* create_link(char *name, char *id, float score)
{
    stu *new_node = (stu*)malloc(sizeof(stu));
    if (new_node == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    strcpy(new_node->name, name);
    strcpy(new_node->id, id);
    new_node->score = score;
    new_node->next = NULL;
    return new_node;
}
void add_node(char *name, char *id, float score)
{
    stu *new_node = create_link(name, id, score);
    if (new_node == NULL)
        return;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        stu *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void show_all()
{
    if (head == NULL)
    {
        printf("没有学生信息。\n");
        return;
    }
    stu *temp = head;
    printf("学生信息列表:\n");
    while (temp != NULL)
    {
        printf("姓名: %s, 学号: %s, 成绩: %.2f\n", temp->name, temp->id, temp->score);
        temp = temp->next;
    }
}
stu* find_node(char *id)
{
    stu *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->id, id) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void delete_node(char *id)
{
    if (head == NULL)
    {
        printf("没有学生信息。\n");
        return;
    }
    stu *temp = head;
    stu *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->id, id) == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("学生信息已删除。\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("未找到该学生信息。\n");
}
void free_link()//用到指针，在结束程序前进行内存释放
{
    stu *temp;
    while (head!= NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void modify_node_name(char *id, char *new_name)
{
    stu *node = find_node(id);
    if (node != NULL)
    {
        strcpy(node->name, new_name);
        printf("学生姓名已修改。\n");
    }
    else
    {
        printf("未找到该学生信息。\n");
    }
}
void modify_node_score(char *id, float new_score)
{
    stu *node = find_node(id);
    if (node != NULL)
    {
        node->score = new_score;
        printf("学生成绩已修改。\n");
    }
    else
    {
        printf("未找到该学生信息。\n");
    }
}
void sort_by_score()
{
    if (head == NULL || head->next == NULL)
    {
        printf("没有足够的学生信息进行排序。\n");
        return;
    }
    stu *i, *j;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->score < j->score)
            {
                // 交换节点数据
                char temp_name[20];
                char temp_id[15];
                float temp_score;

                strcpy(temp_name, i->name);
                strcpy(temp_id, i->id);
                temp_score = i->score;

                strcpy(i->name, j->name);
                strcpy(i->id, j->id);
                i->score = j->score;

                strcpy(j->name, temp_name);
                strcpy(j->id, temp_id);
                j->score = temp_score;
            }
        }
    }
    printf("学生信息已按成绩排序。\n");
}
void save_to_file(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("无法打开文件进行保存。\n");
        return;
    }
    stu *temp = head;
    while (temp != NULL)
    {
        fprintf(file, "%s %s %.2f", temp->name, temp->id, temp->score);
        temp = temp->next;
    }
    fclose(file);
    printf("学生信息已保存到文件。\n");
}
void load_from_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("无法打开文件进行加载。\n");
        return;
    }
    char name[20];
    char id[15];
    float score;
    while (fscanf(file, "%s %s %f", name, id, &score) != EOF)
    {
        add_node(name, id, score);
    }
    fclose(file);
    printf("学生信息已从文件加载。\n");
}