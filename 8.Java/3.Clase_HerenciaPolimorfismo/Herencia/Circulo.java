import java.util.Scanner; 

class Circulo{
	//atributos privados
	private String identificacion; 
	private double radio; 
	private final double PI=3.141592; //es una constante -> final 
	
	//constructores
	public Circulo(){
		radio = 0.0; 
	}
	public Circulo(String identificacion,double radio ){ //con parac
		this.identificacion = identificacion; 
		this.radio = radio; 
	}
	
	
	//metodos selectores 
	public void SetIdentificacion(String c){
		identificacion = c; 
	}
	public String GetIdentificacion(){
		return identificacion;
	}
	
	public void SetRadio(double c){
		radio = c;
	}
	public double GetRadio(){
		return radio; 
	}
	
	//metodos publicos 
	public double area(){
		return PI*radio*radio; //pi*radio^2
	}
	public double perimetro(){
		return 2*PI*radio; //2pi*radio 
	}
}