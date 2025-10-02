# _SFUI V0.4.2_

a Simple and Fast User Interface as a SFML2.5.1 extension running on Android devices.

手机上可以用的轻量化的图像界面库，基于魔改版 SFML2.5.1。

## 特点
  1. 包含常见控件如按钮、进度条、输入框等。
  2. 包含常用功能如滑动、自动换行、辅助对齐等。
  3. 包含虚拟输入如摇杆、键盘等。

## 使用方法（C4Droid）
  1. 首先下载 Release 中的 SFUI源码 和 SFML_Support，解压到你的工程目录。
  2. 在编译选项中添加（请确保 -std≥c++17）：
```
-I/你的目录/_SFMLsupport/include/ -I/你的目录/_SFMLsupport/src/ -I/你的目录/SFUI_0.4.2/include/
```
  3.头文件先导入定制化SFML再导入SFUI：
```
#include <SFML/Graphics.hpp>
#include <SFUI/Graphics.hpp>
```
  4.若要使用虚拟输入功能，需单独导入：
```
#include <SFUI/VirtualInput/NumberKeyboard.hpp>
#include <SFUI/VirtualInput/VJoystick.hpp>
```
  5.开始你的代码之旅，建议首先学习SFML使用。\
  6.SFUI教程暂未编写，其实很简单，看看示例文件和头文件定义摸索试试，有问题提issue.
