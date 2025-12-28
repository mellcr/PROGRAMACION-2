import java.util.Scanner; 

//la clase cilindro hereda de la clase circulo 
class Cilindro extends Circulo{
	private double altura;
	
	//constructor 
	//por parametros -> tmb se le pasa los parametros para la clase padre
	public Cilindro(String identificacion, double radio, double altura){ 
		//llamamos al constructor del circulo 
		super(identificacion, radio); //llama a la superclase pq es con parametros -> si fuera sin parametros se comenta esto 
		this.altura = altura; 
	}
	//NOTA: constructr sin parametros no necesita "super"
	//      constructor sin parametros se llama por defecto 
	
	//metodos selectores
	public void SetAltura(double a){
		altura = a;
	}
	public double GetAltura(){
		return altura; 
	}

	//indica que estamos sobrescribiendo la vista 
	@Override // es opcional, se coloca en cada funcion que se quiere sobreescribir 
	public double area(){
		//   Circulo::area()
		return 2*super.area()+altura*perimetro();  //super solo en area pq esta sobreescrito 
		// super -> se usa cuando hay ambiguedad 
	}
	
	//no se puede hacer en el main alguna instruccion que use un metodo del padre -> NO: super.GetArea() 
	//hacemos una mascara 
	public double areaBase(){
		return super.area(); 
	}
	
	public double volumen(){
		return super.area()*altura;
	}
}