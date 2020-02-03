class Test {
public static void main ( String [] args ){
		A a1 = new A ();
		A a2 = new B ();
		B b = new B ();
		System . out . println ( a1 . f ( a1 ));
		System . out . println ( a1 . f ( a2 ));
		System . out . println ( a2 . f ( a1 ));
		System . out . println ( a2 . f ( a2 ));
		System . out . println ( a2 . f ( b ));
		System . out . println ( b . f ( a2 ));
}
}