/* �ƿ� 2353761 ��𪾧*/
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int a,b,c,i,j,l,g,h,k;          //a�ǰ�λ���֣�b��ʮλ���֣�c�Ǹ�λ����
	int d,e,f,sum,count=0;                //d,e,f�Ǻ�1953���� 
	for(d=111;d<=999;d++){
		for(e=111;e<=999;e++){
			for(f=111;f<=999;f++){
				sum=d+e+f;
				if(sum==1953){
					a=d/100;   //d�İ�λ����
					b=d%100/10;   //d��ʮλ����
					c=d%100%10;		//d�ĸ�λ����
					i=e/100;   //e�İ�λ����
					j=e%100/10;   //e��ʮλ����
					l=e%100%10;		//e�ĸ�λ����
					g=f/100;   //f�İ�λ����
					h=f%100/10;   //f��ʮλ����
					k=f%100%10;		//f�ĸ�λ����
					if(a!=0&&b!=0&&c!=0&&i!=0&&j!=0&&l!=0&&g!=0&&h!=0&&k!=0&&j!=g&&j!=h&&j!=k&&l!=g){
						if(d<e&&e<f&&d<f){
							if(a!=b&&b!=c&&a!=c&&a!=i&&a!=j&&a!=l&&a!=g&&a!=h&&a!=k&&l!=k){
								if(i!=l&&j!=i&&l!=j&&b!=i&&b!=j&&b!=l&&b!=g&b!=h&&b!=k){
									if(g!=h&&k!=g&&h!=k&&c!=i&&c!=j&&c!=l&&c!=g&&c!=h&&c!=k&&i!=g&&i!=h&&i!=k){
										count=count+1;
							    	    printf("No.%3d : %d+%d+%d=1953\n",count,d,e,f);
							        }
							        else{
							        	break;
						    	    }
						        }
							
						    }
						
					    }
					}
					
				}	
			}	
		}
	}


	printf("total:%d\n",count);
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
