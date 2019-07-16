# Uses python3
import sys

def optimal_sequence(n):
    inf = 1000000
    count = [inf]*(n+1)
    sequence = [[inf]]*(n+1)
    count[0] = 0
    count[1] = 0
    sequence[0] = [0]
    sequence[1] = [1]
    for i in range(2,n+1):
        sub_index1 = i-1
        if i % 3 == 0:
            sub_index2 = i//3
        else:
            sub_index2 = i
            
        if i % 2 == 0:
            sub_index3 = i//2
        else:
            sub_index3 = i
        indexes = [sub_index1,sub_index2,sub_index3]
        counts = [count[sub_index1], count[sub_index2], count[sub_index3]]       
        min_index = counts.index(min(counts))
        count[i] = count[indexes[min_index]]+1
        x = sequence[indexes[min_index]].copy()
        x.append(i)
        sequence[i] = x
    return sequence[-1]

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
