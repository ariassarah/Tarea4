#QUIZ 3
PuntoNemo.pdf : Plots.py datos.txt
		python Plots.py
datos.txt : a.out
		./a.out
a.out :PuntoGeographicPoint.c
		cc PuntoGeographicPoint.c -lm 