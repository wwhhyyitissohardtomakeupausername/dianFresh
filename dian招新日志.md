# 要求

level0-1 自己写，重要的是学。

能一键编译运行

# dian招新题目日志

## 9.9

### 价格和代码

用string来存方便输出，使用时stoi和stof

### 代码？数组下标？

**方案一：暴力查找O(n)**

```cpp
int findindex(string code_in) {
    for(int i=1;i<=n;i++)
        if(code_in==items[i].code)
            return i;
    return 0；
}
```

**方案二：数组查找O(1)**

```cpp
int num[1000];//对应
//输入时
cin>>items[i].Code;
num[i]=stoi(items[i].Code);
```

### 输入不定数量的多个编号

**方案一：暴力拆字符串**

先当成一整个字符串，再按空格拆开。

**方案二：用stream机制**

诚实地说，ai给我讲的可以这么做。[但我去B站上学习了一下流机制]([C++之流01-上-基本概念，“流”的本质_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1V2CGYGEYa/?spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=832537d7a1d51d9e8beabd2f3291c4c1))

## 9.10

### 1.1第一个功能的口令

codeinput作为口令

## 9.11

### 环境的完善

在github上下载mingw

## 9.12

### streamtest

stream机制没运行起来，先建了个streamtest试一下。

要清除缓冲区里面的``'\n'`` ，不然后面读不进去。

### 发现vector

在探索vscode功能的时候偶然发现，决定重写EnterP()

## 9.13

### 1.1在探索新功能的同时完成

更深的了解到了关于scanf，cin，流的概念，分辨c和c++关于字符串方面的区别

### auto是什么东西？？？

## 9.14

### 购物车……条码下标对应……删除功能……

100多行的文件看着头疼，先把1.2相关的拿出来

### 代码可读性

学习增加代码可读性的操作，以应对上面的问题。

## 9.15

### 我应该试试多文件

代码越写越多，不方便添加新功能，一个文件里面也不好写

我应该补一些知识了。

## 9.16

### 简单了解了Git GitHub的操作

### 1.2的功能有问题

稍微改改，能实现1.1和1.2就行，然后就先学多文件，再慢慢做题目。

## 9.17

### 完成1.1和1.2的文件

准备先学习一下相关知识再做剩下的部分




