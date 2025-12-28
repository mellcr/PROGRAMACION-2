import java.util.Scanner;

class Persona{
	//1. poner los atributos , indicando si sera publico o no
	private int dni;
	private String nombre; //tiene su propio constructor
	private double sueldo;
	private char sexo;
	
	//2. Los metodos se implementan dentro de la clase 
	// CONSTRUCTORES
	public Persona(){ //constructor por defecto
		//ventas = 0.0 -> si es acumualtivo si 
		sueldo = 0.0; //no es necesario 
	}
	
	public Persona(int dni,String nombre,double sueldo){//constructor por parametros
		this.dni = dni;//el string permite hacer el igual
		this.nombre = nombre;
		this.sueldo = sueldo;
		this.sexo = sexo;
	}
	
	public Persona(Persona per){//constructor por parametros
		asignar(per);
	}
	
	//Destructor-> NO implementar (se encarga el recolector de basura)
	
	// METODOS 
	public void SetDni(int d){
		dni = d;
	}
	public int GetDni(){
		return dni;
	}
	public void SetSueldo(double s){
		sueldo = s;
	}
	public double GetSueldo(){
		return sueldo;
	}
	public void SetNombre(String n){
		nombre = n;
	}
	public String GetNombre(){
		return nombre;
	}
	public void SetSexo(char s){
		sexo = s;
	}
	public char GetSexp(){
		return sexo;
	}
	
	////////////////////////// METODOS SELECTORES //////////////////////////////
	
	public void imprimirDatos(){
		//imprimir con formato jiji
		System.out.printf("%10d %5c %-50s %10.2f\n", dni, sexo, nombre, sueldo);
	}
	
	public void asignar(Persona per){
		this.dni = per.dni;//el string permite hacer el igual
		this.nombre = per.nombre;
		this.sueldo = per.sueldo;
		this.sexo = per.sexo;
	}
	
	public void leerDatos(Scanner arch){
		String aux;
		
		dni = arch.nextInt();
		aux = arch.next();
		sexo = aux.charAt(0);
		nombre = arch.next();
		sueldo = arch.nextDouble();
	}
	
}