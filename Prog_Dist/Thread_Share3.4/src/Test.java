
class Test {
public static void main ( String [] args ) {
		B b = new B ();
		System . out . println ( b . i );
		System . out . println ( b . f ());
		System . out . println ( b . g ());
		System . out . println ( b . h ());
		A a = b;
		System . out . println ( a . i );
		System . out . println ( a . f ());
		System . out . println ( a . g ());
		System . out . println ( a . h ());
}
}