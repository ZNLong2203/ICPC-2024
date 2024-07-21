import sys
import re

def solve():
    total_sum = 0
    int_max = 2147483647  # 2^31 - 1
    long_long_max = 9223372036854775807  # 2^63 - 1

    for line in sys.stdin:
        numbers = re.findall(r'\d+', line)
        for number in numbers:
            num = int(number)
            if (num > int_max and num <= long_long_max):
                total_sum += num

    print(total_sum)

if __name__ == "__main__":
    solve()