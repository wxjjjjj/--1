/* �ƿ� 2353761 ��𪾧 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int ret, x;
    int valid_input = 0; // ����Ƿ�����Ч����  

    while (!valid_input) {
        printf("������x��ֵ[0-100] : ");
        ret = scanf("%d", &x);//����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf

        if (ret == 1) {                                                      
            if (x >= 0 && x <= 100) {
                valid_input = 1; // ��Ч���룬�˳�ѭ��  
            }
            else {
                // x������Ч��Χ�ڣ���scanf�ɹ���ȡ��һ�����������������ڷ�Χ�ڣ�  
                printf("�����д�[ret=%d x=%d],����������\n", ret, x);           //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 --����scanf�ɹ���ȡ����Чֵ����
                // ����Ҫ������뻺��������Ϊscanf�Ѿ���ȡ����������  
            }
        }
        else {    // scanfδ�ܶ�ȡ��������������������ĸ�������������ַ�  
            while (1) {
                printf("�����д�[ret=%d x=%d],����������\n", ret, x);
                int c;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
                while ((c = getchar()) != '\n' && c != EOF) {
                    if (c == '\n' && (c = getchar()) != EOF) {
                        ungetc(c, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
                    }                                                                  // ������뻺�����еĴ����ַ�  
                }
                printf("������x��ֵ[0-100] : ");                                                                  // ������з������ַ������磬��Windows�п�����һ�������'\r'����Ҳ������  
                ret = scanf("%d", &x);//����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
                if (ret == 1) {
                    break;
                }

            }
            
        }

        // ��������ʾ�û�����֮ǰ��ȷ�����뻺�����ǿյ�  
    }

    printf("��Ч����: x = %d\n", x);

    return 0;
}


