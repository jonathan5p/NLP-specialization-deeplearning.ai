# Viajero en una grilla m,n y solo se puede mover a la derecha o hacia abajo.
# La función tiene que encontrar todas las posibles formas de llegar del inicio (top left) al fin (bottom rigth) del tablero 

def gridTraveler(n,m,mem=None):
    
    if mem==None:
        mem={}

    if n == 0 or m == 0:
        return 0
    elif (n,m)==(1,1):
        return 1
    elif (n,m) in mem:
        return mem[(n,m)]
    else: 
        # Suma de la subgrilla si voy a la derecha más la subgrilla de si voy hacia abajo
        suma = gridTraveler(n,m-1,mem)+gridTraveler(n-1,m,mem) 
        mem[(n,m)]=suma
        return suma


print('init')
print(gridTraveler(1,1))
print('init')
print(gridTraveler(0,1))
print('init')
print(gridTraveler(3,3))
print('init')
print(gridTraveler(4,3))
# print(gridTraveler(18,18))