#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �����������
int random_int(int max) {
    return rand() % (max + 1);
}

// �������С��
double random_double(int max) {
    return (double)random_int(max * 10) / 10.0;
}

// ��������������Ŀ
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

// ������
int main() {
    int num_problems, max_num, use_brackets, use_decimals;
    char operators[4];
    int op_count = 0;

    srand(time(NULL));

    // �û�������Ŀ����
    printf("��������Ŀ����: ");
    scanf("%d", &num_problems);

    // �û�ѡ�������
    printf("������Ҫʹ�õ������ (�Ӽ��˳�): ");
    char input;
    while (scanf(" %c", &input) == 1) {
        operators[op_count++] = input;
        if (op_count >= 4) break;
    }

    // �û����������
    printf("����������� (���� 10, 100): ");
    scanf("%d", &max_num);

    // �û�ѡ���Ƿ�ʹ������
    printf("�Ƿ�ʹ������ (1 ��, 0 ��): ");
    scanf("%d", &use_brackets);

    // �û�ѡ���Ƿ�ʹ��С��
    printf("�Ƿ�ʹ��С�� (1 ��, 0 ��): ");
    scanf("%d", &use_decimals);

    // ������Ŀ
    printf("���ɵ���Ŀ:\n");
    for (int i = 0; i < num_problems; i++) {
        generate_problem(operators, op_count, max_num, use_brackets, use_decimals);
    }

    return 0;
}
