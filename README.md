# 无垠镜方 - LangRenKill命令行狼人杀

## 公告
该项目正在制作中，程序未开发完整，**请勿使用。**  
`conio`头文件学习博客：https://blog.csdn.net/xiaochenxiaoren/article/details/105043385

## 制作初衷
为了~~摸鱼~~练习c++语言的使用，算法的实现，~~摸鱼~~整合的技巧

## 技术细节
- 使用 *c++17* 语言标准编写
- 使用**无垠镜方**自研的c++命令行游戏工具库 *gametool*
- 工具库内包含了自行魔改版的 *conio* 头文件的**全部方法**，将 `conio.h` 和 `conio.c` 文件合并，并加入了一些必要的修改  
    **注意**：使用相比 *conio* 只需在函数名前加`gt::`前缀，注意所有方法均去掉前面的`c_`前缀  
    ### 对比及例子：
    #### 原conio
    ```cpp
    #include <iostream>
    #include "conio.h"
    int main() {
        char c=c_getch();
        std::cout<<c;

        while(!c_kbhit());
        std::cout<<"kbhit"<<std::endl;
        return 0;
    }
    ```
    #### gametool
    ```cpp
    #include <iostream>
    #include "gametool.h"
    // 如只需要gtl内conio的内容，也可以导入gtconio.h，用法相同（同样提供）
    // using namespace gtl;
    int main() {
        char c=gtl::getch();
        std::cout<<c;

        while(!gtl::kbhit());
        std::cout<<"kbhit"<<std::endl;
        return 0;
    }
    ```
- 代码分为三个文件
    - `LangRenKill.cpp`：主程序，创建游戏对象，调用游戏对象方法
    - `game.h`：游戏主要代码，实现游戏对象，包含游戏对象方法
    - `gametool.h`：游戏工具库，包含游戏工具库`gtl`
    - `gtconio.h`：游戏工具库，包含游戏工具库`gtl`中`conio`部分的方法

## 
