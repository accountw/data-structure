
public class l {
	public static void  main(String[] args) {
		m m=new m();
		m qM=m;
		m.x=4;
		m.y=5;
		qM.y=6;
		System.out.println(m.toString());
		System.out.println(qM.toString());
		
	}
	
	
}
