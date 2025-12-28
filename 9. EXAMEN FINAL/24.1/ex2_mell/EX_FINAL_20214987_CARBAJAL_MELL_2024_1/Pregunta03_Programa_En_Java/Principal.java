//MELL ALESSANDRA CARBAJAL ROMAN 20214987
import java.util.Scanner;
import java.util.ArrayList;

class Principal{
	public static void main(String []arg){
		Restaurante restaurante; 
		restaurante = new Restaurante(); 
		
		//apertura del archivo 
		Scanner archivo = new Scanner(System.in); 
		
		//metodos de restaurante
		restaurante.leeMesas(archivo); 
		restaurante.leeSolicitudes(archivo);
		
		
	}
}