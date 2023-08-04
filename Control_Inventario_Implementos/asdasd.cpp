#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int main(){
    // crea comando gnuplot para la gráfica de CPU
	std::string gnuplotCpuCommand =
	"
	";

	// crea comando gnuplot para la gráfica de memoria
	std::string gnuplotMemoryCommand = "gnuplot -p -e \"plot 'memory.txt' using 1:2 with linespoints title 'Uso de memoria'\"";

	// llama a gnuplot para que grafique la CPU
	int statusCpu = system(gnuplotCpuCommand.c_str());

	// llama a gnuplot para que grafique la memoria
	int statusMemory = system(gnuplotMemoryCommand.c_str());
    return 0;
}
