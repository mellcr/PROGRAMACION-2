import java.util.Scanner;
import java.util.ArrayList;

abstract class SolicitudReserva{
	private int dni; 
	private String nombre; 
	private char ubicacionDeseada; //T , S , E 
	private int cantidadPersonas; 
	private double hora; 
	private char ocasion; 
	private Mesa mesaAsignada; 
	private char estado; 
	
	//metodos selectores
	//como se puede observar en el setter de  un char 
	//se está empleando dos formas, una pasandole un string
	//y otra pasandole el mismo char
	//la idea es mostrar diversas formas de trabajo
	// Probablemente la mas adecuada sea pasarle el mismo tipo (char)
	//Sin embargo, en el proyecto se mostraran las dos :)
	public void SetUbicacionDeseada(String str){
		ubicacionDeseada = str.charAt(0); 
	}
	public void SetiOcasion(String str){
		ocasion = str.charAt(0); 
	}
	public void SetCantidadPersonas(int cantPer){
		cantidadPersonas = cantPer; 
	}
	public void SetHora(double ho){
		hora = ho;
	}
	public void SetEstado(char est){ 
		estado = est;
	}
	
	public abstract char GetTipo(); 
	
	public double GetHora(){ //getters
		return hora;
	}
	public char GetUbicacionDeseada(){ 
		return ubicacionDeseada; 
	}
	public char GetOcasion(){ 
		return ocasion; 
	}
	public int GetCantidadPersonas(){
		return cantidadPersonas; 
	}
	
	//OTROS METODOS 
	public void leeDatos(Scanner arch){
		String UbiDeseada,oca; 
		
		dni = arch.nextInt(); 
		nombre = arch.next(); 
		
		
		// UbiDeseada = arch.next(); 	
		//convertimos a char
		// ubicacionDeseada = UbiDeseada.charAt(0);
		
		// cantidadPersonas = arch.nextInt(); 
		// hora = arch.nextDouble(); 
		
		// oca = arch.next(); 
		//convertimos a char
		// ocasion = oca.charAt(0);
		
		
	}
	
}