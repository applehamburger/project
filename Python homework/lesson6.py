# 1. 作业选讲


# 2. 程序调试debug
def sift_prime(n):
    is_primes = [True] * (n+1)    # 建立是否为质数的列表，为方便计算，设初始大小n+1全是True--质数
    primes = []
    for i in range(1, int(n**0.5)+1):
        if is_primes[i]:
            for j in range(i*2, n+1, i):    # i*2可改成i*i，会少筛选一些已经比较过的数字
                is_primes[j] = False
    # 至此，在if_primes中，所有的false都为筛掉的
    primes = [i for i in range(2, n+1) if is_primes[i]]

    return primes

print(sift_prime(50))
# 2.1 jupyter notebook中：可用print
# 2.2 IDE中：一般用IDE中的断点调试功能
# 其他方法自行搜索
'''
调试 debug
设置断点toggle breakpoint
单步执行 step over
进入函数 step into
执行函数出来 step out
'''
# 让同学们debug的实例-1
def add_underscores(word):
    new_word = "_"
    for i in range(len(word)):
        new_word = word[i] + "_"
    return new_word

def my_reverse(word):
    return word[::-1]

phrase = "hello"
my_reverse(phrase)
print(add_underscores(phrase))

# 希望输出：_o_l_l_e_h_

# 让同学们debug的实例-2
L = [[5, 5.5, "dsfd"], (6, 56.6, "adfsa"), 5, 5,5, "asdksa"]
total = 0
for item in L:
    if isinstance(item, int) or isinstance(item, float):
        total += item
    elif isinstance(item, list) or isinstance(item, tuple):
        for e in item:
            if isinstance(item, int) or isinstance(item, float):
                total += item
print(total)

# 3. 字符串复习与随堂测试
'''
字符串是不可变序列，类似tuple，但每个对象限制为在字符集中的单个字符，且是连续的，无逗号分隔
可用索引取得各个位置的元素，可相加相乘，可遍历，可切片，支持+=，*=，可比较大小
有count，find，index方法，count可以统计某字符串在一个字符串中的出现次数
find/index方法可以找某字符串在主字符串中第一次出现的位置
字符串中有特殊符号可使字符转义，但也能控制使字符串中的转义失效
和列表/元组一样，可以判断某个字符子串是否在特定字符串中

随堂测试题：
从键盘读入任意长度大于13的字符串，且必须包含"ab"，且"ab"不在索引0位置。写程序：
0）判断"ab"是否在该自字符串中（10分）
1）打印其第一个字符（10分）
2）打印最后一个字符（10分）
3）正向打印所有字符（10分）
4）逆序打印所有字符（10分）
5）打印索引在[3,13)之间且间隔为3的切片（10分）
6）打印其中"ab"出现的频次（10分）
7）打印其中"ab"第一次出现的位置（索引）（10分）
8）打印一个包含任意转义字符的字符串（10分）
9）打印一个"生字符串"--raw字符串，该字符串包含任意转义字符（10分）
'''

# 4. 字符串方法选讲
s = "abcabcabcabcabc"
# startswith/endswith，返回True/False
print(s.startswith('abc'))
# 也有start，end参数，判断期间的字符串是否以某子串开头或结尾
print(s.startswith('abc', 1, 10))

# split切割字符串，返回一个列表，表内元素均为字符串
# 原字符串不变
# 不指定时，默认以空白字符进行分隔
# 空白字符包括（连续的）空格，tab，换行符
s = "The quick brown fox jumps over the lazy dog."
words = s.split()
print(words)
print(s.split(' '))
print('a\n\n  b c   d\ne '.split())			    #['a', 'b', 'c', 'd', 'e']

# 可以指定字符
print('abcdabdebab'.split('a'))				#['', 'bcd', 'bdeb', 'b']
print('abcdabdebab'.split('ab'))			#['', 'cd', 'deb', '']

# split完整形式：str.split(sep=None, maxsplit=-1)->list(str)
# 其中maxsplit是最大切割次数，-1表示尽可能切割

# 当指定maxsplit为非默认值时，代表最多切几次，列表长度最长为maxsplit+1
print('The quick brown fox jumps over the lazy dog.'.split(maxsplit = 3))
print('a\nb c   d\ne '.split(maxsplit=2))

# join拼接可迭代对象，返回一个字符串，该方法可视为是split的逆方法
# 原对象不变
words = ['The', 'quick', 'brown', 'fox', 'jumps', 'over', 'the', 'lazy', 'dog.']
print(' '.join(words))

# 可迭代对象中每一个元素必须是字符串，否则会发生错误
print('+'.join('12345'))                   #1+2+3+4+5
print('喜欢'.join(('张三','李四','王五')))     #张三喜欢李四喜欢王五
print('+'.join([1,2,3,4,5]))                #TypeError

# replace字符串替换，替换原字符串中的所有子串，返回替换后的字符串
# 原字符串不变
s = "今天我考取了北京大学，北京大学耶！"
new_s = s.replace('北京', '北京语言')
print(new_s)

# 完整方法：str.replace(old, new, count)->str
# count是替换次数，不指定则替换最多次数
print('123123123'.replace('12', '一二', 2))

# strip方法去掉字符串两端特定的所有字符，返回处理后的字符串
print('123123321321'.strip('12'))
print('###... .... Section 3.2.1 Issue #32 .#... ...'.strip(' #.'))

# 如果不指定参数，则去掉两端所有空白字符
print(' \n  去掉两端空白字符  \n\n  '.strip())

# 利用partition切分字符串成三元组，返回一个tuple，内有3个字符串
print('大家都爱编程'.partition('爱'))
print('大家都爱编程'.partition('大'))
print('大家都爱编程'.partition('程'))
print('大家都爱编程'.partition('无'))

# 利用center使字符串居中
print("abcde".center(10))       # 字符串总长度
print("abcde".center(10, "+"))  # 第二个参数为用什么字符（单个str）填补
# 利用ljust使字符串左对齐
print("abcde".ljust(10))       
print("abcde".ljust(10, "+"))  
# 利用rjust使字符串右对齐
print("abcde".rjust(10))       
print("abcde".rjust(10, "+"))  

# 其他字符串方法（自行查阅python官方文档，教材教程等）
# 由于各类方法很多，可用help函数，查看各种对象、方法的用法
help(str.count)
help(str.replace)
help(list.pop)

'''
额外介绍python中很特别的一个函数eval函数
eval函数接受一个字符串形式的表达式，在经过对这个字符串的解析后，返回其“值”
'''
# 接受的字符串形式的表达式可以是列表等，eval可直接得到并返回对应数据类型的值（数据）
x = eval("[3,4,5]")
print(type(x))
print(eval("1,2,3"))
print(eval('{1:"2"}'))

# 还可以是合法的表达式，eval将计算并返回该表达式的值
x = eval("1+2")
print(x)
print(eval("1==2"))

# 还可以是变量名，但变量必须在该作用域中已经被赋值
some_arg = 123
test = eval("some_arg")
print(test)


# 还可以是函数，利用eval可以直接运行这个函数（可视为得到函数值，因而需要运行函数<---这很合理）
eval('print("Hello World！")')
# 自定义函数也可以，只要是在当前作用域中存在的已经实现的函数就可以

'''
课堂习题
1、利用字符串方法，打印字符三角形
2、读入一行字符串，里面是三个整数相加的字符串如：1+2+3。请将三个数字提取成整型数，赋值给x,y,z
3、读入一行字符串，里面是字符串如：1+2+3=？。请用两种方法计算出相加的结果，并输出：1+2+3=6

'''

# 5. 字符串格式化
# 有3种方法，这里介绍最新的f-string方法（python 3.6+）
# 只有当字符串内含有“槽”（即一对大花括号{}）时
# fstring才会根据槽内的对象的格式化配置进行控制
print(f"aaa")
print(f"{1234}")		#1234
# 9是对象（即1234）总共占的字符个数。
# 未没有指定对齐方式，默认为右对齐。字符总长不足时，默认用空格在左侧填补
print(f"{1234:9}")		#     1234
# ^表示居中对齐
# 字符无法在对象总宽度内完全对齐时，默认对齐重心向左偏移一位
print(f"{1234:^9}")		#     1234 
# >表示右对齐
print(f"{1234:>9}")		#     1234
# <表示左对齐
print(f"{1234:<9}")	

# 指定字符填补因对齐出现的空位
print(f'{1234:*>9}')		#*****1234
print(f'{1234:p^9}')		#pp1234ppp

# 对象的格式化配置通常为：{object:marker}，
# 即要控制的对象（object）以及配置该对象的标记符（marker）
# 对象只有一个，标记marker可以有多个，分别代表不同含义。可归纳为：
# {object:填充符 对齐符 长度值 数字千位分隔符.精度值 数据类型}
# 弄几页PPT
# 一个完整的例子
print(f"{31415.927:*<12,.2f}")		#31,415.93***

# 在槽中，字符串也可以作为格式对象
print(f"{'python':<10}")			#python    
print(f"{'python':^10}")			#  python
print(f"{'python':>10}")			#    python

# 格式字符串常量中除了槽，还可以有其他字符。
# 不在槽中的字符，将原样输出
print(f"左侧字符串{1234}右侧字符串")
print(f"左侧字符串{1234:<9}右侧字符串")
print(f"左侧字符串{{1234}}右侧字符串")

# 多个槽
print(f"Radius is {2}, PI is {3.1415927:.4f}, area = {3.1415927*2*2:>8.4f}")

# 以上的各个实例，均可改为变量来代替常量，注意，变量必须在槽中
x = 3.1415
s = "test"
print(f"{x:.2f}----{s:9}")