# function prints fibonacci numbers up to given value
def fib(max):          
	a = b = 1          
	while a <= max:                  
		print(a)         
		a, b = b, a + b
