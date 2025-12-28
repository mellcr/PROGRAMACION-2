class Triangulo extends Figura{
	public Triangulo(String identificacion, double base, double altura){
		super(identificacion,base,altura); //llama al constructor por parametros de la super clase 
	}
	
	
	@Override
	public void CalcularArea(){
		System.out.printf("Figura: Triangulo (" + GetIdentificacion() + ") \n"); 
		System.out.printf("Formulaa = (base x altura)/2\n"); 
		System.out.printf("Area: %.2f\n", (GetBase()*GetAltura())/2);
	}
}
