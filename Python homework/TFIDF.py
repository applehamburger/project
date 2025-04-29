'''使用未简化的TFIDF公式计算每日新闻关键词'''
import os
import re
import math
def readData(dire):
    res=[]
    fileList=os.listdir(dire)#
    for file in fileList:
        if file.endswith('.txt'):
            res.append(dire+r'/'+file)
    return res

def TF(dire):
    tf={}
    fileList=readData(r"C:\Users\67327\Desktop\gmrb_lex")
    for file in fileList:
        total=0#文章总词数
        tfidf={}#存储每个词的词频
        with open(file,encoding='utf-8')as fr:
            for line in fr:
                line=re.split(r'[\s\n]',line)
                if line[0] !='':
                    total+=int(line[1])
                    tfidf[line[0]]=int(line[1])#词--数量
        for word ,count in tfidf.items():
            tfidf[word]=count/total
        tf[file]=sorted(tfidf.items(),key=lambda d:d[1],reverse=True)
    return tf
#tf=TF(r'D:\CalAgriIndex202211681178\gmrb_lex')

def IDF(dire):
    idf={}
    filecount=0  # 文章数量
    fileList=readData(dire)
    for file in fileList:
        filecount += 1
        with open(file, encoding='utf-8') as fr:
            for line in fr:
                line=re.split(r'[\s\n]', line)
                word=line[0]
                if word in idf:
                    idf[word]+=1
                else:
                    idf[word]=1
                    
    for word, count in idf.items():
        idf[word]=math.log(filecount/(count+1))
    return idf

#idf=IDF(r'D:\CalAgriIndex202211681178\gmrb_lex')



def TFIDF(dire):
    tfidf={}
    tf=TF(dire)
    idf=IDF(dire)
    for file, tf_values in tf.items():
        tfidf[file]=[]
        for word, tf_value in tf_values:
            tfidf[file].append((word, tf_value*idf[word]))

    return tfidf

tfidf = TFIDF(r"C:\Users\67327\Desktop\gmrb_lex")
print(tfidf)
                       
        

    
    


