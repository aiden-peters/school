import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Random;

import ca.queensu.cs.cisc124.notes.basics.geometry.Point2;

public class SortPoints {
	
	public static class CompareByX implements Comparator<Point2> {
		
		@Override
		public int compare(Point2 p1, Point2 p2) {
			if(p1.x()>p2.x()) {return 1;};
			if(p1.x()<p2.x()) {return -1;}else {return 0;}
		}
		
	}
	
	public static void main(String[] args) {
		Random rng = new Random();
		// list of 8 random points
		List<Point2> t = new ArrayList<>();
		for (int i = 0; i < 8; i++) {
			t.add(new Point2(
					rng.nextDouble() * 20.0 - 10.0, 
					rng.nextDouble() * 20.0 - 10.0));
		}
		t.add(new Point2(-0.0, 0.0));
		t.add(new Point2(0.0, 0.0));
		// sort the list using CompareByX
		Comparator<Point2> c = new CompareByX();
		t.sort(c);
		for (Point2 p : t) {
			System.out.println(p);
		}
		
	}
}
