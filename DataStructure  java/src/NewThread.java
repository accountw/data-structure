
public class NewThread implements Runnable{
	Thread t;
	

	String lString;
	
	NewThread(String name){
		lString=name;
		t=new Thread(this,name);
		System.out.println("child thread"+t);
		t.start();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		
		
		try {
			for(int i=5;i>0;i--) {
				System.out.println(lString+i);
				Thread.sleep(500);
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			System.out.println("child thread Interrupted");
		}
		System.out.println("child thread  end");
	}

}
