import java.util.Scanner; 


class Alumno{
	private int codigo; 
	private String nombre; 
	
	
	//CONSTRUCTOR
	public Alumno(){
		
	}
	//METODOS SELECTORES 
	
	
	//OTROS METODOS
	public void leerAlumno(Scanner arch){
		codigo = arch.nextInt(); 
		nombre = arch.next(); 
	}
	
	public void imprimeAlumno(){
		imprimeLinea('=',60); 
		System.out.printf("Codigo del alumno: %d\n",codigo); 
		System.out.printf("Nombre del alumno: %s\n",nombre); 
	}
	
	public void imprimeLinea(char c, int n){
		for(int i=0; i<n; i++){
			System.out.print(c);
		}
		System.out.println(); 
	}
	
}