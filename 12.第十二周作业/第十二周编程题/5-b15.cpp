/*2353761 ��𪾧 �ƿ�*/
#include<iostream>

using namespace std;    //ps:��Ҫ��cin��ȡ����Ϊcin����Ȼ�����ո�ͻس��Ķ�ȡ
                        //_getche--�л��� �Ļس���\r����getchar--�л��� ��\n

int main()
{
    char str[3][128] = { 0};//str0�����һ�����������
    int daxie = 0, xiaoxie = 0, number = 0, space=0,others = 0;
    for (int i = 0; i < 3; ++i) {
        cout << "�������" << i+1 << "��" << endl;
        cin.getline(str[i], 128);
    }//�������
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 128; ++j) {
            if (str[i][j] >= 'A' && str[i][j] <= 'Z') {//��д����
                daxie++;
            }
            else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
                xiaoxie++;
            }
            else if (str[i][j] >= '0' && str[i][j] <= '9') {
                number++;
            }
            else if (str[i][j] == ' ') {
                space++;
            }
            else {
                if (str[i][j] != 0) {
                    others++;
                }
            }
        }
    }

    cout << "��д : " << daxie<<endl;
    cout << "Сд : " << xiaoxie << endl;
    cout << "���� : " << number << endl;
    cout << "�ո� : " << space << endl;
    cout << "���� : " << others << endl;

    return 0;
}
