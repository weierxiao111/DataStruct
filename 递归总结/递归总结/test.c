// ������֮��
/*#include <stdio.h>

void hanluota(unsigned int k, char a, char b, char c, int* count)  //n��������B�ϣ����B����C
{
	if (k == 0)
		return ;
	if (k == 1)
	{
		printf("��%c�ϵ�����%c\n",b,c);         //���һ�����Ӵ�B���Ƶ�C
	    (*count) ++;
		return ;
	}

	hanluota(k-1,c,b,a,count); //��n-1�����Ӵ�B�Ƶ�A��
	printf("��%c�ϵ�����%c\n",b,c);
	(*count) ++;
    hanluota(k-1,b,a,c,count); //��n-1�����Ӵ�A����C��
}

int main()
{
	unsigned int n;
	int ret = 0;
	hanluota(5,'A','B','C',&ret);
	printf ("�ܹ���Ҫ%d��\n",ret);
	return 0;
}
*/

//����ת���㷨  ��M����ת��ΪN����

//MtoNnumber(const char* Mnumber , unsigned short m, unsigned short n)
//{
//
//
//}
//
//
//int main()
//{
//	char* Mnumber = "123456";
//	char* Nnumber;
//	unsigned short m = 10;
//	unsigned short m = 2;
//	MtoNnumber(Mnumber,m,n);
//	return 0;
//}

//�����˷�
//#include <iostream>
//#include <assert.h>
//#include <string.h>
//
//using namespace std;
//
//char* resver (char* dest)       //�ַ�����ת
//{
//        char *start = dest;
//        char *left = dest;
//        char ch;
//
//        while (*dest++)                 
//                ; 
//        dest -= 2;
//
//        while (left < dest)
//        {
//                ch = *left;
//                *left++ = *dest;
//                *dest-- = ch;
//        }
//	  return (start);
//}
//
//char* maxmlu(char* num1, char* num2, char* num3 )       
//{
//      assert(num1 && num2 && num3);
//	  if (num1[0] == '0' || num2[0] == '0' )
//	  {
//		  num3[0] = '0';
//		  return num3;
//	  }
//	  int len1 = strlen(num1);
//	  int len2 = strlen(num2);
//	  resver(num1);
//	  resver(num2);
//	  memset(num3,0,sizeof(char)*127);
//	  for (int i = 0; i<len1; i++)
//	  {
//		  for (int j = 0; j<len2; j++)
//		  {
//			  short temp1 = num1[i] - '0';
//			  short temp2 = num2[j] - '0';
//			  short temp3 = temp1*temp2;
//			  num3[i+j] += temp3;
//			  int count = 0;
//			  while (num3[i+j+count] >9)       //�������9��λ
//			  {
//				  num3[i+j+1+count] += (num3[i+j+count]/10);
//				  num3[i+j+count] = num3[i+j+count]%10;
//				  count++;
//			  }
//		  }
//	  }
//
//	  for (int i = 0; i<=len1+len2; i++)
//	  {
//		  num3[i] += '0';
//	  }
//
//	  num3[len1+len2] = '\0';
//	  resver(num3);              //��3���ַ����鷭ת����
//	  resver(num1);
//	  resver(num2);
//      
//	  int k = 0;
//	  while (num3[k] == '0')      //����ǰ����0����Ŀ
//		   k++;
//
//	  memmove(num3,&num3[k],(126-k));   //��ǰ��Ϊ0�Ĳ��ָ���      
//	  return num3;
//
//}
//
//int main()
//{
//	char num1[64] = "";        //�������Ϊ63λ���һλ��'\0'
//	char num2[64] = "";
//	char ret[127]={0};         //���Ľ��Ϊ126 ���һλ��'\0'
//	cout<<"�������һ��"<<endl;
//	cin.getline(num1,64);
//	cout<<"�����������"<<endl;
//	cin.getline(num2,64);
//	maxmlu(num1,num2,ret);
//	cout<<num1<<"*"<<num2<<"="<<ret<<endl;
// 	return  0;
//}


//�ݹ��㷨�ж������Ƿ������ݼ�
//
//#include <stdio.h>
//
//void order (int* arr, size_t sz)
//{
//	if (sz == 0)
//		return ;
//	if (sz == 1)
//	{
//		printf("����Ϊ��������\n");
//	    return;
//	}
//	else if (arr[0] < arr[1])
//		order(&arr[1],sz-1);
//	else 
//	{
//		printf("���鲻����\n");
//		return;
//	}
//}
//int main()
//{
//	int arr[6] = {3,4,5,6,7,6};
//	size_t size = sizeof(arr)/sizeof(arr[0])-1;
//	order(arr,size);
//	return 0;
//}
