---
title: 全局变量VS局部变量
tags: Knowledge
---

变量可以分为全局变量和局部变量<!--more-->

---

|              |           全局变量           |          局部变量          |
| :----------: | :--------------------------: | :------------------------: |
|    作用域    |    在整个工程中都可以使用    | 只能在自己的局部范围内使用 |
|   生命周期   | 从定义变量的位置到源文件结束 |        仅限于{}内部        |
|    初始值    |              0               |           随机值           |
| 在内存的位置 |            静态区            |            栈区            |

当全局变量和局部变量同名时，优先使用局部变量~