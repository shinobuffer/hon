# hon
这是一个处理本子的命令行工具，支持如下功能：
- 解析本子的发布展会、作者、标题、翻译类型、标签等
- 根据本子的上述一个或多个属性对本子进行分类，可选择移动到指定位置

## 命名规范
本子的命名规范如下（基本涵盖所有日区本子），其中标题和作者两个部分通常是必须的，各个部分之间可以存在空格，暂不支持括号里面嵌套同类型的括号的场景（如`(str1(str2))`）
> `(发布展会)[发布圈 (作者)]标题(类型)[语言][标签]...`

# 使用
```bash
# -i --info 解析本子信息
hon -i "(FF40) [山含] 色色運動大會 (ブルーアーカイブ) [中国語] [無修正] [DL版].zip"

# -r --recursive 启用递归
# -v --verbose 显示操作详情
# -g --group-by 根据发布展会（convention）/作者（author）/类型（type）对目录下的本子进行分类
# --copy-to 将分类结果拷贝至指定目录
# --move-to 将分类结果移动至指定目录
hon -r -g author --copy-to ./R18 ./Downloads
```