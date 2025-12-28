class Cuadrado extends Figura{
	public Cuadrado(String identificacion, double base, double altura){
		super(identificacion,base,altura); //llama al constructor por parametros de la super clase 
	}
	
	
	@Override
	public void CalcularArea(){
		System.out.printf("Figura: Cuadrado (" + GetIdentificacion() + ") \n"); 
		System.out.printf("Formulaa = base x altura\n"); 
		System.out.printf("Area: %.2f\n", GetBase()*GetAltura()); 
	}
	
}
