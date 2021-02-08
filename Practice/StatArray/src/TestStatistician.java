import java.util.*;

public class TestStatistician {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input;
        int test;
        StatArray s = new StatArray();
        input = sc.nextInt();
        test = sc.nextInt();
        if (input == 1)
            input1(s);
        else
            input2(s);
        switch (test) {
            case 1: test1(s);break;
            case 2: test2(s);break;
            case 3: test3(s);break;
            case 4: test4(s);break;
            case 5: test5(s);break;
            case 6: test6(s);break;
        }
    }

    private static void test1(StatArray s) {
        System.out.println(s);
        System.out.printf("isEmpty(s)? %s\n",s.isEmpty()?"yes":"no");
        System.out.printf("Clearing ...\n");
        s.clear();
        System.out.println(s);
        System.out.printf("isEmpty(s)? %s\n",s.isEmpty()?"yes":"no");
    }

    private static void test2(StatArray s) {
        System.out.println(s);
        System.out.printf("findMin(s) = %d\n",s.findMin());
        System.out.printf("findMax(s) = %d\n",s.findMax());
        System.out.printf("findRange(s) = %d\n",s.findRange());
        System.out.printf("findMedian(s) = %.2f\n",s.findMedian());
    }

    private static void test3(StatArray s) {
        System.out.println(s);
        System.out.printf("findSum(s) = %d\n",s.findSum());
        System.out.printf("findMean(s) = %.2f\n",s.findMean());
        System.out.printf("findStandardDeviation(s) = %.2f\n",s.findStandardDeviation());
    }

    private static void test4(StatArray s) {
        System.out.println(s);
        System.out.printf("frequency(s,23) = %d\n",s.frequency(23));
        System.out.printf("frequency(s,55) = %d\n",s.frequency(55));
        System.out.printf("frequency(s,33) = %d\n",s.frequency(33));
        System.out.printf("contains(s1,15)? %s\n",s.contains(15)?"yes":"no");
        System.out.printf("contains(s1,75)? %s\n",s.contains(75)?"yes":"no");
        System.out.printf("contains(s1,78)? %s\n",s.contains(78)?"yes":"no");
        System.out.printf("contains(s1,115)? %s\n",s.contains(115)?"yes":"no");
    }

    private static void test5(StatArray s) {
        System.out.println(s);
        System.out.printf("remove first 23\n");
        s.removeFirst(23);
        System.out.println(s);
        System.out.printf("remove first 75\n");
        s.removeFirst(75);
        System.out.println(s);
        System.out.printf("remove first 175\n");
        s.removeFirst(175);
        System.out.println(s);
    }

    private static void test6(StatArray s) {
        System.out.println(s);
        System.out.printf("remove all 23\n");
        s.removeAll(23);
        System.out.println(s);
        System.out.printf("remove all 55\n");
        s.removeAll(55);
        System.out.println(s);
        System.out.printf("remove all 75\n");
        s.removeAll(75);
        System.out.println(s);
        System.out.printf("remove all 175\n");
        s.removeAll(175);
        System.out.println(s);
    }

    private static void input1(StatArray s) {
        s.addLast(15);
        s.addLast(23);
        s.addLast(23);
        s.addLast(29);
        s.addLast(48);
        s.addLast(55);
        s.addLast(55);
        s.addLast(55);
        s.addLast(68);
        s.addLast(75);
    }

    private static void input2(StatArray s) {
        s.add(15);
        s.add(23);
        s.add(75);
        s.add(23);
        s.add(73);
        s.add(3);
        s.add(23);
        s.add(15);
        s.add(9);
        s.add(15);
        s.add(33);
    }
}
