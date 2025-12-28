import java.util.Scanner;
import java.util.ArrayList;

class UsoArrayList{
	public static void main(String []arg){
		//1. definir el obj lista de personas
		ListaDePersonas listaPersonas = new ListaDePersonas(); // ?????
		//2. metodos del arraylist de ListaDePersonas
		listaPersonas.leerPersonas();
		listaPersonas.mostrarDatos();
		
		System.out.println();
		System.out.println("Datos ordenados por dni y nombre");
		listaPersonas.ordenar();
		listaPersonas.mostrarDatos();
	}
}