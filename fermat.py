import random

def prime_test(N, k): # O(k*n log n) or O(n log n)
    i = 0 # O(n bits) space
    u = N - 1 # Calculates u beforehand so it only has to do it once. O(n bits) space
    tests = ([])# O(m n bits) space
    while u % 2 == 0: # O(n log n)
        u = u / 2 # O(n)
    if k > N - 2: # Shrinks k down if k is too large. O(1)
        k = N - 2 # O(1)
    while i < k: # O(k*n log n)
        same = True # O(1 bit) space
        while same: # Makes sure that the values of a are not repeated O(n)
            a = random.randint(2, N - 1) # O(n), O(n bits) space
            if a not in tests: # O(1) because it tests is a set.
                tests.append(a) # Keeps a set of all the values of a previously tested O(1)
                same = False # O(1)
        if mod_exp(a, N - 1, N) != 1: # O(n log n)
            return 'not prime' # O(1)
        if carmichael_test(N, a, u): # O(n log n)
            return 'not prime' # O(1)
        i += 1 # O(1)
    return 'prime' # O(1)


def mod_exp(x, y, N): # O(n log n)
    if y == 0: # O(1)
        return 1 # O(1)
    z = mod_exp(x, int(y / 2), N) # Divides y until it equals 0, casts it as an int so it will round down when. O(n log n)
    if((y % 2) == 0): # O(1)
        return ((z * z) % N) # O(n)
    else:
        return ((x * z * z) % N) # O(n)


def probability(k): # O(k n)
    prob = 1 - (1 / 2**k) # O(k n) O(n bits) space
    return prob # O(1)



def carmichael_test(N, a, u): # O(n log n)  
    test = 0 # O(n bits) space
    amount = 1 # O(n bits) space
    while (amount * u) <= (N - 1): # O(n log n)
        if amount == 1: # It has to use the mod_exp the first time, after that it can just square it. O(1)
            test = mod_exp(a, u, N) # O(n log n)
            if test == 1: # O(1)
                return False # O(1)
        else:
            test = (test**2) % N # O(n)
        if test == (N - 1): # O(1)
            return False # O(1)
        else:
            amount = amount * 2 # O(n)
    return True # O(1)

#Uncomment these lines to be able to analyze an excel sheet of these numbers.
#amount = input("Up to what number?")
#amount = int(amount)
#output = open("test+1.csv", "w") # Creates a .csv file
#index = 2
#output.write("N,")
#counter = 1
#while counter < amount:
#	output.write(str(counter) + ",")
#	counter += 1
#output.write("\n")
#while index <= amount:
#	print(index)
#	output.write(str(index) + ",")
#	counter = 1
#	while counter < index:
#		output.write(str(mod_exp(counter, index + 1, index)) + ",")
#		counter += 1
#	output.write("\n")
#	index += 1