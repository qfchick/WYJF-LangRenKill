 # Boundless Mirror - LangRenKill command line werewolf kill

 ## Notice
 The project is under production, and the program is not completely developed, ** Do not use. **
 ` 铸造 ` Header file learning blog: https://blog.csdn.net/xiaochenxiaoren/article/details/105043385

 ## Original intention of production
 in order to ~~ loaf on a job ~~ Practice the use of c language, the implementation of algorithms, ~~ loaf on a job ~~ Integration skills

 ## Technical details
 - use *c 17 * Language standard writing
 - use ** Boundless Mirror Square ** Self developed c command line game tool library * 游戏工具 *
 - The tool library contains the self modified * 铸造 * Of header file ** All methods ** , will ` 圆锥形。 小时 ` and ` 圆锥形。 c（c） ` The documents are merged and some necessary modifications are added
 ** Magic revision * 铸造 * Also open for download **
 ** be careful ** : Use comparison * 铸造 * Just add the `gt:： ` Prefix. Note that the preceding `c（c）_ ` prefix
 ### Comparison and examples:
 #### The original conio&#38;magic modified conio
 ```中央处理器
#include <iostream>
#包括“conio.h”
整型main（）{
char c=c_getch();
std::cout<<c;

 while（！c_kbhit（））；
std::cout<<"kbhit"<<std::endl;
返回0；
 }
 ```
 #### 游戏工具
 ```中央处理器
#include <iostream>
#包括“gametool.h”
//使用名称空间gtl；
整型main（）{
char c=gtl::getch();
std::cout<<c;

 while（！gtl:：kbhit（））；
std::cout<<"kbhit"<<std::endl;
返回0；
 }
 ```
 - The code is divided into three files
 - ` 朗仁基尔.cpp ` : Main program, create game object, call game object method
 - `游戏。小时 ` : The main code of the game, which implements the game object, including the game object method
 - ` 游戏工具。 小时 ` : Game tool library, including game tool library ` 全球技术实验室 `

 ##
