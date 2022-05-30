def solution(phone_book):
    dic = {}
    for num in phone_book:
        dic[num] = num
    for i in phone_book:
        for j in range(len(i)):
            if i[:j] in dic:
                return False
    answer = True
    return answer
