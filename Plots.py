import numpy as np 
import matplotlib.pyplot as plt 
# Leo todos archivos de datos
a=np.genfromtxt('map_data.txt',delimiter=' ')
b= np.genfromtxt('datos.txt')
# Defino las posiciones y los radios
x0 = b[:,0]
y0 = b[:,1] 
r = b[:,2]
# Calculo donde esta el radio maximo

maximo = r.argmax()
X = x0[maximo]
Y = y0[maximo]
r_ = r[maximo].mean()

#Grafico la imagen

plt.imshow(a)
# inicializo para graficar el radio el circulo
angulo = np.linspace(0, 2*np.pi, 100)
x = r_*np.cos(angulo) + X
y = r_*np.sin(angulo) + Y
# Grafico el circulo
plt.plot(y, x)
plt.plot([Y], [X], "o")
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Punto Nemo')

plt.savefig("PuntoNemo.pdf")
plt.close()