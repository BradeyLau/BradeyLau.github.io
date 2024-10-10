---
title: C语言中 main 函数的类型和参数
tags: Knowledge
---

在一个C语言程序里，不论代码有多少行，程序都是从main函数开始执行。__main函数也被称为程序的入口，有且仅有一个，即使有多个 .c 文件，也只能存在一个main函数__。

<!--more-->

---

首先，我们来认识一下main函数的标准写法：

~~~c
int main(){
    //code
    return 0;
}
~~~

相信大家曾经在书上见过另一种main函数的写法，如下：

~~~c
void main(){
	//code
}
~~~

有何区别？主要区别在于函数是否有返回值，int表示函数有一个整型的返回值，void表示函数不需要返回值。虽然在某些编译器中void main可以编译通过，但在其他编译器中可能会报错，为了代码的可移植性，推荐使用**int main()**。

那么这种main函数呢？

~~~c
int main(void){
    //code
    return 0;
}
~~~

这里的void表示main函数不需要参数，这个写法不算是错误的，是符合标准的，也可以什么都不写。

也许你会有这样的疑问，如果main函数有参数呢？很好！那什么情况下会用到这些参数呢？我们都知道程序需要交互，这些main函数里的参数就能让我们在程序启动的时候给程序传参

~~~c
int main(int argc, char* argv[]){
    //code
    return 0;
}
~~~

**argc**: argument count，是命令行参数的数量，包括程序本身的名称。因此，argc的值至少是1，并且argc不用用户输入，程序会自己计算值是多少。

**argv**: argument vector，是指向字符串数组的指针，其中每个元素是一个指向 传递给程序的参数的 指针。这些参数是通过命令行传递给程序的。

举个例子

~~~c
int main(int argc, char* argv[]) {
	printf("argc=%d\n", argc);
	printf("%s\n", *argv);
	return 0;
}
~~~

![image1](https://github.com/BradeyLau/BradeyLau.github.io/blob/master/_posts/image-202410093.png?raw=true)

显然，argv[0]就是指向程序名称的字符串指针。

再举个例子，这次我们多输入几个参数值

~~~c
int main(int argc, char* argv[]) {
	int i;
	printf("参数个数：%d\n", argc);
	printf("程序名称：%s\n", argv[0]);
	for (i = 1; i < argc; i++) {
		printf("参数 %d: %s\n", i, argv[i]);
	}
	return 0;
}
~~~

![image2](https://github.com/BradeyLau/BradeyLau.github.io/blob/master/_posts/image-202410094.png?raw=true)

可以看到，我们在命令行中执行程序时给了两个参数string1和string2，于是程序输出结果是参数有3个：程序本身的名称、string1j和string2。

argv[1]是指向string1的字符串指针，argv[2]是指向string2的字符串指针。

---

最后，总结一下：一般情况下，__推荐使用int main()，如果需要给main函数参数，就写成int main(int argc, char* argv[])__

下次再见~