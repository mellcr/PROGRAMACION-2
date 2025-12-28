// no ttiene area, no tiene nada -> es una clase abstracta -> no se puede instanciar 
//no se puede definir un objeto de esta clase 
// no tiene forma xd , es algo que no puede tocar 
abstract class Figura{
	private String identificacion; 
	private double  base; 
	private double altura; 
	
	//constructor por param 
	public Figura(String identificacion, double base, double altura){
		this.identificacion = identificacion; 
		this.base = base; 
		this.altura = altura; 
	}	
	//metodos selectores
	public void SetIdentificacion(String c){
		identificacion = c; 
	}
	public String GetIdentificacion(){
		return identificacion;
	}
	
	public void SetBase(double c){
		base = c;
	}
	public double GetBase(){
		return base; 
	}
	public void SetAlatura(double c){
		altura = c;
	}
	public double GetAltura(){
		return altura; 
	}
	
	//ABSTRACT -> para hacer un metodo puro 
	public abstract void CalcularArea(); //es puro 
	//si una clase no tiene abstract -> TODOS LOS METODOS DEBEN TENER CODIGO 
	
}