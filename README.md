[![Project Status: Inactive - The project has reached a stable, usable state but is no longer being actively developed; support/maintenance will be provided as time allows.](http://www.repostatus.org/badges/latest/inactive.svg)](http://www.repostatus.org/#inactive)

# 概述

本驱动可以对直流电动机进行简单的控制，包括速度调节、方向控制等。本驱动基于Arduino Mega 2560，如果你使用的是其他版本的arduino，请视情况做相应的修改。

# L298N

L298N是专用驱动集成电路，属于H桥集成电路，与L293D的差别是其输出电流增大，功率增强。其输出电流为2A，最高电流4A，最高工作电压50V，可以驱动感性负载，如大功率直流电机，步进电机，电磁阀等，特别是其输入端可以与单片机直接相联，从而很方便地受单片机控制。当驱动直流电机时，可以直接控制步进电机，并可以实现电机正转与反转，实现此功能只需改变输入端的逻辑电平。

使用该驱动器可以驱动两台直流电动机，假设分别为M1和M2。引脚ENA和ENB可用于输入PWM脉冲宽度调制信号，实现对电动机的调速控制,PWM信号端ENA控制M1调速，PWM信号端ENB控制M2调速。实现电动机的方向控制也非常容易：输入信号端IN1接高电平，输入端IN2接低电平，电动机M1正转;反之则反转。控制另一台电动机也是如此：输入信号端IN3接高电平，输入端IN4接低电平，电动机M2正转;反之则反转。

# 使用本驱动

## 引脚连接

| L298N     | Arduino  |
| :------------- | :------------- |
| ENA | D5 |
| IN1 | D7 |
| IN2 | D8 |
| ENB | D6 |
| IN3 | D9 |
| IN4 | D10 |

- 电源

使用12V电源，因此+12v接线柱接电源正极，GND接电源负极。

- 电动机

| L298N     | MOTORS |
| :------------- | :------------- |
| OUT1 | 左电机线+ |
| OUT2 | 左电机线- |
| OUT3 | 右电机线- |
| OUT4 | 右电机线+ |

## 注意事项

- 要给L293N单独供电，不要将电源接在Arduino上；
- 给L293N通电时，电源正负极千万不要接反，否则很容易烧毁板子；

## 速度控制

对单个电动机控制：

    ｒ　100

其中命令ｒ代表设置右前轮速度，参数100为速度大小。

下表是了列举了各命令代表的含义：

|编号| 命令 | 含义 |
| :-------------: | :-------------: | :------: |
| 0 | l       | 设置左前轮       |
| 1 | r       | 设置右前轮       |
| - | A       | 设置所有车轮     |


## 方向

只要将参数设置为负值，即可改变电动机旋转方向。

## 停止

如果你想终止电动机转动，可以使用命令`s`或者`S`：

    s 0     # 终止左轮
    S       # 终止所有车轮

命令非常好理解，通过车轮对应的编号即可终止相应的车轮。

**NOTE:** 当然，将速度设置为0也可以达到相同的效果。

具体可以查看程序中的`command.h`文件:

```
#define CLEFT       'l'
#define CRIGHT      'r'

#define ALLWHEELS	'A'
#define STOPWHEEL       's'
#define STOPWHEELS      'S'
#define FORWARDS        true
#define BACKWARDS       false
```

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议</a>进行许可。
