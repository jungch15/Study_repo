import time
import matplotlib.pyplot as plt

def evaluate_n(x):
    for i in range(x):
        a=i
   
def evaluate_n2(x):
    for i in range(x):
        a=i**x #이것도 x번 곱하는 거라 for에서 한번 여기서 한번 해서 제곱되나


n = list(range(100,5000,1000))


On2list=[]
Onlist=[]
for x in n:
    # evaluate_n2 호출
    before = time.process_time()
    evaluate_n2(x)
    after = time.process_time()
    On2 = after - before
    # evaluate_n 호출
    before = time.process_time()
    evaluate_n(x)
    after = time.process_time()
    On = after - before
    On2list.append(On2)
    Onlist.append(On)
plt.plot(n, On2list, 'r',n,Onlist)
plt.xlabel("n")
plt.ylabel("process time")

plt.show()
