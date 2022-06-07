#######################

def isPrime(num):
    if num == 2:
        return True
    elif num <2 or num%2 == 0:
        return False
    for i in range(3,num//3+2,2):
        if num%i==0:
            return False
    return True

def solution(numbers):
    answer = 0
    s = set()
    n = len(numbers)
    l = {str(a) for a in list(range(n))}
    for i in range(n-1):
        l.update({a + str(b) for a in l for b in range(n) if str(b) not in a})
    for x in l:
        a=[numbers[int(x[i])] for i in range(len(x))]
        add_num="".join(a)
        s.add(int(add_num))
    for i in s:
        if isPrime(i):
            answer+=1
    return answer
######################

def main():
    print(solution("01575"))
