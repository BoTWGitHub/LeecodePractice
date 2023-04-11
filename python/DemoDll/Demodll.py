from ctypes import cdll
import time as t

testCase = 40
dll = cdll.LoadLibrary('.\\DemoDll.dll')

print('\n========================\n')

start = t.time()
print(f'Fib({testCase})={dll.Fibonacci(testCase)}')
print(f'C DLL running time {t.time()-start}s')

print('\n========================\n')

def fib(n: int) -> int:
    if n<2:
        return n
    return fib(n-1)+fib(n-2)

start = t.time()
print(f'Fib({testCase})={fib(testCase)}')
print(f'Python running time {t.time()-start}s')

print('\n========================\n')