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

### 改名引发的Git指令学习

熟悉了远程重命名和重定向，过程有点坎坷，D老师总结belike



```
    今天这一顿操作，虽然踩了不少坑，但你实际上已经掌握了 Git 日常工作中 80% 的高阶操作。为了方便你以后随时查阅，我把我们用到过的所有指令按功能分类整理成了一份**速查表**：
    ### 📁 一、 终端与文件操作 (PowerShell)
    *   `cd 文件夹名`：进入指定的文件夹。
    *   `cd ..`：返回上一级目录。
    *   `Remove-Item -Path ".\.git" -Recurse -Force`：强制删除目录下的隐藏 `.git` 文件夹（用来清理嵌套仓库）。
    ### 🏗️ 二、 Git 仓库初始化与状态
    *   `git init`：在当前目录初始化一个新的本地 Git 仓库。
    *   `git status`：查看当前工作区的状态（文件是否被修改、是否暂存、是否有冲突）。
    ### 📝 三、 Git 提交流程（最常用）
    *   `git add .`：把当前目录下所有修改过的文件添加到“暂存区”。（注意最后有个点 `.`）
    *   `git commit -m "提交信息"`：把暂存区的内容提交到本地仓库，`-m` 后面跟着你写的备注（比如 "修复了bug"）。
    ### 🌐 四、 远程仓库管理 (GitHub)
    *   `git remote add origin <URL>`：首次关联一个远程仓库（`origin` 是远程仓库的默认别名）。
    *   `git remote set-url origin <URL>`：**修改**已关联的远程仓库地址（当你重命名了 GitHub 仓库或改了地址时使用）。
    *   `git remote -v`：查看当前关联的远程仓库地址是否正确。
    *   `git push -u origin main --force`：强制把本地代码推送到远程 `main` 分支，并建立追踪关系。
        *   `--force`：强制覆盖，一般用于本地重置仓库后覆盖远端。**日常千万别随便加！**
        *   `-u`：建立关联后，以后再推送直接用 `git push` 即可。
    *   `git push`：日常写代码后的推送命令（不带任何参数，直接推送到已关联的远端）。

    ### 🧹 五、 清理嵌套仓库与暂存区
    *   `git rm -r --cached .`：清空暂存区，但**保留本地文件**（用来移除嵌入的子模块记录）。
    *   `git rm -r --cached . -f`：强制清空暂存区（当普通命令因为冲突执行失败时使用）。

    ### 💻 六、 C++ 编译相关
    *   `g++ 1.2test.cpp -o a1.exe`：编译源文件并生成可执行文件 `a1.exe`。
    *   `.\a1.exe` (或直接 `a1.exe`)：运行生成的程序。

    ### ⌨️ 七、 VS Code 快捷键
    *   `F2`：在资源管理器中重命名选中的文件或文件夹。
    *   `Ctrl + ~`：打开/关闭底部集成终端。
    *   `Ctrl + Shift + P` -> 输入 `Reload Window` -> 回车：重新加载 VS Code 窗口（当左侧源代码管理面板卡顿、不刷新时，用这招瞬间治好）。
```

### 学习了函数、指针、引用和时间查询的基本内容

之前学的时候不做重点的内容

## 9.18

### 学习指针、面向对象

更深入地学习了指针和类的基础知识

## 9.19

### 学习类、文件输入输出

## 9.21

军训结束，类和分文件学习收尾，准备Cmake

### 顺利掌握类和分文件写法

大概明白了，准备着手开始

### D老师教我CMake

```

一、mkdir 是什么意思？mkdir 是 Make Directory 的缩写，意思是“创建文件夹（目录）”。

归属：它是操作系统的终端命令（在 Windows PowerShell、Mac、Linux 中通用），不属于 CMake。

作用：在当前目录下创建一个新的文件夹。

用法：mkdir build 就是新建一个名为 build 的文件夹。

为什么用：为了把编译产生的中间文件（.obj、.exe）和源代码文件（.cpp、.hpp）隔离开，保持项目目录整洁。

二、CMake 相关指令总结为了方便你以后复习和写进 dian招新日志.md，我把刚才的操作分为两部分：终端命令 和 CMakeLists.txt 内容。

1. 终端命令（手动挡工作流）⚠️ 注意：cd、mkdir、.\ 属于系统终端命令，不是 CMake 发明的，但它们是 CMake 构建流程的好搭档。

指令 作用 归属cmake --version 检查 CMake 是否安装，输出版本号。 CMakemkdir build 创建一个叫 build 的文件夹。 终端 (系统)cd build 进入 build 文件夹。 终端 (系统)cmake -G "MinGW Makefiles" .. 配置阶段。读取上一级目录的 CMakeLists.txt，生成 Makefile。-G 指定使用 MinGW 生成器。 CMakecmake --build . 构建阶段。读取当前目录的 Makefile，调用 g++ 编译代码并链接成 .exe。 CMake.\box_app.exe 运行程序。. 代表当前目录，运行刚才编译出来的可执行文件。 终端 (系统)💡 日常口诀（配置一次，构建无数次）：第一次：mkdir build -> cd build -> cmake -G "MinGW Makefiles" ..以后每次改代码：cd build -> cmake --build . -> .\box_app.exe

2. CMakeLists.txt 文件中的指令（项目图纸）这是你写在 CMakeLists.txt 里的内容，是 CMake 的核心配置。

指令 作用 备注cmake_minimum_required(VERSION 3.10) 声明项目需要的 CMake 最低版本。 必须写在第一行。project(BoxTest) 给项目起个名字。 名字随意，纯英文即可。set(CMAKE_CXX_STANDARD 11) 设置 C++ 标准为 C++11。 建议以后改为 17 以支持新特性。set(CMAKE_CXX_STANDARD_REQUIRED ON) 强制要求编译器支持指定标准，不支持就报错。 防止编译器悄悄降级。add_executable(box_app mltf_class.cpp Box.cpp) 核心指令。告诉 CMake 生成一个名叫 box_app 的可执行文件，由后面的 .cpp 源文件编译而成。 如果新增了 .cpp 文件，必须加在这里。

```

## 9.22

### 正式开始做1.1

Item基本功能已完成，达到1.1的要求

## 9.23

### 编写class Cart相关

## 9.24

### Class Cart设置

首先，选`map`

其次，key选`std::string`，存条码

最后，值选`Item`，方便打印信息，`cart[code].stock`表示购买数量，

### 准备测试

我打算写一个信号处理的类，专门处理输入输出和文件管理，但好像这会导致相互调用，我先测试一下，没问题就来学一下相关。

### 测试完成

另外，crtl+f crtl+h快速查找和更改

### sale的设计

sale有day和id双重属性

方案一：sale里面放sale_id和day，使用时一个vector搞定，此时sale代表一次的流水

方案二：sale里面放结构体vector，外面再做一个vector下表为day，此时sale代表一天的流水

~~决定，Sale管临时流水（内存），FileMangement管长期（文件）~~

### cart的修改

total动态，考虑现实情况，不会有在结账的时候改变价格的情况，只读进来是多少就认多少

### Sale和SaleManager的使用

Sale到底要不要？

还是要，作为一个中转，当个接口

SaleManager要涉及哪些功能？

1.追加写⼊⽂件

2.查看当⽇所有销售记录及总营业额，省略 day 参数默认为今天

3.开始新的⼀天：清空当⽇销售记录（内存中的记录清空，但⽂件中的历史记录保留，可另存为带⽇期的⽂件，或清空⽂件但保留历史⽂件）

初想法：来个vector存一天的，一天完直接clear，符合题目描述，而且简洁

### day和sale_id的储存和使用

## 9.25

### SaleManager的使用

如果在cart::checkout里面调用，数据存哪里？能达到当日内内存能直接调用，新的一天清空内存但信息存在文件里面吗？

### 解决方案

**这两天关于Cart/Sale/SaleManager的责任划分不够清晰，导致前前后后思路混乱。究其根本是我对类的设计经验不足，可以专门学一下。**

重新划定`Cart.checkout()`职责，reutrn本次记录，打印，清空。这样Cart的实际就可以彻底结束了，把剩下的交给SaleManager。

Sale类似于Item的作用，露接口，小的临时的对象

SaleManager当一个大的对象，在总程序中声明一个

### 代码健壮性

后面来加，但现在默认输入完全合理。

### SaleManager

初想法：里面`std::vector<Sale> daily_record;`，外面`std::vector <SaleManager> manager;`，daily_record下标表示一日流水号，manager下标表示天数

不行，太过复杂，太丑了。就定义一个SaleManager。

### CSV文件读取、统一转换与屏幕输出


