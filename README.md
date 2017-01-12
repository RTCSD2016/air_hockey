Air Hockey
================

冰球仿真系统

实现目标
------

1. 机器人实时子系统
2. 物理引擎子系统
3. 游戏策略子系统

详见`doc`下的文件。

成员
-------

|   班级  |   姓名  |   学号  |   Github账号    |
| :---: | :---: | :---: | :--- |
|	机械1303	|	姜娇英	|	U201310615	|	[U201310615](https://github.com/U201310615)	|
|	机械1306	|	李君威	|	U201310747	|	[Justin1253610681](https://github.com/Justin1253610681)	|
|	机制1303	|	涂虎	|	U201310626	|	[lingqingyunjun](https://github.com/lingqingyunjun)	|
|	机械1304	|	王冉	|	U201310666	|	[rwang0417](https://github.com/rwang0417)	|
|	机械1301	|	张启宁	|	U201210709	|	[KNCheung](https://github.com/KNCheung)	|
|	机制1303	|	周佩	|	U201310616	|	[ritsuzp](https://github.com/ritsuzp)	|
|	机械1304	|	朱凯	|	U201310678	|	[KaiZhuhhhhhh](https://github.com/KaiZhuhhhhhh)	|

编译&运行
---------

0. 环境要求
    + 编译环境
        + xenomai 2.6.5 开发库
        + CppUnit 库（可选，未装则不会生成单元测试文件）
    + 运行环境
        + 正常运行 Xenomai 2.6.5 内核的 Linux 系统
        + Xenomai 需装有 Native Skin
1. 创建生成文件夹
2. 执行命令：`cmake <工程根目录>`
3. 执行编译命令：`make`
4. 在生成文件夹下的`build`目录下有生成的二进制文件
6. 执行
    + 单元测试：`build/unit_test`
    + 主程序：`build/air_hockey`

项目总结
--------------------

见[项目总结.md](项目总结.md)