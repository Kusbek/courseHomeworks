# Uses python3
import sys

def get_change(money):
    coins = [1,3,4]
    inf = 1000
    
    if money == 0:
        return 0
    minNumCoins = [inf]*(money+1)
    minNumCoins[0]=0
    for m in range(1,money+1): 
        for coin in coins:
            if m >= coin:
                num_coins = minNumCoins[m - coin]
                if (num_coins<inf and num_coins+1<minNumCoins[m]):
                    minNumCoins[m] = num_coins+1
    return minNumCoins[money]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
