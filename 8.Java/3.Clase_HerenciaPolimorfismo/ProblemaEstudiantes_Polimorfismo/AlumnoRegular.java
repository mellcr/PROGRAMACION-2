import java.util.Scanner; 

class AlumnoRegular extends Alumno{
	private String especialidad; 
	private String facultadad; 
	
	public AlumnoRegular(){
		
	}
	//metodos selectores 
	
	//OTROS METODOS 
	@Override
	public void leerAlumno(Scanner arch){
		super.leerAlumno(arch); 
		especialidad = arch.next(); 
		facultadad = arch.next(); 
	}
	
	@Override
	public void imprimeAlumno(){
		super.imprimeAlumno();
		System.out.println("Alumno regular: "); 
		System.out.println("Especialidad: " + especialidad); 
		System.out.println("Facultad: " + facultadad); 
	}
}