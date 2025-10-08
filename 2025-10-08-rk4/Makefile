hw.x: hw_rk4.cpp
	g++ -std=c++23 hw_rk4.cpp -o hw.x

data.txt: hw.x
	./hw.x > data.txt

fig.pdf: plot.py data.txt 
	python plot.py

clean:
	rm -f *~ *.txt a.out *.x
