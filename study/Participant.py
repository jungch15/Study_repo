def solution(participant, completion):
    answer = ' '
    hashTable = {}
    for i in completion:
        if hash(i) in hashTable:
            hashTable[hash(i)] += 1
        else:
            hashTable[hash(i)] = 1
    for j in participant:
        key = hash(j)
        if key in hashTable:
            hashTable[key] -= 1
            if hashTable[key] <0:
                answer = j
                break
        else:
            answer = j
            break
    return answer
