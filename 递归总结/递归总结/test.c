// 汉罗塔之谜
/*#include <stdio.h>

void hanluota(unsigned int k, char a, char b, char c, int* count)  //n个盘子在B上，完成B移至C
{
	if (k == 0)
		return ;
	if (k == 1)
	{
		printf("把%c上的移至%c\n",b,c);         //最后一个盘子从B上移到C
	    (*count) ++;
		return ;
	}

	hanluota(k-1,c,b,a,count); //把n-1个盘子从B移到A上
	printf("把%c上的移至%c\n",b,c);
	(*count) ++;
    hanluota(k-1,b,a,c,count); //把n-1个盘子从A移至C上
}

int main()
{
	unsigned int n;
	int ret = 0;
	hanluota(5,'A','B','C',&ret);
	printf ("总共需要%d步\n",ret);
	return 0;
}
*/

//进制转化算法  把M进制转化为N进制

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

//大数乘法
//#include <iostream>
//#include <assert.h>
//#include <string.h>
//
//using namespace std;
//
//char* resver (char* dest)       //字符串翻转
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
//			  while (num3[i+j+count] >9)       //如果大于9进位
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
//	  resver(num3);              //将3个字符数组翻转回来
//	  resver(num1);
//	  resver(num2);
//      
//	  int k = 0;
//	  while (num3[k] == '0')      //计算前面是0的数目
//		   k++;
//
//	  memmove(num3,&num3[k],(126-k));   //将前面为0的部分覆盖      
//	  return num3;
//
//}
//
//int main()
//{
//	char num1[64] = "";        //乘数最多为63位最后一位放'\0'
//	char num2[64] = "";
//	char ret[127]={0};         //最大的结果为126 最后一位放'\0'
//	cout<<"输入乘数一："<<endl;
//	cin.getline(num1,64);
//	cout<<"输入乘数二："<<endl;
//	cin.getline(num2,64);
//	maxmlu(num1,num2,ret);
//	cout<<num1<<"*"<<num2<<"="<<ret<<endl;
// 	return  0;
//}


//递归算法判断数组是否递增或递减
//
//#include <stdio.h>
//
//void order (int* arr, size_t sz)
//{
//	if (sz == 0)
//		return ;
//	if (sz == 1)
//	{
//		printf("数组为递增数组\n");
//	    return;
//	}
//	else if (arr[0] < arr[1])
//		order(&arr[1],sz-1);
//	else 
//	{
//		printf("数组不递增\n");
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
