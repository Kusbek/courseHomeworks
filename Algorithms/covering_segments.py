# Uses python3
import sys
from collections import namedtuple
from operator import attrgetter
Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    points = []
    segments = sorted(segments, key=attrgetter('end'))
    point = segments[0].end
    points.append(segments[0].end)
    #write your code here
    for segment in segments:
        if (point<segment.start or point>segment.end):
            point = segment.end
            points.append(segment.end)
    return points

if __name__ == '__main__':
    input = sys.stdin.read()
    n,*data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    for p in points:
        print(p, end=' ')
