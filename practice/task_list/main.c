#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    CREATE,
    COMPLETED,
    REMOVE,
} TASK_STATUS;

typedef struct task
{
    char *task_name;
    TASK_STATUS task_status;
} task_t;

typedef struct task_list
{
    task_t *data;
    int size;
    int capacity;
} task_list_t;

char *menu[] = {"添加任务", "完成任务", "删除任务", "退出程序"};

task_list_t task_list;

// 声明方法区域
void init();
void dynamic_array_resize();
void run();
int select_menu();
void show_task_list();
void add_task();
void completed_task();
void delete_task();
void task_list_add(char *);
void flash_scanf_cache();
void check_NULL_point(void *p);

int main(void)
{
    //
    run();
    return 0;
}
void run()
{
    // 初始化需要的数据
    init();
    while (1)
    {
        // 查看当前任务详情
        show_task_list();
        // 显示选项列表
        int q = select_menu();
        if (q)
        {
            printf("程序结束");
            free(task_list.data);
            task_list.data = NULL;
            break;
        }
    }
}
void init()
{
    task_list.data = malloc(sizeof(task_t) * 20);
    check_NULL_point(task_list.data);
    task_list.size = 0;
    task_list.capacity = 20;
}

int select_menu()
{
    int select = 0;
init:
    printf("请输入你想要选择的选项:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d.%s\n", i + 1, menu[i]);
    }
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        add_task();
        break;
    case 2:
        completed_task();
        break;
    case 3:
        delete_task();
        break;
    case 4:
        return 1;
    default:
    {
        printf("请输入正确的选项");
        flash_scanf_cache(); // 清空scanf的缓存区
        goto init;
    };
    }
    return 0;
}

void task_list_add(char *task)
{
    int size = task_list.size;
    int task_size = strlen(task);
    int expansion_capacity = (int)task_list.capacity * 0.7;

    task_list.data[size].task_name = malloc(size + 1);
    check_NULL_point(task_list.data[size].task_name);
    task_list.data[size].task_status = CREATE;
    strcpy(task_list.data[size].task_name, task);
    task_list.size++;
    if (task_size >= task_list.capacity)
    {
        dynamic_array_resize();
    }
}

void add_task()
{
    flash_scanf_cache();
    printf("请输入你要添加的任务\n");
    char task[100];
    fgets(task, 100, stdin);
    task[strcspn(task, "\n")] = 0; // 删除换行符
    task_list_add(task);
}

void completed_task()
{
    flash_scanf_cache();
    show_task_list();
    printf("请输入你要完成的用户编号\n");
    int id = 0;
    scanf("%d", &id);
    task_list.data[id - 1].task_status = COMPLETED;
}

void delete_task()
{
    flash_scanf_cache();
    show_task_list();
    printf("请输入你要删除的id\n");
    int id = 0;
    scanf("%d", &id);

    // 还内存
    task_t *task = &(task_list.data[id - 1]);
    free(task->task_name);
    task->task_name = NULL;

    memmove(&(task_list.data[id - 1]), &(task_list.data[id]), (task_list.size - id) * sizeof(task_t));
    task_list.size--;
}
void show_task_list()
{
    int size = task_list.size;
    for (int i = 0; i < size; i++)
    {
        task_t *task = &(task_list.data[i]);
        printf("\t%d.%s", i + 1, task->task_name);
        if (COMPLETED == task->task_status)
        {
            printf("\t完成");
        }
        printf("\n");
    }
}

void check_NULL_point(void *p)
{
    if (p == NULL)
    {
        printf("分配内存失败,程序结束");
        exit(-1);
    }
}

void flash_scanf_cache()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void dynamic_array_resize()
{
    task_list.capacity *= 2;
    task_list.data = realloc(task_list.data, sizeof(task_t) * task_list.capacity);
}
