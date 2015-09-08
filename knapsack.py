# problem plecakowy	z powtarzalnymi przedmiotami
from collections import namedtuple
Item = namedtuple("Item","w, v")

# Założenia

items = (Item(5,8), Item(2,3), Item(1,1)) # dostępne przedmioty
volume = 10 # pojemność plecaka

# Algorytm

# Tablica A przechowuje maksymalne wartosci dla kolejnych wag
A = [0 for i in range(volume+1)]

for i in range(volume+1):
	for item in items: # Przejrzenie dostepnych przedmiotow
		if(item.w <= i):
			A[i] = max(A[i - item.w] + item.v, A[i])
	
# Wypisanie wyniku

print("Można spakować przedmioty o wartości {0}".format(A[volume]))

for i in range(len(A)):
	print ("A[{0}] = {1}".format(i, A[i]))
	
