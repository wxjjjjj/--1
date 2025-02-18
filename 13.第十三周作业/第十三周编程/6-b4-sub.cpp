/* 2353761 ��𪾧 �ƿ� */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)//��const����ֻ���������޸�*p��ָ�����
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p;
    if (str == 0) {//NULL������
        return 0;
    }
    else {
        p = str;
        while (*p != 0) {
            ++p;
        }//pָ��β0
        return int(p - str);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL�����⴦��
        return NULL;
    }
    else {
        if (s2 == 0) {
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            while (*ps1 != 0) {
                ++ps1;
            }//ps1ָ��s1��β0
            while (*ps2 != 0) {
                *ps1 = *ps2;
                ++ps2;
                ++ps1;
            }//ps2ָ��s2β0
            *ps1 = *ps2;//β0Ҳ������
            return s1;
        }
    }
    
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL�����⴦��
        return NULL;
    }
    else {
        if (s2 == 0) {
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            while (*ps1 != 0) {
                ++ps1;
            }//ps1ָ��s1��β0
            if (len >= tj_strlen(s2)) {
                while (*ps2 != 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                }//ps2ָ��s2β0
                *ps1 = *ps2;//β0Ҳ������
            }
            else {
                int count = len;
                while(count > 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                    --count;
                }
                *ps1 = '\0';
            }
            return s1;
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL�����⴦��
        return NULL;
    }
    else {
        if (s2 == 0) {
            *s1 = '\0';
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            while (*ps2 != 0) {
                *ps1 = *ps2;
                ++ps2;
                ++ps1;
            }//ps2ָ��s2β0
            *ps1 = *ps2;//β0Ҳ������
            return s1;
        }
    }
    
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL�����⴦��
        return NULL;
    }
    else {
        if (s2 == 0) {//�մ�����
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            if (len >= tj_strlen(s2)) {
                while (*ps2 != 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                }//ps2ָ��s2β0
            }
            else {
                int count = len;
                while (count > 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                    --count;
                }
            }
            return s1;
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            while (*ps1!=0&&*ps2!=0) {
                if (*ps1 != *ps2) {
                    return int(*ps1 - *ps2);
                }
                else {
                    ps1++;
                    ps2++;
                }
            }
            if (*ps1 == 0) {
                return -int(*ps2);
            }
            else {
                return int(*ps1);
            }
        }
    }
    
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            while (*ps1 != 0 && *ps2 != 0) {
                if (*ps1 != *ps2) {
                    if (*ps1 >= 'A' && *ps1 <= 'Z') {
                        if (*ps2 >= 'A' && *ps2 <= 'Z') {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            if (*ps2 == *ps1 + 32) {
                                ;
                            }
                            else {
                                return int((*ps1 + 32) - *ps2);
                            }
                        }
                    }
                    else if (*ps1 >= 'a' && *ps1 <= 'z') {
                        if (*ps2 >= 'A' && *ps2 <= 'Z') {
                            if (*ps1 == *ps2 + 32) {
                                ;
                            }
                            else {
                                return int(*ps1 - *ps2 - 32);
                            }
                        }
                        else {
                            return int(*ps1 - *ps2);
                        }
                    }
                    else {
                        if (*ps2 >= 'A' && *ps2 <= 'Z') {
                            return int(*ps1 - *ps2 - 32);
                        }
                        else {
                            return int(*ps1 - *ps2);
                        }
                    }
                }
                ps1++;
                ps2++;
            }

            if (*ps1 == 0) {
                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                    return -int(*ps2+32);
                }
                else {
                    return -int(*ps2);
                }
            }
            else {
                if (*ps1 >= 'A' && *ps1 <= 'Z') {
                    return int(*ps1 + 32);
                }
                else {
                    return int(*ps1);
                }
            }
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            int i = tj_strlen(s1) - tj_strlen(s2);
            if (i > 0) {//s2��
                if (len > tj_strlen(s2)) {
                    while (*ps2 != 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                    }//ps2ָ��s2β0
                    return int(*ps1);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                        --a;
                    }
                    return 0;
                }
            }
            else {
                if (len > tj_strlen(s1)) {
                    while (*ps1 != 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                    }//ps1ָ��s1β0
                    return -int(*ps2);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                        --a;
                    }
                    return 0;
                }
            }
            
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            int i = tj_strlen(s1) - tj_strlen(s2);
            if (i > 0) {//s2��
                if (len > tj_strlen(s2)) {
                    return tj_strcasecmp(s1, s2);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            if (*ps1 >= 'A' && *ps1 <= 'Z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2);
                                }
                                else {
                                    if (*ps2 == *ps1 + 32) {
                                        ;
                                    }
                                    else {
                                        return int((*ps1 + 32) - *ps2);
                                    }
                                }
                            }
                            else if (*ps1 >= 'a' && *ps1 <= 'z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    if (*ps1 == *ps2 + 32) {
                                        ;
                                    }
                                    else {
                                        return int(*ps1 - *ps2 - 32);
                                    }
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                            else {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2 - 32);
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                        }
                        ps1++;
                        ps2++;
                        --a;
                    }
                    return 0;
                }
            }
            else {
                if (len > tj_strlen(s1)) {
                    return tj_strcasecmp(s1, s2);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            if (*ps1 >= 'A' && *ps1 <= 'Z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2);
                                }
                                else {
                                    if (*ps2 == *ps1 + 32) {
                                        ;
                                    }
                                    else {
                                        return int((*ps1 + 32) - *ps2);
                                    }
                                }
                            }
                            else if (*ps1 >= 'a' && *ps1 <= 'z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    if (*ps1 == *ps2 + 32) {
                                        ;
                                    }
                                    else {
                                        return int(*ps1 - *ps2 - 32);
                                    }
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                            else {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2 - 32);
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                        }
                        ps1++;
                        ps2++;
                        --a;
                    }
                    return 0;
                }
            }

        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == 0) {
        return NULL;
    }
    else {
        char* p=str;
        while (*p!= 0) {
            if (*p >= 'a' && *p <= 'z') {
                *p = *p - 32;
            }
            ++p;
        }
        return str;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == 0) {
        return NULL;
    }
    else {
        char* p = str;
        while (*p != 0) {
            if (*p >= 'A' && *p <= 'Z') {
                *p = *p + 32;
            }
            ++p;
        }
        return str;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p=str;
    int n = 1;
    if (str == 0) {
        return 0;
    }
    else {
        while (*p != 0) {
            if (*p == ch) {
                return n;
                break;
            }
            ++n;
            ++p;
        }
        return 0;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == 0 || substr == 0) {
        return NULL;
    }
    else {
        const char* p = str;
        int n = 1;
        while (*p != 0) {
            if (*p == *substr) {
                const char* m = substr;
                int j = tj_strncmp(p, substr,tj_strlen(substr));
                if (j == 0) {
                    return n;
                }
                else {
                    ;
                }
            }
            ++p;
            ++n;
        }
        return 0;

    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    int n = 1;
    if (str == 0) {
        return 0;
    }
    else {
        while (*p != 0) {
            ++p;
            ++n;
        }//pָ��strβ0
        while (p != str) {
            --p;
            --n;
            if (*p == ch) {
                return n;
                break;
            }
        }
        if (*str == ch) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == 0 || substr == 0) {
        return NULL;
    }
    else {
        const char* p = str;
        int n = 1;
        while (*p != 0) {
            ++p;
            ++n;
        }
        while (p != str) {
            --p;
            --n;
            if (*p == *substr) {
                const char* m = substr;
                int j = tj_strncmp(p, substr, tj_strlen(substr));
                if (j == 0) {
                    return n;
                }
                else {
                    ;
                }
            }
        }
        return 0;

    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == 0) {
        return NULL;
    }
    else {
        char* p, * q;
        p = str;
        q = str;
        while (*p != 0) {
            ++p;
        }//pָ��str��β0
        --p;
        while (p !=q) {
            if (p - q < 0) {
                break;
            }
            char tmp;
            tmp = *p;
            *p = *q;
            *q = tmp;
            --p;
            ++q;
        }
        return str;
    }
}
