package a5;

/**
 * The ideal projectile angle function.
 *
 */
public class ProjectileAngle implements Function1 {
	
	// YOUR CLASS SHOULD PROVIDE ALL OF THE FEATURES
	// DESCRIBED BY ITS DOCUMENTATION
	private double d;
	private double v;
	/**
	 * Magnitude of Earth standard gravity constant.
	 */
	public static final double G = 9.80665;
	
	/**
	 * Ideal projectile angle function for a target at the specified distance and a projectile having the specified initial speed.
	 * 
	 * @param distance horizontal distance to the target
	 * @param speed initial speed of the projectile
	 * 
	 * @throws IllegalArgumentException if distance < 0
	 * @throws IllegalArgumentException if speed < 0
	 * 
	 */
	public ProjectileAngle(double distance, double speed) {
		if(distance<0) {
			throw new IllegalArgumentException();
		}
		if(speed<0) {
			throw new IllegalArgumentException();
		}
		this.d = distance;
		this.v = speed;
	}
	
	/**
	 * Returns the horizontal distance to the target.
	 * @return the horizontal distance to the target
	 */
	public double getDistance() {
		return this.d;
	}
	
	/**
	 * Returns the initial speed of the projectile.
	 * @return the initial speed of the projectile
	 */
	public double getSpeed() {
		return this.v;
	}
	
	/**
	 * Sets the horizontal distance to the target returning the previously set distance.
	 * 
	 * @param distance the new horizontal distance to the target
	 * @return the previous horizontal distance to the target
	 */
	public double setDistance(double distance) {
		double oldDistance = this.d;
		this.d = distance;
		return oldDistance;
	}
	
	/**
	 * Sets the initial speed of the projectile returning the previously set speed.
	 * @param speed the new initial speed of the projectile
	 * @return the previous initial speed of the projectile
	 */
	public double setSpeed(double speed) {
		double oldSpeed = this.v;
		this.v = speed;
		return oldSpeed;
	}
	
	@Override
	/**
	 * Evaluate the function at the specified argument returning y = f(x) if the
	 * function exists at {@code x}. Returns {@code Double.NaN} if the function does not exist at x.
	 * 
	 * @param x the argument to the function
	 * 
	 * @return the function evaluated at x
	 */
	public double eval(double x) {
		Function1 sin = new Sine();
		Function1 cos = new Cosine();
		double val = -(0.5)*G*(Math.pow((d/(this.v*cos.eval(x))),2));
		val = val + this.d*(sin.eval(x)/cos.eval(x));
		return val;
	}
	
	/**
	 * Small example program that finds the two possible aiming angles
	 * for a projectile launched at 32.0 m/s at a target located 100 m
	 * horizontally from the launch point.
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {
		// target located 100 m horizontally from the launch point
		// launched at 50 m/s
		ProjectileAngle f = new ProjectileAngle(100.0, 50.0);
		// root finding using the bisection method
		Bisection n = new Bisection();
		
		// first angle is between 0 and 45 degrees 
		Root x0 = n.root(f, 0.0, Math.PI / 4.0);
		if (x0 != Root.NONE) {
			System.out.println(Math.toDegrees(x0.value()));
		}
		
		// second angle is between 45 and 90 degrees
		x0 = n.root(f, Math.PI / 4.0, Math.PI / 2.0);
		if (x0 != Root.NONE) {
			System.out.println(Math.toDegrees(x0.value()));
		}
	}

}
