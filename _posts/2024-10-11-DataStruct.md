---
title: C语言数据类型
tags: Knowledge
---



C语言提供了丰富的数据类型，有内置类型和自定义类型。

<!--more-->

## 内置类型

### 字符型

~~~c
char//char不一定是signed char，C语言并没有规定char==signed char
char ch = 'a';
//ch到底是signed还是unsigned，取决于编译器
[signed] char //有符号的，[]里的可以省略不写
unsigned char //无符号的
~~~

### 整型

~~~c
[signed] short [int] //
unsigned short [int] //
[signed] int //
signed num = 1;//默认num是int类型
unsigned int //
[signed] long [int] //
unsigned long [int] //
[signed] long long [int] //c99中引入
unsigned long long [int] //
//整型变量声明unsigned的好处是：同样长度的内存能表示的最大整数值增大一倍
~~~

### 浮点型

~~~c
float //单精度浮点型
double //双精度浮点型
long double //c99中引入
~~~

### 布尔类型

~~~C
//早期C语言并没有为布尔值单独设置一个类型，而是使用0表示假，非0表示真
_Bool //c99中引入，如包含头文件<stdbool.h>
#defien bool _Bool //将_Bool定义为bool
#define true 1
#define false 0
bool flag1 = true;
bool flag2 = false;
//代码可读性更高了
~~~

### 数据类型的取值范围

每一种数据类型都有自己的取值范围，也就是存储的数值的最大值和最小值范围，limits.h头文件中说明了整型类型的取值范围，float.h头文件中说明了浮点型类型的取值范围。

~~~c
//想知道某种整型类型的极限值时，尽量使用这些常量。
SCHAR_MIN//signed char最小值
SCHAR_MAX//signed char最大值
UCHAR_MAX//unsigned char最大值
SHRT_MIN//signed short最小值
SHRT_MAX//signed short最大值
USHRT_MAX//unsigned short最大值
INT_MIN//signed int最小值
INT_MAX//signed int最大值
UINT_MAX//unsigned int最大值
LONG_MIN//signed long最小值
LONG_MAX//signed long最大值
ULONG_MAX//unsigned long最大值
LLONG_MIN//signed long long最小值
LLONG_MAX//signed long long最大值
ULLONG_MAX//unsigned long long最大值
~~~



## 自定义类型

(待补充)

## 各种数据类型的长度

### sizeof操作符

sizeof是一个关键字，也是操作符，用来计算操作数的类型长度，单位是字节。sizeof的操作数可以是类型，也可以是变量名或表达式。

~~~c
int num = 10;
printf("%zd\n",sizeof(num));
printf("%zd\n",sizeof num);//操作数是变量时，可以省略括号
printf("%zd\n",sizeof(int));
//sizeof的计算结果是size_t类型的，使用 %zd 打印
//关于sizeof运算符的返回值，C语言只规定是无符号整数，并没有规定具体的类型，而是留给系统自己决定
//不同系统的返回类型可能不同，unsigned int、unsigned long、unsigned long long，对应的占位符分别是%u、%lu、%llu。
//不利于程序的可移植性
//C语言为此提供了一个解决方法，使用size_t统一表示sizeof的返回值类型

printf("%zd\n", sizeof(char));//1
printf("%zd\n", sizeof(bool));//1
printf("%zd\n", sizeof(short));//2
printf("%zd\n", sizeof(int));//4
printf("%zd\n", sizeof(long));//4
printf("%zd\n", sizeof(long long));//8
printf("%zd\n", sizeof(float));//4
printf("%zd\n", sizeof(double));//8
printf("%zd\n", sizeof(long double));//8
//不同的环境计算出的值不同，以上是VS2022 x64的计算结果

short sum = 0;
int num = 10;
printf("%zd\n",size0f(sum = num + 1));//2
printf("sum = %d\n",sum);//0
//sizeof()括号中的表达式不会计算，sizeof在代码进行编译的时候，就根据表达式
//的类型确定好了，所以在代码运行阶段就不会执行表达式了
~~~

---

下次再见~

