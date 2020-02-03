
public class A {

	private int val = 0;
	
	public static void affichePlus(int a ) {
		a++;
		System.out.println(a);
	}
	
	public static void affichePlus(A a ) {
		a.val++;
		System.out.println(a.val);
	}
	
	public static void main(String[] args) {
		
		A unObj = new A ();
		A unAutreObj = new A ();
		affichePlus (unObj.val);
		affichePlus (unObj.val);
		affichePlus (unObj);
		affichePlus (unObj);
		affichePlus (unAutreObj);
		affichePlus (unAutreObj);
		
		if (unObj == unAutreObj)
			System.out.println("Egales");
		else 
			System.out.println("Differentes");


	}

}
