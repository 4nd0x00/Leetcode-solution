import numpy as np
import math 

# Sieve of Eratosthene

def closestPrimes(self, left, right):
    primes = np.arange(right+1)
    primes[0] = -1
    primes[1] = -1

    for i in range(2, int(math.sqrt(right))+1):
        if primes[i] != -1:
            primes[i*i::i] = -1

    primes = primes[primes != -1]
    primes = primes[primes >= left]
    min_diff, A, B = math.inf, -1, -1

    for i in range(1, len(primes)):
        curr = primes[i]-primes[i-1]
        if min_diff > curr:
            min_diff = curr
            A, B = primes[i-1], primes[i]

    return [A, B]