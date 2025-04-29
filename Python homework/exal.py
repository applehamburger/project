def readData(fn_test,fn_gold): 
    with open(fn_test,encoding='utf-8') as f:
         for line in f:
             line=line.strip()
             test_words=line.split(' ')
#读答案文件
    with open(fn_gold,encoding='utf-8') as f:
        for line in f:
            line=line.strip()
            gold_words=line.split(' ') 
    return test_words,gold_words


def locWords(words): #将分词结果（词列表）转化为位置组（列表）
    res,i,j=[],0,0 #结果列表和记录词首尾的变量,显然res改为集合，更方便
    for w in words:
        j=i+len(w)-1   
        res.append([i,j])
        i=j+1 
    return res


def cal(test_words,gold_words):
    loc_test=locWords(test_words) 
    loc_gold=locWords(gold_words)
    tp=0 
    for lt in loc_test: 
        if lt in loc_gold:
            tp+=1
    pre=tp/len(loc_test)
    rec=tp/len(loc_gold)
    f1=2*pre*rec/(pre+rec)
    return pre,rec,f1

def main(fn_test,fn_gold):
    test_words,gold_words=readData(fn_test,fn_gold)
    pre,rec,f1=cal(test_words,gold_words)
    print('Precision:',pre,'\tRecall:',rec,'\tF1-score:',f1)

main(r"C:\Users\67327\Desktop\python\news.seg.txt", r"C:\Users\67327\Desktop\python\news.gold.txt")

