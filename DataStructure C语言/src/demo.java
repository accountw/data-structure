
public class demo {

	public static void  main(String[] args) {
		new NewThread("one");
		new NewThread("two");
		new NewThread("tree");
		Thread thread=Thread.currentThread();//获取主线程
		try {
			for(int i=5;i>0;i--) {
				System.out.println("main thread"+i);
				Thread.sleep(1000);
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			System.out.println("main thread Interrupted");
		}
		System.out.println("main thread  end");
	}
}
