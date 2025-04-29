# 1. 作业选讲


# 2. 实验课
# 2.1 写函数，接受任意多个字符串，返回一个列表，其中各个元素是每个字符串中的大写字母个数

def upper_times(s):
    if not isinstance(s, str):
        raise TypeError
    times = 0
    for c in s:
        if c.isupper():
            times += 1
    return times

def multi_str(*args):
    return [upper_times(s) for s in args]

print(multi_str("adfRE","adsfaEEE", "fsa"))

# 2.2 字符走马灯
'''
对给定的字符串，每次将其最后一个字符放到最前面（或第一个放最后面），循环打印，打印次数为字符串长度。
要实现走马灯的效果，则需要清屏和延时功能，可用os及time模块中的相应功能，读者可查阅官方文档。
'''
def revolving(letters):
    import os
    import time
    os.system('cls')
    n = len(letters)

    for i in range(n):
        letters = letters[-1] + letters[:-1]
        # letters = letters[1:] + letters[0]
        
        print(letters)  
        time.sleep(2)      
        os.system('cls')

revolving('赏花归去马如飞')

# 2.2 字符塔
'''
任务名称：回文字符塔
任务简述：程序将提示用户输入一个非空字符串，程序将这个字符串进行组合拆分，形成一个回文字符塔，该字符塔每一行均为回文字符串。
输入：一个字符串
输出：由输入的字符串组合而成的回文字符塔（字符串）
----------------------------------------------------------------------------------------------------------------------
输入用例：赏花归去马如飞
输出：
             赏
            赏赏
           赏花赏
          赏花花赏
         赏花归花赏
        赏花归归花赏
       赏花归去归花赏
      赏花归去去归花赏
     赏花归去马去归花赏
    赏花归去马马去归花赏
   赏花归去马如马去归花赏
  赏花归去马如如马去归花赏
 赏花归去马如飞如马去归花赏
赏花归去马如飞飞如马去归花赏
'''
line = '赏花归去马如飞'
for i in range(1, len(line)+1):    
    print(line[:i] + line[:i-1][::-1])
    print(line[:i] + line[:i][::-1])

# 当前为偏字符塔，前面空格，自行编程加上

############# 文本文件基本读写，文件的更多用法，将在后续几讲中逐步介绍
file = r"d:\temp\test_r.txt"
# 以只读（read）的模式打开文件，返回文件对象（可迭代类型）。如无则报错。
f = open(file)      # 如读取有问题可：f = open(file,encoding="utf8")
# 利用read方法读取文件对象内的所有字符作为一个str
txt = f.read()
print(type(txt))
# 打印该文件的前10个字符
print(txt[:10])
#关闭文件
f.close()	

# 文件读取的其他函数方法-readlines
f = open(file)
# readlines方法，将所有数据按行读入，返回一个列表，一行为一个元素
lines = f.readlines()
print(type(lines))
print(lines[:5])
f.close()

# 文件读取的其他函数方法-readline
f = open(file)
# readline方法，读入一行，返回一个str
line = f.readline()
print(type(line))
print(line)
f.close()

# 文件读取的其他函数方法-更适合大文件
f = open(file)
# 直接对文件对象f进行循环逐行读取，读取后可进行各种操作
for line in f:
    print(line)
f.close()

file = r"d:\temp\test_w.txt"
# 以写入（write）的模式打开文件，返回文件对象（可迭代类型）。
# 如无则创建一个空文件。如已存在，则先清空这个已经存在的文件。
f = open(file, "w")
# 利用write方法向文件对象f写入一个字符串，注意不会自动换行
f.write("001 张三   1班")
f.write("002 李四   1班")
f.close()	

# 文件写入的其他函数方法=writelines
# 写入时，各个元素是依次连续写入的，中间并没有’\n’或空格之类的分隔符
f = open(file, "w")
words = ["a", "b", "c"]
f.writelines(words)
f.close()

# 用print函数写入文件，将f文件对象传给file关键字参数
# 方法和格式等与打印在屏幕基本一致，只是重新定向到了文件
f = open(file, "w")
print('001 张三   1班', file=f)
print('002 李四   2班', file=f)
x = 3.1415
print(f'002{x:9} 李四   2班', file=f)
f.close()

# with语句打开文件
'''
文件被打开并使用后，必须关闭。
很多时候，忘记将文件关闭或中间被break而没有执行文件关闭
 这样文件数据可能就会出现意想不到的错误。为防止这样的错误
python提供了with上下文管理关键字，管理文件读写过程
'''
with open(file) as f:
    for line in f:
    	print(line)
# 当程序执行完with控制范围内的语句后（或意外退出）
# python解释器将自行将文件关闭，无需用户用close语句关闭。