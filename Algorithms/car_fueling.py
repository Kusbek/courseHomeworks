# python3
import sys


def compute_min_refills(distance, tank, stops):
    stops.append(distance)
    stops.insert(0,0)
    next_tank = tank
    count = 0
    for i in range(0,len(stops)-1):
        current_station, next_station =  stops[i], stops[i+1]
        if (next_station - current_station > tank):
            return -1
        else:
            if(next_station>next_tank): 
                next_tank = current_station + tank
                count = count + 1         
    return count

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops))
