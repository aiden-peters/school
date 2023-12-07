package a5;

/**
 * Root finding via the bisection method.
 *
 */
public class Bisection implements RootFinder1 {
	
	/**
	 * The tolerance used by this root finder.
	 * 
	 */
	public static final double TOL = 1.0E-6;
	
	/**
	 * Searches for a root on the interval {@code a} to {@code b} 
	 * for the specified {@code Function1} object {@code f}. Returns
	 * {@code Root.NONE} if no root is found.\n
	 * The bisection method requires that the values of {@code f.eval(a)} and {@code f.eval(b)}
	 * have opposite signs. An exception is thrown if this requirement is not satisfied.
	 *@override root in interface RootFinder1
	 *@param f a one-dimensional function
	 *@param a the minimum value of the interval to search
	 *@param b the maximum value of the interval to search
	 *
	 *@return a {@code Root} object containing the root if a root is found, or Root.NONE if no root is found
	 *
	 *@throws IllegalArgumentException if {@code a} >= {@code b}
	 *@throws IllegalArgumentException if the value of {@code f.eval(a)} has the same sign as {@code f.eval(b)}
	 *
	 */
	@Override
	public Root root(Function1 f, double a, double b) {
		
		
		if(a>=b) {
			throw new IllegalArgumentException();
		}
		if((f.eval(a)>0&&f.eval(b)>0)||(f.eval(a)<0&&f.eval(b)<0)) {
			throw new IllegalArgumentException();
		}
		double c = (a+b)/2;
		double ya = f.eval(a);
		double yb = f.eval(b);
		double yc = f.eval(c);
		while(Math.abs(yc)>TOL) {
			if((yc>0&&ya>0)||(yc<0&&ya<0)) {
				a = c;
			}
			else if((yc>0&&yb>0)||(yc<0&&yb<0)){
				b = c;
			}
			c = (a+b)/2;
			yc = f.eval(c);
		}
		Root r = new Root(c);
		return r;
	}

	/**
	 * Small example program that finds a root of the sine and cosine functions.
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {
		// find the root of sin(x) on the interval [3, 4]
		Function1 sin = new Sine();
		Bisection bisect = new Bisection();
		Root x0 = bisect.root(sin, 3.0, 4.0);
		if (x0 != Root.NONE) {
			System.out.println(x0.value()); // should be approx. pi
		}

		// find the root of cos(x) on the interval [1, 2]
		Function1 cos = new Cosine();
		x0 = bisect.root(cos, 1.0, 2.0);
		if (x0 != Root.NONE) {
			System.out.println(x0.value()); // should be approx. pi / 2
		}
	}

}
