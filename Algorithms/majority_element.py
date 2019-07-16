# Uses python3
import sys

def get_majority_element(a, left, right):
    half = left + (right-left)//2
    if left == right:
        return -1
    if (right - left) == 1:
        return a[left]
    else:
        y = get_majority_element(a,left, half)
        x = get_majority_element(a,half,right)
        maj_elements = (a for a in (x,y) if a!=-1)
        for maj_element in maj_elements:
            count = 0
            for i in range(left,right):
                if(a[i]== maj_element):
                    count = count + 1
                if (count > (right-left)/2):
                    return maj_element
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
