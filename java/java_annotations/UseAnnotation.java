import java.lang.annotation.*;
import java.lang.reflect.*;

public class UseAnnotation {
	@MyAnnotation(testName="hello")
	public String aaa;

	public static void main(String[] args) throws NoSuchFieldException {
		Field f = UseAnnotation.class.getField("aaa");
		System.out.println(f.getAnnotation(MyAnnotation.class).testName());
	}
}