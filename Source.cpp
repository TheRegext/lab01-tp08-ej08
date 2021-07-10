#include <iostream>

int main() {
	int vendedor_provincia[30];
	int codart, dia, mes, codven, cantidad;
	float importe;


	//Punto A
	float provincia_recaudacion[24][12]{};

	//Punto B
	float articulo_recaudacion[200]{};


	// Punto C

	bool vendedor_articulo[30][200]{};

	//Punto D
	float vendedor_recaudacion[30][12]{};


	for (int i = 30; i > 0; i--) {
		std::cout << "Ingrese Provicia del vendedor " << i << ": ";
		std::cin >> vendedor_provincia[i-1];
	}

	std::cout << "Ingrese codigo de articulo: ";
	std::cin >> codart;

	while (codart != 0) {
		std::cout << "Dia: ";
		std::cin >> dia;
		std::cout << "Mes: ";
		std::cin >> mes;
		std::cout << "Código de vendedor: ";
		std::cin >> codven;
		std::cout << "Cantidad vendida: ";
		std::cin >> cantidad;
		std::cout << "Importe de la venta: ";
		std::cin >> importe;

		provincia_recaudacion[vendedor_provincia[codven - 1] - 1][mes - 1] += importe;
		vendedor_recaudacion[codven-1][mes-1] += importe;
		
		articulo_recaudacion[codart - 1] += importe;

		vendedor_articulo[codven - 1][codart - 1] = true;

		std::cout << "Ingrese codigo de articulo: ";
		std::cin >> codart;
	}

	// Punto A
	for (int prov = 0; prov < 24; prov++) {
		float may = 0;
		int bim;

		for (int mes = 0; mes < 12; mes+=2) {
			float rec = provincia_recaudacion[prov][mes] + provincia_recaudacion[prov][mes + 1];

			if (rec > may) {
				may = rec;
				bim = mes / 2 + 1;
			}
		}

		std::cout << "Provincia: " << prov + 1 << "        Bimestre: " << bim << "\n";
	}

	// Punto B
	float total = 0;
	for (float r : articulo_recaudacion) {
		total += r;
	}

	for (int art = 0; art < 200; art++) {
		std::cout << "Articulo: " << art + 1
			<< "    Recaudacion: " << articulo_recaudacion[art]
			<< "    Porcentaje: " << articulo_recaudacion[art] / total * 100 << "\n";
	}

	// Punto C
	for (int vend = 0; vend < 30; vend++) {
		int cant = 0;

		for (int art = 0; art < 200; art++) {
			if (vendedor_articulo[vend][art]) {
				cant++;
			}
		}

		if (cant > 5) {
			std::cout << "Vendedor: " << vend + 1 << "\n";
		}
	}



	// Punto C
	for (int vend = 0; vend < 30; vend++) {
		float may = 0;
		int bim;

		for (int mes = 0; mes < 12; mes += 3) {
			float rec = vendedor_recaudacion[vend][mes] + vendedor_recaudacion[vend][mes + 1] + vendedor_recaudacion[vend][mes + 2];

			if (rec > may) {
				may = rec;
				bim = mes / 3 + 1;
			}
		}

		std::cout << "Vendedor: " << vend + 1 << "        Trimestre: " << bim << "\n";
	}






	return 0;
}