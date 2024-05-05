#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机整数
int random_int(int max) {
    return rand() % (max + 1);
}

// 生成随机小数
double random_double(int max) {
    return (double)random_int(max * 10) / 10.0;
}

// 生成四则运算题目
void generate_problem(char operators[], int op_count, int max_num, int use_brackets, int use_decimals) {
    int num1, num2;
    double dec1, dec2;
    char op = operators[rand() % op_count];
    
    if (use_decimals) {
        dec1 = random_double(max_num);
        dec2 = random_double(max_num);
        if (use_brackets) {
            printf("(%0.1f %c %0.1f)\n", dec1, op, dec2);
        } else {
            printf("%0.1f %c %0.1f\n", dec1, op, dec2);
        }
    } else {
        num1 = random_int(max_num);
        num2 = random_int(max_num);
        if (use_brackets) {
            printf("(%d %c %d)\n", num1, op, num2);
        } else {
            printf("%d %c %d\n", num1, op, num2);
        }
    }
}

// 主函数
int main() {
    int num_problems, max_num, use_brackets, use_decimals;
    char operators[4];
    int op_count = 0;

    srand(time(NULL));

    // 用户输入题目数量
    printf("请输入题目数量: ");
    scanf("%d", &num_problems);

    // 用户选择运算符
    printf("请输入要使用的运算符 (加减乘除): ");
    char input;
    while (scanf(" %c", &input) == 1) {
        operators[op_count++] = input;
        if (op_count >= 4) break;
    }

    // 用户设置最大数
    printf("请输入最大数 (例如 10, 100): ");
    scanf("%d", &max_num);

    // 用户选择是否使用括号
    printf("是否使用括号 (1 是, 0 否): ");
    scanf("%d", &use_brackets);

    // 用户选择是否使用小数
    printf("是否使用小数 (1 是, 0 否): ");
    scanf("%d", &use_decimals);

    // 生成题目
    printf("生成的题目:\n");
    for (int i = 0; i < num_problems; i++) {
        generate_problem(operators, op_count, max_num, use_brackets, use_decimals);
    }

    return 0;
}
