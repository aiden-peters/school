package a5;

/**
 * Root finding via Newton's method.
 *
 */
public class Newton implements RootFinder1 {

	// YOUR CLASS SHOULD PROVIDE ALL OF THE FEATURES
	// DESCRIBED BY ITS DOCUMENTATION
	private Function1 df;
	/**
	 * The tolerance used by this root finder
	 */
	public static final double TOL = 1.0E-6;
	
	/**
	 * Specifies the derivative function {@code df} for the function that this
	 * object finds the root of.
	 * @param df the derivative of the function to find the root of
	 */
	public Newton(Function1 df) {
		this.df = df;
	}
	/**
	 * Searches for a root on the interval {@code a} to {@code b} using Newton's method. 
	 * The initial estimate of the root is the average of {@code a} and {@code b}.
	 * If a root is found that is not in the interval {@code [a,b]} then this
	 * root finder returns Root.NONE.
	 * 
	 * @param f a one-dimensional function
	 * @param a the minimum value of the interval to search
	 * @param b the maximum value of the interval to search
	 * 
	 * @return a {@code Root} object containing the root if a root is found, or {@code Root.NONE} if no root is found
	 * 
	 * @throws IllegalArgumentException if a >= b
	 */
	@Override
	public Root root(Function1 f, double a, double b) {
		if(a>=b) {
			throw new IllegalArgumentException();
		}
		double xi = (a+b)/2;
		int i = 0;
		while(Math.abs(f.eval(xi))>TOL) {
			xi = xi - f.eval(xi)/df.eval(xi);
			i = i + 1;
		}
		Root r = new Root(xi);
		return r;
	}
	
	/**
	 * Small example program that finds a root of the sine and cosine function.
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {

		// find the root of sin(x) on the interval [3, 4]
		Function1 sin = new Sine();
		Function1 cos = new Cosine(); // derivative of sin(x)
		Newton n = new Newton(cos);
		Root x0 = n.root(sin, 3.0, 4.0);
		if (x0 != Root.NONE) {
			System.out.println(x0.value()); // should be approx. pi
		}

		// find the root of cos(x) on the interval [1, 2]
		Function1 negsin = new NegSine();
		Newton n2 = new Newton(negsin); // derivative of cos(x)
		x0 = n2.root(cos, 1.0, 2.0);
		if (x0 != Root.NONE) {
			System.out.println(x0.value()); // should be approx. pi / 2
		}
	}

}
