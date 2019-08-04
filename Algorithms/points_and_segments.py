# Uses python3
import sys

import collections
import numpy as np
def fast_count_segments(starts, ends, points):
    left, p, right = ("l", "p", "r")
    count = [0] * len(points)

    pairs = []
    for start in starts:
        pairs.append((start, left))
    for end in ends:
        pairs.append((end, right))
    for point in points:
        pairs.append((point, p))
    np_points = np.array(points)    
    sorted_points_indices = np.argsort(np_points)
    index = 0
    sorted_pairs = sorted(pairs)

    coverage = 0
    for pair in sorted_pairs:
        if pair[1] == left:
            coverage += 1
        if pair[1] == right:
            coverage -= 1
        if pair[1] == p:
            count[sorted_points_indices[index]]=coverage
            index += 1

    return count

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
