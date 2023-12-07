package a2;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Test;

public class TestWordleUtils {

	@Test
	public void test01a_replace() {
		// method args
		String s = "A";
		int index = 0;
		char c = 'B';
		
		// expected answer
		String exp = "B";
		
		// run test
		assertEquals(exp, WordleUtils.replace(s, index, c));
	}

	@Test
	public void test01b_replace() {
		// method args
		String s = "GUMBO";
		int index = 0;
		char c = 'J';
		
		// expected answer
		String exp = "JUMBO";
		
		// run test
		assertEquals(exp, WordleUtils.replace(s, index, c));
	}
	
	@Test
	public void test01c_replace() {
		// method args
		String s = "JIMBO";
		int index = 1;
		char c = 'U';
		
		// expected answer
		String exp = "JUMBO";
		
		// run test
		assertEquals(exp, WordleUtils.replace(s, index, c));
	}
	@Test
	public void test02_isGreen() {
		// method args
		String guess = "WATERMELON";
		String ans = "HONEYDEW";
		
		try {
			WordleUtils.isGreen(guess, ans);
			fail("Illegal Argument");
		}
		catch(IllegalArgumentException x) {
			
		}
	}
	@Test
	public void test03_isYellow() {
		// method args
		String guess = "KAYAK";
		String ans = "WHACK";
		ArrayList<Boolean> exp = new ArrayList<>();
		exp.add(true);
		exp.add(true);
		exp.add(false);
		exp.add(false);
		exp.add(false);
		
	
		// run test
		assertEquals(exp, WordleUtils.isYellow(guess, ans));
	}
	@Test
	public void test04_getColors() {
		// method args
		String guess = "TRAPS";
		String ans = "TRIPS";
		ArrayList<WordleColor> exp = new ArrayList<>();
		exp.add(WordleColor.GREEN);
		exp.add(WordleColor.GREEN);
		exp.add(WordleColor.GRAY);
		exp.add(WordleColor.GREEN);
		exp.add(WordleColor.GREEN);
		
		// run test
		assertEquals(exp, WordleUtils.getColors(guess, ans));
	}
}
