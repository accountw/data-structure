package cn.edu.cdu.zb.linklist;


public class LinkList{
	
	
	private Node head,tail;//定义一个头结点和尾结点
	
	public LinkList() {
		head=tail=null;//初始化，头尾结点都为空
	}
	
	//判断链表是否为空
	public boolean isEmpty(){
		return head==null;
	}
	
	//从头结点添加数据
	public void addToHead(int e) {
		head=new Node(e,head);
		if(tail==null) {
			tail=head;
		}
	}
	
	//从尾结点添加数据
	public void addToTail(int e) {
		if(!isEmpty()) {
			tail.next=new Node(e);
			tail=tail.next;
		}
		else {
			head=tail=new Node(e);
		}
		
	}
	
	//从指定位置添加数据
	public void add(int n,int e) {
		Node tmp=head;
		Node newNode=new Node(e);
		if(n==1) {
			head=newNode;
			head.next=tmp;
		}
		else {
		for(int i=1;i<n-1;i++) {
			if(tmp.next==null) {
				System.out.println("添加位置不当");
				return;
			}else {
				tmp=tmp.next;
			}
		}
		newNode.next=tmp.next;
		tmp.next=newNode;
		
	}
	}
	
	//删除值为e的结点
	public void delete(int e) {
		if(!isEmpty()) {
			if(head==tail && e==head.data) {
				head=tail=null;
			}else if (e==head.data) {
				head=head.next;
			}else {
				Node pred, tmp;
				for(pred=head,tmp=head.next;tmp!=null &&tmp.data!=e;pred=pred.next,tmp=tmp.next); 
					if(tmp!=null) {
						pred.next=tmp.next;
						if(tmp==tail) {
							tail=pred;
						}
					}
				
			}
		}
	}
	
	//将第n个结点的值改为e
	public void  change(int n,int e) {
		Node tmp=head;
		for(int i=1;i<n;i++) {
			tmp=tmp.next;
		}
		tmp.data=e;
	}
	
	
	
	//打印所有数据
	public void printAll() {
		for(Node tmp=head;tmp!=null;tmp=tmp.next) {
			System.out.println(tmp.data);
		}
	}
}
