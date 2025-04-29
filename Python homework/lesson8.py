# 1. 作业选讲


# 2. 文本字符统计
# 2.1 统计一个字符串中出现的字符列表（写函数）：输入为字符串，返回一个列表
def get_chs(s):
    chs = []
    for c in s:
        if c not in chs:
            chs.append(c)
    return chs

# 2.2 给定一个字符串，给定对应的字符列表，输出字符串中各个字符的个数（写函数） 
# 输入为字符串，返回一个列表（[[x, 1], [y,3]....]）
def count(s, chs):
    freqs = []
    for ch in chs:
        freqs.append(s.count(ch))

    return freqs

# 2.3 对文件进行字频统计
'''
打开文件，统计文件中每一个字出现的频次（汉字、英文字符、空格等均统计）
并输出任意10个字及对应的频次
'''
# 2.3.1 方法1：先得到字表，再根据子表得到字频
def count(s):
    chs = []
    for c in s:
        if c not in chs:
            chs.append(c)
    freqs = []
    for ch in chs:
        freqs.append(s.count(ch))
    
    return zip(chs, freqs)

file = r"dangzhang2022-01.txt"      # 自行手动建立test.txt存在指定位置，然后再读入
with open(file, encoding="utf8") as fr:
    txt = fr.read()

print(list(count(txt)))

# 2.3.2 方法2：扫描一遍字符串，一边形成字符表一边进行字符统计
def my_counter(s):
    char_freq_lst = []
    for c in txt:
        for char_freq in char_freq_lst: # 对在字-频-列表中的每一个[字-频]
            if c == char_freq[0]:       # 如果c==字
                char_freq[1] += 1       # 对应的频+1
                break                   # 已经找到这个c，因此break，要查找下一个c
        else:
            char_freq_lst.append([c, 1])    # 没有出现过c，因此加入[c,1]
    return char_freq_lst

file = r"test.txt"  
with open(file) as f:
    txt = f.read()

print(my_counter(txt)[:10])

# 2.3.3 两种方法对比分析

# 2.4 对文件进行词频统计
# 2.4.1 利用jieba分词等工具包进行分词
'''
https://github.com/fxsjy/jieba
上面的网址中有用法说明。
分词所涉及到的技术原理：
1、前缀词典、DAG（有向无环图）---《数据结构》中涉及或讲授。
2、HMM模型、Viterbi算法--- 《计算语言学》中涉及或讲授。
3、动态规划--- 《算法导论》中讲授
基本使用实例：
import jieba
seg_list = jieba.cut("我考上了北京大学旁边的北京语言大学") # ---> list
print(" ".join(seg_list)) # 我 考上 了 北京大学 旁边 的 北京 语言 大学
'''
import jieba

file = r"199801.txt"
with open(file) as f:
    txt = f.read()

seg_list = jieba.cut(txt)

file = r"199801_cut.txt"
with open(file, "w") as f:
    f.write(" ".join(seg_list))

# 2.4.2 对分词后的文件进行词频统计
def my_counter(words):
    word_freq_lst = []
    for word in words:
        for word_freq in word_freq_lst: 
            if word == word_freq[0]:    
                word_freq[1] += 1 
                break                   
        else:
            word_freq_lst.append([word, 1]) 
    return word_freq_lst

file = r"199801_cut.txt"
with open(file) as f:
    txt = f.read()

words = txt.split()
print(my_counter(words)[:10])

# python中的模块（module：单个文件构成）与包（package：多个文件构成）
'''
在python中，模块（Module）就是一个包含python程序代码的文件，该文件以.py作为扩展名。模块内一般多为能实现某种特定功能的函数。
用户既可以针对自己某项任务，自行定义并设计好模块并保存在本地，随时加载，还可以上传并共享给整个python社区。
python语言维护者以及开源社区的专家与编程爱好者们，已经将很多常用模块写好，一些内置在python语言中，可以直接使用，
还有一些针对特定任务的模块，需要另行下载安装后使用。这些模块功能强大、覆盖面广，可以毫不夸张地说，覆盖了你能想到的方方面面。
这就形成了python良好的生态社区，这也是python除了简单易学外，能够持续流行的原因所在。
'''
# 安装标准库外的包
# pip install 包名
# conda install 包名 或 conda install -c conda-forge 包名
# pip与conda还有很多用法，其中pip只能安装包，conda还有虚拟环境管理的功能，详细用法自行搜索

# 自定义模块
def add_two_numbers(a, b):
    return a+b

def multiply_two_numbers(a, b):
    return a*b

# 将以上代码保存到当前工作目录下的文件：my_math.py，即创建了一个my_math模块。
import my_math							#导入模块

x = my_math.add_two_numbers(10, 20)		#调用my_math模块下的add_two_numbers
y = my_math.multiply_two_numbers(10, 20)

# 自定义包
'''
在某目录比如当前目录：
1、创建一个目录名作为未来的包名，比如my_package
2、在my_package下，创建包配置文件__init__.py，可为空文件
3、在my_package下，创建1-n个模块，假设创建了两个模块：my_math, my_word
4、在当前目录中建立.py文件，就可以 import my_package.my_math
目录格层次为：
my_package
--__init__.py
--my_math.py
--my_word.py
'''
'''
发布自定义包至PyPI，以及模块与包的详细说明，参见官方文档：
https://docs.python.org/3/tutorial/modules.html
或网络自行搜索
'''

# 4 递归
'''
函数自己直接/间接调用自己的方法/技巧，称为递归（recusive）。这种函数也称为递归函数。
python语言支持递归
'''
# 4.1 第一类递归：问题的定义是递归的
# 4.1.1 阶乘
def factorial(n):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)

print(factorial(5))

# 4.1.2 斐波那契数列第n项
def fibonacci(n):
    if n in (1, 2):
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)
    
print(fibonacci(6))	

# 4.2 第二类递归：问题的求解过程是递归的
#李永乐讲解汉诺塔问题： https://www.bilibili.com/video/BV1gJ41177fX/?share_source=copy_web&vd_source=c03fb9dfd522cabcb52e22ad78b26705
# 汉诺塔-1：打印移动过程与步骤，不要求模拟确实存在柱子和盘子
def hanoi(n, A, B, C):
    if n==1:
        print(A,'--->',C)
    else:
        hanoi(n-1, A, C, B)
        print(A,'--->',C)
        hanoi(n-1, B, A, C)

# 以4个盘子做测试
hanoi(4, 'A', 'B', 'C')

# 4.3 第三类递归：数据结构可视为是递归的
# 递归打印列表元素
def print_recusion(nums_):
    if not nums:
        return        
    else:
        print(nums_[0])
        if len(nums_) > 1:
            print_recusion(nums_[1:])

nums = [1,2,3,4,5]
print_recusion(nums)

# 练习：写递归函数，可反向打印一个列表

# 作业