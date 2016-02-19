interface Callable {
	public void call(int i);
} 

public class lambda {
	void print(Callable a) {
		a.call(2);
	}
	public static void main(String[] args) {
		lambda b = new lambda();
		b.print((int a) -> System.out.println(a));
	}
}