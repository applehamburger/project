
# coding: utf-8

# In[ ]:


'''请对二十大报告进行分词操作（使用jieba模块）

1输出词频表wordFreq.txt（无需排序，只要有词和对应的次数即可）

2告知有多少种不同的词，只出现了1次？有多少种不同的词只出现了2次？3次的呢？
'''
import jieba

file=r"D:\20thReport.txt"
with open(file,encoding='utf-8') as fr:
    txt=fr.read()

dd=jieba.lcut(txt)         
hh=[]
for i in dd:
    if i not in hh:     #去除重复项
        hh.append(i)

HH=[]
for i in hh:            
    HH.append([i,dd.count(i)])


k=0
for i in HH:
    if i[1]>=k:          #找出最高的频次
        k=i[1]

for i in range(1,k+1):
    count=0              
    for j in HH:
        if j[1]==i:
            count=count+1
    if count!=0:
        print("共有",count,"个数出现了",i,"次")
        

        
'''读取“学习二十大：字频统计”任务中二十大报告的字频表，
将其封装为形如“[[王,200176],[刘,149887],[了,3455668]......]”的数据结构。
不使用sort()函数，对这个列表根据频次多寡，从大到小进行排序，
并将排序好的列表，以和之前任务相同的格式输出为chs_sort_20Report.txt'''
file=r"D:\20thReport.txt"

f=open(file,encoding='utf-8')
txt=f.read()
f.close()

TT=list(txt)

tt=[]
for i in TT:
    if i not in tt:
        tt.append(i)
HH=[]
for i in tt:
    HH.append([i,TT.count(i)])
    
for i in range(len(HH)):
    for j in range(len(HH)-1-i):
        if HH[j][1]<=HH[j+1][1]:
            HH[j],HH[j+1]=HH[j+1],HH[j]

fr=r"D:\chs_sort_20Report.txt"

f=open(fr,'w')

f.write(str(HH))jif
            
f.close()




'''写函数，以递归思想完成以下任务：

写递归函数my_rec_sum(a,b)完成累加操作，并测试从1累加到100

写递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19。输入：1729，输出：19

刘院士每次可以选择走一阶或者走两阶，那么他一共有多少种走法？LiuStep(n)，以10为例进行测试。'''


def my_rec_sum(a,b):
    if a==b:
        return b
    else:
        return a+my_rec_sum(a+1,b)

print(my_rec_sum(0,100))


def Digitsum(n):
    i=0
    while n%(10**i)!=n:
        i=i+1
    t=n//10**(i-1)
    if i==1:
        return n
    else:
        return t+Digitsum(n-t*(10**(i-1)))
        
print(Digitsum(1729))


def Liustep(n):
    if n<=2:
        return n
    else:
        return Liustep(n-1)+Liustep(n-2)


print(Liustep(10))






'''请编写程序，读取文本文件20thReport。并将总书记在二十大报告中所有包含“中国式现代化”的句子写入文本文件ChineseMordernization中。

提示操作顺序：1读取文件；2按照换行和句号切分文本，形成列表；3遍历列表并找寻包含关键词的成员；4将这些成员写入文件中。'''
#现代化4.18
file= r"D:\20thReport.txt"
f= open(file,encoding="utf-8") 
T=f.read()
f.close()

l=[]
l=T.split('。')
words=('\n'.join(l))
t=[]
t=words.split('\n')

s=[]
for j in t:
    for k in range(len(j)):
        if k<len(j) and j[k]=="中":
            if k+1<len(j)and j[k+1]=="国":
                if  k+2<len(j)and j[k+2]=="式":
                    if k+3<len(j)and j[k+3]=="现":
                        if k+4<len(j)and j[k+4]=="代":
                            if k+5<len(j)and j[k+5]=="化":
                                s.append(j)
 
file2 = r"D:\ChineseMordernization.txt"
f2 = open(file2, "w")
for i in s:
    print(i,file=f2)
    print('\n',file=f2)
f2.close()




'''哈沙德数（Harshad number）是数论中的一个概念，指的是那些能够被自己的数字和整除的正整数集合。
因为自己的数字就是自己本身，显然1到9全是哈沙德数。比如42的数字和是4 + 2 =6，42能被6整除，是一个哈沙德数，并且它是第20个哈沙德数。（你记得42的梗吗？）

请编写函数，计算1000以内所有的哈沙德数。

'''
def is_harshad_number(n):
    # 将数字n拆分成各位数值
    digits = [int(d) for d in str(n)]
    # 计算n的数字和
    digit_sum = sum(digits)
    # 判断
    return n % digit_sum == 0


def find_harshad_numbers(limit):
    # 存储所有哈沙德数
    harshad_numbers = []
    for i in range(1, limit+1):
        if is_harshad_number(i):
            harshad_numbers.append(i)
    
    return harshad_numbers


# 查找1000以内所有的哈沙德数并输出
harshad_numbers = find_harshad_numbers(1000)
print("1000以内的哈沙德数有：", harshad_numbers)





'''写函数，读入一行字符串，里面是三个整数进行加减乘除的字符串如：1+2+3或1x4/5。
算式中没有括号。请将三个数字提取成整型数，赋值给x,y,z。并计算出结果。'''
def calculate(s):
    
    tokens = s.replace('+', ' ').replace('-', ' ').replace('x', ' ').replace('/', ' ').split()
    
    # 将分割得到的三个数字转化为整数型
    x, y, z = map(int, tokens)
    
    # 遍历原始字符串，根据加减乘除符号计算出结果
    result = None
    for i in range(len(s)):
        if s[i] == '+':
            result = x + y + z
            break
        elif s[i] == '-':
            result = x - y - z
            break
        elif s[i] == 'x':
            result = x * y * z
            break
        elif s[i] == '/':
            result = int(x / y / z)
            break
    
    return result
    

# 测试
s = '1+52+4'
result = calculate(s)
print(s, '=', result)






'''写函数，针对字符串s，回答以下问题：

字符串有几个单词？

字符串中每个单词各出现了多少次？采用成员为元组的列表返回结果，如[(love,3),(never,1)]这样

如果不使用count函数怎么做？

s=r'love never fails no matter you believe ''''\
def word_count(s):
    # 利用空格分割字符串得到单词列表
    words = s.split()
    # 计算总单词数
    count = len(words)
    
    # 构建字典，记录每个单词出现的次数
    word_dict = {}
    for word in words:
        if word not in word_dict:
            word_dict[word] = 1
        else:
            word_dict[word] += 1
    
    # 将字典转化为元组的列表
    word_list = [(word, count) for word, count in word_dict.items()]
    
    return count, word_list


def word_count_without_count(s):
    # 利用空格分割字符串得到单词列表
    words = s.split()
    # 总单词数初始化为0
    count = 0
    
    # 构建字典，记录每个单词出现的次数
    word_dict = {}
    for word in words:
        # 如果单词不在字典中，则将其添加，并将计数值初始化为1
        if word not in word_dict:
            word_dict[word] = 1
        else:
        # 如果单词已经在字典中，则将其计数值加1
            word_dict[word] += 1
        # 每处理一个单词，总单词数加1
        count += 1
    
    # 将字典转化为元组的列表
    word_list = [(word, count) for word, count in word_dict.items()]
    
    return count, word_list
s=r'lov0 always good for you and for me and for everyone someone and having no end no earth no answer least'

# 使用count函数
count, word_list = word_count(s)
print("单词数：", count)
print("每个单词出现次数：", word_list)

# 不使用count函数
count, word_list = word_count_without_count(s)
print("单词数：", count)
print("每个单词出现次数：", word_list)





'''写函数，不使用python内置函数，对一个长字符串进行排序。测试样例“loveneverfailsnomatteryoubelieveitornot”'''
def string_sort(s):
    n = len(s)
    for i in range(1, n):
        j = i
        while j > 0 and s[j] < s[j-1]:
            s = s[:j-1] + s[j] + s[j-1] + s[j+1:]
            j -= 1
    return s
s = "loveneverfailsnomatteryoubelieveitornot" 
sorted_s = string_sort(s)
print(sorted_s)



'''写函数，功能是max与min函数的合体，返回最最大值和最小值，并用多个实数为参数进行调用该函数并用两个变量分别存最大值和最小值'''
#最值4.3
def zuizhi (*n):
    maxs=-1000000
    for i in n:
        if i>maxs:
            maxs=i
    mins=1000000
    for j in n:
        if j<mins:
            mins=j
    return maxs,mins

a,b=zuizhi(1,2,3,4,5)
print(a,,b)




'''编写函数，将一段英文中单词中间错写的“l”修改为“I”，不用正则。

测试文本：I saw two FBls going down lower into the rooms.

'''
#斐波勒4.3
def change(line):
    s=line
    i=s.find('l')
    s=s[0:i+1].replace('l','I')+s[i+1::]
    return s

line='I saw two FBls going down lower into the rooms.'
print(change(line))





'''写函数，输入为用户指定的一个符号，输出为用该符号构成的图形。
要求可输出四种直角三角形（直角分别在左下、左上、右下、右上）和两种等腰三角形（顶角在上，顶角在下）'''
#星星塔4.4
s=input("请输入符号：")
b=int(input("你喜欢的高度："))
def zuoxiazhijiao(s):
    for i in range(1, h+1):
        print(s*i)


def zuoshangzhijiao(s):
    for i in range(1, h+1):
        print(s*(h-i+1)+' '*(i-1))
        

def youxiazhijiao(s):
    for i in range(1, h+1):
        print(' '*(h-i)+s*i)
        

def youshangzhijiao(s):
    for i in range(1, h+1):
        print(' '*(i-1)+s*(h+1-i))


def shangdingjiao(s):
    for i in range(1,h+1):
        print(' '*(h-i)+s*(2*i-1))
        
def xiadingjiao(s):
    for i in range(1,h+1):
        print(' '*(i-1)+s*(2*(h-i+1)-1)+' '*(i-1))
zuoxiazhijiao(s)

zuoshangzhijiao(s)

youxiazhijiao(s)

youshangzhijiao(s)

shangdingjiao(s)

xiadingjiao(s)






'''穷举法验证哥德巴赫猜想

任何一个大于3的偶数均可以表示为两个素数之和

 （要求穷举n=10000以内的偶数，得到分解列表，并打印最后10个偶数与分解成的两个素数）。

提示：注意课上习题的做法、注意求N以内素数的做法

'''

#哥德巴赫猜想 3.27
n=10000
list1=[2]
list2=[]
lista=[]
listb=[]
listo=[]
for i in range(3,n+1):
    j=2
    for j in range(2,i):
        if i%j==0:
            break
        else:
            list1.append(i)
for q in range(1,n+1):
    if q%2==0:
        listo.append(q)
list2=listo[4990:5000]

for e in list2:
    flag=False
    a=2
    for a in list1:
        if flag==True:
            continue
        b=2
        
        for b in list1:
            if e==a+b:
                
                lista.append([e,a,b])
                flag=True
                continue
print(lista)




'''质数的距离 

写（多个）函数，用列表记录小于n的所有相邻质数之间的距离。如3和5之间的距离是2。5和7之间的距离也是2。7和11之间是4。本题规定第一个质数为3。主程序令n为1000进行测试。 

a 计算小于n的所有质数，并输出。

b 计算所有质数之间的距离，装入列表并输出。

c 不使用Python内置函数，计算这些距离的最大值、最小值、平均距离和距离方差。

d 计算超过平均值的距离的个数。

'''
#质数的距离 3.28  

def sushu(m):
    i=1
    j=0
    while i<m/2:
        i+=1
        if m%i==0:
            j+=1
    if j==0:
        return m
    else:
        return 0
    

def lenth(l):
    s=[]
    i=0
    while i<len(l):
            j=0
            j=i+1
            if j<len(l) and l[j]-l[i]!=0:
                if l[j]-l[i]>0:
                    s.append(l[j]-l[i])
                else:
                    s.append(l[i]-l[j])
            i+=1
    return s       


def zuida(n,nums=[]):
    maxs=0
    for i in range(n):
        if nums[i]>maxs:
            maxs=nums[i]
    print('最大值=',maxs)


def zuixiao(n,nums=[]):
    mins=1000000
    for i in range(n):
        if nums[i]<mins:
            mins=nums[i]
    print('最小值=',mins)


def pingjun(n,nums=[]):
    s=0
    for i in range(n):
        s+=nums[i]
    average=s/n
    print('平均值=',average)
    return average


def fangcha(c,nums=[]):
    s=0
    t=0
    z=0
    for i in range(len(nums)):
        z=(nums[i]-c)*(nums[i]-c)
        t=z+t
    s=t/len(nums)
    print("方差=",s)
    
def then(d,nums=[]):
    j=0
    for i in range(len(nums)):
        if nums[i]>d:
            j+=1
    print("超过平均值的距离的个数=",j)
    

for k in range(3,1000):
    if sushu(k)!=0:
        print(sushu(k),end=' ')      
print('\n')


l=[]
x=0
for x in range(3,1000):
    if sushu(x)!=0:
        l.append(sushu(x))
print(lenth(l))

n=len(lenth(l))
zuida(n,lenth(l))
zuixiao(n,lenth(l))
y=pingjun(n,lenth(l))
fangcha(y,lenth(l))

then(y,lenth(l))



'''列表a_list内包含120个成员，均为(0,100]的随机正整数。请分别编写函数：

（1）生成a_list

（2）不使用python内置函数，由a_list中的内容，生成从小到大内容有序的列表b_list

（3）不使用python内置函数，计算a_list中内容的均值，并打印超过均值的成员的下标'''

#列表 3.27
import random
def generate_a_list():
    a_list = []
    for i in range(120):
        num = random.randint(1, 100)
        a_list.append(num)
    return a_list
def sort_a_list(a_list):
    b_list = []
    for i in range(len(a_list)):
        for j in range(i, len(a_list)):
            if a_list[i] > a_list[j]:
                a_list[i], a_list[j] = a_list[j], a_list[i]
    b_list = a_list
    return b_list
def print_index_above_mean(a_list):
    sum = 0
    for num in a_list:
        sum += num
    mean = sum / len(a_list)
    for i in range(len(a_list)):
        if a_list[i] > mean:
            print(i)
a_list = generate_a_list()
print(a_list)
b_list = sort_a_list(a_list)
print(b_list)
print_index_above_mean(a_list)

