#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char* token;
    int d_value = 0;
    char c_value = '\0';
    char s_value[100] = "";
    char t_value[100] = "";//�� �Է� ����
    float f_value = 0.0f;

    printf("�Է°�: ");
    // �Է°� ����
    fgets(input, 100, stdin);

     token = strtok(input, " \t");
    while (token != NULL) 
    {
        // �Է°��� ������ ������ ��
        if (isdigit(token[0]))
        { 
            int i = 0;
            while (token[i])
            {

                //���ڸ� �ִ��� �Ǵ�
                if (isdigit(token[i]))
                {
                    d_value = atoi(token);
                }
                //. �� ���� ��
                else if (token[i] == '.')
                {
                    f_value = atof(token);
                }

                i++;
            }

            
        }
        // �Է°��� ������ ������ ��
        else if (isalpha(token[0])) 
        { 
            c_value = token[0];
        }
        // �Է°��� ���ڿ� ������ ��
        else if (strlen(token) > 0) 
        { 
            if (strlen(s_value) == 0) {
                strcpy(s_value, token);
            }
            //tap Ű �Է� ����
            else if (strlen(t_value) == 0) {
                strcpy(t_value, token);
            }
          

        }
        token = strtok(NULL, " ");
    }

    //�Է� �� ǥ��
    printf("d_value = %d\n", d_value);
    printf("c_value = %c\n", c_value);
    printf("s_value = %s\n", s_value);
    printf("t_value = %s\n", t_value);
    printf("f_value = %f\n", f_value);
    return 0;
}