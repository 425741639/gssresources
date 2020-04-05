#!/usr/bin/env python
# coding: utf-8

# In[7]:


def g_max(ls):
    max_sum1=ls[0]
    max_sum=0
    for i in ls:
        if max_sum1<0:
            max_sum1=i
        else:
            max_sum1+=i
        if max_sum1>max_sum:
            max_sum=max_sum1
    return max_sum
def main():
    print("请输入一个数组：")
    x=input()
    ls= [int(n) for n in x.split()]
    max_sum=g_max(ls)
    print(max_sum)
main()

